#ifndef __transport__
#define __transport__

#include "plain.h"
#include "train.h"
#include "ship.h"
#include "rnd.h"

struct transport {
    enum key {PLAIN, TRAIN, SHIP};
    key k;
    union {
        plain p;
        train t;
        ship s;
    };
};


transport *In(std::ifstream &ifdt);

transport *InRnd();

void Out(transport& t, std::ofstream &ofst);

double OptimalTime(transport &t);

#endif
