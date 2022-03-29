//
// Created by alexandru on 29.03.2022.
//

#ifndef LABORATOR6_FORD_H
#define LABORATOR6_FORD_H
#include "Car.h"
class Ford: public Car {
    void setFuelCapacity() override;
    void setFuelConsumption() override;
    void setRainSpeed() override;
    void setSnowSpeed() override;
    void setSunnySpeed() override;
    void setName() override;
};
#endif //LABORATOR6_FORD_H
