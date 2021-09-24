#ifndef __train__
#define __train__

#include <fstream>

#include "rnd.h"

struct train {
    int speed, distance;
    int cars_counter;
};

void In(train &t, std::ifstream &ifst);

void InRnd(train &t);

void Out(train &t, std::ofstream &ofst);

double OptimalTime(train &t);

#endif //__train__