#include <stdio.h>
#include "structures.h"
#include "danger_signal.h"

int main(void)
{
    int N;
    struct position ship[50];
    float slopes[50][4] = {0};
    int danger[50] = {0};

    puts("Введите количество судов (1–50):");
    if (scanf("%d", &N) != 1 || N < 1 || N > 50) {
        fputs("Некорректное количество судов.\n", stderr);
        return 1;
    }

    puts("Введите координаты судов: широта (градусы минуты секунды), долгота (градусы минуты секунды).");
    input_ship(N, ship);
    puts("Введите координаты трёх вершин треугольника в том же формате:");
    struct fig triangle = input_triangle();
    puts("Введите координаты порта:");
    struct position port = input_port();

    matrix_of_slopes(N, ship, triangle, port, slopes);
    danger_indification(N, slopes, danger);

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    puts("Для следующего судна нажмите Enter.");
    danger_signal(N, danger);
    return 0;
}
