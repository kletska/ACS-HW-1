#ifndef __plain__
#define __plain__

#include <fstream>

#include "rnd.h"

struct plain {
    int speed, distance;
    int fly_distance, lifting_capacity;
};

void In(plain &p, std::ifstream &ifst);

void InRnd(plain &p);

void Out(plain &p, std::ofstream &ofst);

double OptimalTime(plain &p);

#endif //__plain__
