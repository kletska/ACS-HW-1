#ifndef __ship__
#define __ship__

#include <fstream>
#include <string>

#include "rnd.h"

struct ship {
    int speed, distance;
    int displace;
    enum vessel_type {LINER, TUG, TANKER, ERROR};
    vessel_type ship_kind;
};

void In(ship &s, std::ifstream &ifst);

void InRnd(ship &s);

void Out(ship &s, std::ofstream &ofst);

double OptimalTime(ship &s);

#endif //__ship__