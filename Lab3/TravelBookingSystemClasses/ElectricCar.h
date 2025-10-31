#pragma once
#include "TransportOption.h"
#include "CarAgent.h"

class ElectricCar : public TransportOption {
public:
    CarAgent* agent;
    ElectricCar(double price, double duration, CarAgent* agent);
    std::string getAgentName();    
    double getBatteryCapacity();   
};