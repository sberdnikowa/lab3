#ifndef STRUCTURES_H
#define STRUCTURES_H

struct coordinates { 
    int degree;
    int minute;
    int second;
};

struct position {
    struct coordinates lat;
    struct coordinates longitude;
};

struct fig { 
    struct position apex1;
    struct position apex2;
    struct position apex3;
};

void input_ship (int N, struct position *ship);
struct fig input_triangle (void);
struct position input_port(void);

void matrix_of_slopes(int N, struct position *ship, struct fig triangle,
                      struct position port, float (*slopes)[4]);
void danger_indification(int N, float (*slopers)[4], int *danger);

#endif
