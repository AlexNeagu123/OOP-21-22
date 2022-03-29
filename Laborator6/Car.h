//
// Created by alexandru on 28.03.2022.
//

#ifndef LABORATOR6_CAR_H
#define LABORATOR6_CAR_H
class Car {
    // fuel capacity - liters
    // fuel consumption - how many liters consumed in 100 km?
    // speeds - km/h
    friend class Circuit;
protected:
    const char *name;
    double fuelCapacity, fuelConsumption, rainSpeed, sunnySpeed, snowSpeed;
    virtual void setSunnySpeed() = 0;
    virtual void setFuelCapacity() = 0;
    virtual void setFuelConsumption() = 0;
    virtual void setRainSpeed() = 0;
    virtual void setSnowSpeed() = 0;
    virtual void setName() = 0;
};
#endif //LABORATOR6_CAR_H
