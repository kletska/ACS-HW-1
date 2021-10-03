#include "transport.h"


//------------------------------------------------------------------------------
// ввод транспорта из потока ввода
// если данные не правлитьные - возвращает nullptr, он считается невалидным оБьектом
transport* In(FILE* file) {
    transport *t = new transport;
    char kind[9];
    fscanf(file, "%s", kind);
    if (strcmp(kind, "plain") == 0) {
        t->k = transport::PLAIN;
        In(t->p, file);
    } else if (strcmp(kind, "train") == 0) {
        t->k = transport::TRAIN;
        In(t->t, file);
    } else if (strcmp(kind, "ship") == 0) {
        t->k = transport::SHIP;
        In(t->s, file);
        // не забыл обработать невалидный обьект
        if (t->s.ship_kind == ship::ERROR) {
            delete t;
            return nullptr;
        }
    } else {
        delete t;
        return nullptr;
    }
    return t;
}

//------------------------------------------------------------------------------
// инициализация случайного транспорта
transport *InRnd() {
    transport *t = new transport;
    auto k = Random();

    if (k % 3 == 0) {
        t->k = transport::PLAIN;
        InRnd(t->p);
    } else if (k % 3 == 1) {
        t->k = transport::TRAIN;
        InRnd(t->t);
    } else {
        t->k = transport::SHIP;
        InRnd(t->s);
    }

    return t;
}


//------------------------------------------------------------------------------
// вывод транспорта в поток вывода
void Out(transport &t, FILE* file) {
    if (t.k == transport::PLAIN) {
        Out(t.p, file);
    } else if (t.k == transport::TRAIN) {
        Out(t.t, file);
    } else  {
        Out(t.s, file);
    }
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для транспорта
double OptimalTime(transport &t) {
    if (t.k == transport::PLAIN) {
        return OptimalTime(t.p);
    } else if (t.k == transport::TRAIN) {
        return OptimalTime(t.t);
    } else {
        return OptimalTime(t.s);
    }
}
