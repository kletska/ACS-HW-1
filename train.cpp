#include "train.h"


//------------------------------------------------------------------------------
// ввод поезда из потока ввода
void In(train &t, FILE* file) {
    fscanf(file, "%d %d %d %d", &t.speed, &t.distance, &t.cars_counter);
}

//------------------------------------------------------------------------------
// инициализация случайного поезда
void InRnd(train &t) {
    t.speed = Random();
    t.distance = Random();
    t.cars_counter = Random();
}

//------------------------------------------------------------------------------
// вывод поезда в поток вывода
void Out(train &t, FILE* file) {
    fprintf(
        file,
        "It is train: speed = %d, distance = %d, cars counter = %d. ",
        t.speed,
        t.distance,
        t.cars_counter
    );

    fprintf(file, "Optimal time = %lf.\n", OptimalTime(t));
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для поезда
double OptimalTime(train &t) {
    return static_cast<double>(t.distance) /  static_cast<double>(t.speed);
}
