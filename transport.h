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


//------------------------------------------------------------------------------
// ввод транспорта из потока ввода
transport *In(FILE* file);


//------------------------------------------------------------------------------
// инициализация случайного транспорта
transport *InRnd();

//------------------------------------------------------------------------------
// вывод транспорта в поток вывода
void Out(transport& t, FILE* file);


//------------------------------------------------------------------------------
// вычисление оптимального времени, для транспорта
double OptimalTime(transport &t);

#endif
