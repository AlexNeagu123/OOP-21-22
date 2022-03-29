//
// Created by alexandru on 29.03.2022.
//

#include "Circuit.h"
#include "Weather.h"
#include <iostream>

void Circuit::SetLength(int _length) {
    length = _length;
}
void Circuit::SetWeather(Weather _weather) {
    condition = _weather;
}

void Circuit::AddCar(Car *newCar) {
    newCar -> setName();
    newCar -> setSunnySpeed();
    newCar -> setSnowSpeed();
    newCar -> setRainSpeed();
    newCar -> setFuelConsumption();
    newCar -> setFuelCapacity();
    cars[carNumber++] = newCar;
}
void Circuit::Race() {
    for(int i = 0; i < carNumber; ++i) {
        double speed;
        switch(condition) {
            case 0:
                speed = cars[i] -> rainSpeed;
                break;
            case 1:
                speed = cars[i] -> sunnySpeed;
                break;
            case 2:
                speed = cars[i] -> snowSpeed;
                break;
        }
        times[i] = length / speed;
        consumed[i] = cars[i] -> fuelConsumption * length / 100.0;
    }

    for(int i = 0; i < carNumber; ++i) {
        for(int j = 0; j < carNumber - 1; ++j) {
            if(times[j] > times[j + 1]) {
                std::swap(times[j], times[j + 1]);
                std::swap(cars[j], cars[j + 1]);
                std::swap(consumed[j], consumed[j + 1]);
            }
        }
    }
}

// DEBUGGING PURPOSE
void Circuit::showCars() {
    for(int i = 0; i < carNumber; ++i) {
        std::cout << cars[i] -> name << ' ' << cars[i] -> sunnySpeed << ' ' << cars[i]->fuelConsumption << '\n';
    }
}

void Circuit::ShowFinalRanks() {
    printf("Final Ranks:\n");
    int finished = 0;
    for(int i = 0; i < carNumber; ++i) {
        if(consumed[i] <= cars[i] -> fuelCapacity) {
            printf("Place #%d: Car: %s, Time: %f hours (%f seconds)\n", finished + 1, cars[i] -> name, times[i], times[i] * 3600.0);
            ++finished;
        }
    }
}

void Circuit::ShowWhoDidNotFinis() {
    printf("Participants who did not finish the race:\n");
    int notFinished = 0;
    for(int i = 0; i < carNumber; ++i) {
        if(consumed[i] > cars[i] -> fuelCapacity) {
            printf("Car %s did not finish the race. Max Fuel Capacity: %f. Fuel Capacity Needed: %f\n", cars[i] -> name, cars[i] -> fuelCapacity, consumed[i]);
        }
    }
}

