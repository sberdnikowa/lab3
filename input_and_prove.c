#include "structures.h"

void danger_indification(int N, float (*slopers)[4], int *danger){
    for (int i = 0; i < N; i++){
        float min_slope = slopers[i][0];
        if (slopers[i][1] < min_slope) min_slope = slopers[i][1];
        if (slopers[i][2] < min_slope) min_slope = slopers[i][2];
        float max_slope = slopers[i][0];
        if (slopers[i][1] > max_slope) max_slope = slopers[i][1];
        if (slopers[i][2] > max_slope) max_slope = slopers[i][2];

        if (slopers[i][3] >= min_slope && slopers[i][3] <= max_slope) danger[i] = 1;
        else danger[i] = 0;
    }
}
