#include "plain.h"


//------------------------------------------------------------------------------
// ввод самолёта из потока ввода
void In(plain &p, std::ifstream &ifst) {
    ifst >> p.speed >> p.distance >> p.fly_distance >> p.lifting_capacity;
}


//------------------------------------------------------------------------------
// инициализация случайного самолёта
void InRnd(plain &p) {
    p.speed = Random();
    p.distance = Random();
    p.fly_distance = Random();
    p.lifting_capacity = Random();
}


//------------------------------------------------------------------------------
// вывод самолета в поток вывода
void Out(plain &p, std::ofstream &ofst) {
    ofst << "It is plain: "
         << "speed = " << p.speed << ", " 
         << "distance = " << p.distance << ", "
         << "fly distance = " << p.fly_distance << ", "
         << "lifting capacity = " << p.lifting_capacity << ". "
         << "Optimal time = " << OptimalTime(p) << ".\n";
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для самолёта
// я не уверен, идеальное время дожно считаться по длинне полёта или расстоянию между пунктами
// я считаю по дистанции полета т.к. в противном весь транспорт будет иметь идентичную функцию, а это скучно
double OptimalTime(plain &p) {
    return static_cast<double>(p.fly_distance) /  static_cast<double>(p.speed);
}
