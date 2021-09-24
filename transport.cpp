#include "transport.h"


//------------------------------------------------------------------------------
// ввод транспорта из потока ввода
// если данные не правлитьные - возвращает nullptr, он считается невалидным оБьектом
transport* In(std::ifstream &ifst) {
    transport *t = new transport;
    std::string k;
    ifst >> k;

    if (k == "plain") {
        t->k = transport::PLAIN;
        In(t->p, ifst);
    } else if (k == "train") {
        t->k = transport::TRAIN;
        In(t->t, ifst);
    } else if (k == "ship") {
        t->k = transport::SHIP;
        In(t->s, ifst);
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
void Out(transport &t, std::ofstream &ofst) {
    if (t.k == transport::PLAIN) {
        Out(t.p, ofst);
    } else if (t.k == transport::TRAIN) {
        Out(t.t, ofst);
    } else  {
        Out(t.s, ofst);
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
