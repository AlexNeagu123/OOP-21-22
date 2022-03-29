//
// Created by alexandru on 29.03.2022.
//

#ifndef LABORATOR6_MERCEDES_H
#define LABORATOR6_MERCEDES_H
#include "Car.h"
class Mercedes: public Car {
    void setFuelCapacity() override;
    void setFuelConsumption() override;
    void setRainSpeed() override;
    void setSnowSpeed() override;
    void setSunnySpeed() override;
    void setName() override;
};
#endif //LABORATOR6_MERCEDES_H
