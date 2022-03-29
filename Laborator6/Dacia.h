//
// Created by alexandru on 29.03.2022.
//

#ifndef LABORATOR6_DACIA_H
#define LABORATOR6_DACIA_H
#include "Car.h"
class Dacia: public Car {
    void setFuelCapacity() override;
    void setFuelConsumption() override;
    void setRainSpeed() override;
    void setSnowSpeed() override;
    void setSunnySpeed() override;
    void setName() override;
};
#endif //LABORATOR6_DACIA_H
