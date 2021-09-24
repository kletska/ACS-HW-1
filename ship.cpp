#include "ship.h"
#include <fstream>

//------------------------------------------------------------------------------
// ввод корабля из потока ввода
// на самом деле, лучше как то сообщать, что мы возвращаем не валидный обьект (ship::ERROR),
// но в проекте такого масштаба достаочно не забыть обработать это в местах, где мы вызваем эту 
void In(ship &s, std::ifstream &ifst) {
    ifst >> s.speed >> s.distance >> s.displace;
    std::string kind;

    ifst >> kind;
    if (kind == "liner") {
        s.ship_kind = ship::LINER;
    } else if (kind == "tug") {
        s.ship_kind = ship::TUG;
    } else if (kind == "tanker") {
        s.ship_kind = ship::TANKER;
    } else {
        s.ship_kind = ship::ERROR;
    }
}


//------------------------------------------------------------------------------
// инициализация случайного корабля
void InRnd(ship &s) {
    s.speed = Random();
    s.distance = Random();
    s.displace = Random();
    
    int kind = Random();
    if (kind % 3 == 0) {
        s.ship_kind = ship::LINER;
    } else if (kind % 3 == 1) {
        s.ship_kind = ship::TUG;
    } else {
        s.ship_kind = ship::TANKER;
    }
}


//------------------------------------------------------------------------------
// вывод корабля в поток вывода
void Out(ship &s, std::ofstream &ofst) {
    ofst << "It is ship: "
         << "speed = " << s.speed << ", " 
         << "distance = " << s.distance << ", "
         << "displace = " << s.displace << ", ";

    
    if (s.ship_kind == ship::LINER) {
        ofst << "ship kind = liner" << ". ";
    } else if (s.ship_kind == ship::TUG) {
        ofst << "ship kind = tug" << ". ";
    } else if (s.ship_kind == ship::TANKER) {
        ofst << "ship kind = tanker" << ". ";
    }

    ofst << "Optimal time = " << OptimalTime(s) << ".\n";
}


//------------------------------------------------------------------------------
// вычисление оптимального времени, для корабля
double OptimalTime(ship &s) {
    return static_cast<double>(s.distance) /  static_cast<double>(s.speed);
}
