#pragma once
#include "TransportOption.h"

class HighSpeedTrain : public TransportOption {
private:
    double maxSpeed;
public:
    HighSpeedTrain(double price, double duration);
    double getMaxSpeed();      
    bool hasFirstClass();      
};