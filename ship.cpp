#include "ship.h"



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

double OptimalTime(ship &s) {
    return static_cast<double>(s.distance) /  static_cast<double>(s.speed);
}
