from pathlib import Path
import re
import subprocess

root = Path(__file__).resolve().parent.parent
expected = {
    "valencia": ["YES", "NO", "YES", "NO", "NO"],
    "genoa": ["YES", "NO", "YES", "NO", "YES"],
    "barcelona": ["YES", "NO", "YES", "NO", "NO"],
    "sevastopol": ["NO", "YES", "YES", "NO", "NO"],
    "sochi": ["YES", "NO", "NO", "YES", "NO", "NO"],
}

def run(data):
    return subprocess.run([str(root / "build/lab3")], input=data,
                          text=True, capture_output=True, timeout=3)

for name, answers in expected.items():
    result = run((root / "tests" / (name + ".txt")).read_text())
    assert result.returncode == 0, result.stderr
    rows = re.findall(r"^(\d+)\s+(YES|NO)$", result.stdout.replace("\a", ""), re.M)
    assert rows == [(str(i + 1), a) for i, a in enumerate(answers)], (name, rows)
    assert result.stdout.count("\a") == answers.count("YES")
    print(name + ": OK")

for data in ["", "0\n", "51\n", "abc\n", "1\n"]:
    assert run(data).returncode != 0

data = (root / "tests/valencia.txt").read_text()
retry = data.replace("39 28 31 0 23 22", "91 0 0 0 0 0\n39 28 31 0 23 22")
assert run(retry).stdout == run(data).stdout
print("Invalid input, EOF, repeated port input: OK")
