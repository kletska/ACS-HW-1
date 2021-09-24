#include "plain.h"

void In(plain &p, std::ifstream &ifst) {
    ifst >> p.speed >> p.distance >> p.fly_distance >> p.lifting_capacity;
}

void InRnd(plain &p) {
    p.speed = Random();
    p.distance = Random();
    p.fly_distance = Random();
    p.lifting_capacity = Random();
}

void Out(plain &p, std::ofstream &ofst) {
    ofst << "It is plain: "
         << "speed = " << p.speed << ", " 
         << "distance = " << p.distance << ", "
         << "fly distance = " << p.fly_distance << ", "
         << "lifting capacity = " << p.lifting_capacity << ". "
         << "Optimal time = " << OptimalTime(p) << ".\n";
}

double OptimalTime(plain &p) {
    return static_cast<double>(p.fly_distance) /  static_cast<double>(p.speed);
}
