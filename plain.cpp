#include "plain.h"


//------------------------------------------------------------------------------
// ввод самолёта из потока ввода
void In(plain &p, FILE* file) {
    fscanf(file, "%d %d %d %d", &p.speed, &p.distance, &p.fly_distance, &p.lifting_capacity);
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
void Out(plain &p, FILE* file) {
    fprintf(
        file,
        "It is plain: speed = %d, distance = %d, fly distance = %d, lifting capacity = %d. Optimal time = %lf.\n",
        p.speed,
        p.distance,
        p.fly_distance,
        p.lifting_capacity,
        OptimalTime(p)
    );
}

//------------------------------------------------------------------------------
// вычисление оптимального времени, для самолёта
// я не уверен, идеальное время дожно считаться по длинне полёта или расстоянию между пунктами
// я считаю по дистанции полета т.к. в противном весь транспорт будет иметь идентичную функцию, а это скучно
double OptimalTime(plain &p) {
    return static_cast<double>(p.fly_distance) /  static_cast<double>(p.speed);
}
