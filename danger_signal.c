#include <stdio.h>

#include "danger_signal.h"

void danger_signal(int N, int *danger)
{
    if (N <= 0 || danger == NULL) {
        return;
    }

    printf("Индекс судна\tОпасность\n");

    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            int ch;
            while ((ch = getchar()) != '\n') {
                if (ch == EOF) {
                    return;
                }
            }
        }

        printf("%d\t\t%s\n", i + 1, danger[i] == 1 ? "YES" : "NO");
        if (danger[i] == 1) {
            putchar('\a');
        }
        fflush(stdout);
    }
}
