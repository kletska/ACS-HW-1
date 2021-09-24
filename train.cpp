#include "train.h"


void In(train &t, std::ifstream &ifst) {
    ifst >> t.speed >> t.distance >> t.cars_counter;
}

void InRnd(train &t) {
    t.speed = Random();
    t.distance = Random();
    t.cars_counter = Random();
}

void Out(train &t, std::ofstream &ofst) {
    ofst << "It is train: "
         << "speed = " << t.speed << ", " 
         << "distance = " << t.distance << ", "
         << "cars_counter = " << t.cars_counter << ". ";

    ofst << "Optimal time = " << OptimalTime(t) << ".\n";
}

double OptimalTime(train &t) {
    return static_cast<double>(t.distance) /  static_cast<double>(t.speed);
}
