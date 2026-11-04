#ifndef DANGER_SIGNAL_H
#define DANGER_SIGNAL_H

/* danger содержит N значений: 1 — опасность, 0 — безопасный курс.
 * Перед вызовом stdin должен находиться в начале новой строки. */
void danger_signal(int N, int *danger);

#endif
