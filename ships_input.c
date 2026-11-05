#include <stdio.h>
#include <stdlib.h>

#include "structures.h"


struct position input_position(void) {
    int d, m, s, d1, m1, s1;
    int result = scanf("%d%d%d%d%d%d", &d, &m, &s, &d1, &m1, &s1);
    if (result != 6) {
        if (feof(stdin)) {
            fputs("Недостаточно входных данных.\n", stderr);
            exit(EXIT_FAILURE);
        }
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return (struct position){{-1, 0, 0}, {-1, 0, 0}};
    }
    struct position x;
    x.lat.degree = d;
    x.lat.minute = m;
    x.lat.second = s;
    x.longitude.degree = d1;
    x.longitude.minute = m1;
    x.longitude.second = s1;
    return x; 
}

int check(struct position pos) {
    return !(pos.lat.degree < 0 || pos.lat.degree > 90 || pos.lat.minute < 0 || pos.lat.minute > 60 || pos.lat.second < 0 || pos.lat.second > 60 ||
            pos.longitude.degree < 0 || pos.longitude.degree > 180 || pos.longitude.minute < 0 || pos.longitude.minute > 60 || pos.longitude.second < 0 || pos.longitude.second > 60);
}

void input_ship(int N, struct position *ship) {
    int isInputCorrect = 0;

    while (!isInputCorrect) {
        isInputCorrect = 1;
        for (int i = 0; i < N; i++) {
            ship[i] = input_position();
            if (!check(ship[i])) {
                isInputCorrect = 0;
            }
        }
        if (!isInputCorrect) fputs("Повторите координаты всех судов.\n", stderr);
    }
}

struct fig input_triangle(void) {
    int isInputCorrect = 0;

    struct position x, y, z;
    while (!isInputCorrect) {
        isInputCorrect = 1;
        
        x = input_position();
        y = input_position();
        z = input_position();
        if (!check(x) || !check(y) || !check(z)) {
            isInputCorrect = 0;
            fputs("Неверные координаты. Повторите ввод.\n", stderr);
        }
    }
    struct fig res = {x, y, z};
    return res;
}

struct position input_port(void) {
    int isInputCorrect = 0;

    struct position x;
    while (!isInputCorrect) {
        isInputCorrect = 1;
        x = input_position();
        if (!check(x)) {
            isInputCorrect = 0;
            fputs("Неверные координаты. Повторите ввод.\n", stderr);
        }
    }
    return x;
}
