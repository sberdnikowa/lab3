#include "structures.h"

void matrix_of_slopes( int N, struct position *ship, struct fig triangle, struct position port, float(*slopes)[4]) {
    float l; 
    int latip, longip;
    int latit, longit;
    for (int i = 0; i < N; i++) {
        latip = port.lat.degree * 3600 + port.lat.minute * 60 + port.lat.second  - ship[i].lat.degree * 3600 - ship[i].lat.minute * 60 - ship[i].lat.second; 
        longip = port.longitude.degree * 3600 + port.longitude.minute * 60 + port.longitude.second - ship[i].longitude.degree * 3600 - ship[i].longitude.minute * 60 - ship[i].longitude.second;
        l = 1. * latip / longip;
        slopes[i][3] = l;
        latit = triangle.apex1.lat.degree * 3600 + triangle.apex1.lat.minute * 60 + triangle.apex1.lat.second - ship[i].lat.degree * 3600 - ship[i].lat.minute * 60 - ship[i].lat.second;
        longit = triangle.apex1.longitude.degree * 3600 + triangle.apex1.longitude.minute * 60 + triangle.apex1.longitude.second - ship[i].longitude.degree * 3600 - ship[i].longitude.minute * 60 - ship[i].longitude.second;
        l = 1. * latit / longit;
        slopes[i][0] = l;
        latit = triangle.apex2.lat.degree * 3600 + triangle.apex2.lat.minute * 60 + triangle.apex2.lat.second - ship[i].lat.degree * 3600 - ship[i].lat.minute * 60 - ship[i].lat.second;
        longit = triangle.apex2.longitude.degree * 3600 + triangle.apex2.longitude.minute * 60 + triangle.apex2.longitude.second - ship[i].longitude.degree * 3600 - ship[i].longitude.minute * 60 - ship[i].longitude.second;
        l = 1. * latit / longit;
        slopes[i][1] = l;
        latit = triangle.apex3.lat.degree * 3600 + triangle.apex3.lat.minute * 60 + triangle.apex3.lat.second - ship[i].lat.degree * 3600 - ship[i].lat.minute * 60 - ship[i].lat.second;
        longit = triangle.apex3.longitude.degree * 3600 + triangle.apex3.longitude.minute * 60 + triangle.apex3.longitude.second - ship[i].longitude.degree * 3600 - ship[i].longitude.minute * 60 - ship[i].longitude.second;
        l = 1. * latit / longit;
        slopes[i][2] = l;
    }
}
