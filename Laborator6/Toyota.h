//
// Created by alexandru on 29.03.2022.
//

#ifndef LABORATOR6_TOYOTA_H
#define LABORATOR6_TOYOTA_H
#include "Car.h"
class Toyota: public Car {
    void setFuelCapacity() override;
    void setFuelConsumption() override;
    void setRainSpeed() override;
    void setSnowSpeed() override;
    void setSunnySpeed() override;
    void setName() override;
};
#endif //LABORATOR6_TOYOTA_H
