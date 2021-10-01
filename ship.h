#ifndef __ship__
#define __ship__

#include <fstream>
#include <cstring>
#include <cstdio>

#include "rnd.h"

// корабль со значением ERROR в vessel_type считается не валидным,
// поэтому этот вариант нигде не обрабатывается
struct ship {
    int speed, distance;
    int displace;
    enum vessel_type {LINER, TUG, TANKER, ERROR};
    vessel_type ship_kind;
};


//------------------------------------------------------------------------------
// ввод корабля из потока ввода
void In(ship &s, FILE* file);

//------------------------------------------------------------------------------
// инициализация случайного корабля
void InRnd(ship &s);

//------------------------------------------------------------------------------
// вывод корабля в поток вывода
void Out(ship &s, FILE* file);

//------------------------------------------------------------------------------
// вычисление оптимального времени, для корабля
double OptimalTime(ship &s);

#endif //__ship__