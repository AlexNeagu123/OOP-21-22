//
// Created by alexandru on 29.03.2022.
//

#ifndef LABORATOR6_CIRCUIT_H
#define LABORATOR6_CIRCUIT_H
#include "Car.h"
#include "Weather.h"
class Circuit {
    Car *cars[10];
    int length, carNumber;
    double times[10], consumed[10];
    Weather condition;
public :
    void SetLength(int);
    void SetWeather(Weather);
    void AddCar(Car *);
    void showCars();
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinis();
    Circuit() : cars{}, length(0), carNumber(0), times{}, consumed{}, condition(Weather::Sunny) {};
};
#endif //LABORATOR6_CIRCUIT_H
