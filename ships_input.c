#include <stdio.h>

#include "structures.h"

float slopes[50][4]={};
int danger[50]={};

struct position input_position() {
    int d, m, s, d1, m1, s1;
    scanf("%d%d%d%d%d%d", &d, &m, &s, &d1, &m1, &s1);
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
            int gradus1, mins1, secs1, gradus2, mins2, secs2;

            scanf("%d%d%d%d%d%d", &gradus1, &mins1, &secs1, &gradus2, &mins2, &secs2);

            if (gradus1 < 0 || gradus1 > 90 || mins1 < 0 || mins1 > 60 || secs1 < 0 || secs1 > 60 || gradus2 < 0 || gradus2 > 180 || mins2 < 0 || mins2 > 60 || secs2 < 0 || secs2 > 60) {
                isInputCorrect = 0;
                break;
            }

            ship[i].lat.degree = gradus1;
            ship[i].lat.minute = mins1;
            ship[i].lat.second = secs1;

            ship[i].longitude.degree = gradus2;
            ship[i].longitude.minute = mins2;
            ship[i].longitude.second = secs2;
        }
    }    
}

struct fig input_triangle() {
    int isInputCorrect = 0;

    struct position x, y, z;
    while (!isInputCorrect) {
        isInputCorrect = 1;
        
        x = input_position();
        y = input_position();
        z = input_position();
        if (check(x) || check(y) || check(z)) {
            isInputCorrect = 0;
        }
    }
    struct fig res = {x, y, z};
    return res;
}

struct position input_port() {
    int isInputCorrect = 0;

    struct position x;
    while (!isInputCorrect) {
        isInputCorrect = 1;
        x = input_position();
        if (check(x)) {
            isInputCorrect = 0;
        }
    }
    return x;
}
