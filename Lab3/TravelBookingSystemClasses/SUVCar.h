#pragma once
#include "TransportOption.h"
#include "CarAgent.h"

class SUVCar : public TransportOption {
public:
    CarAgent* agent;
    SUVCar(double price, double duration, CarAgent* agent);
    std::string getAgentName();       
    bool isFourWheelDrive();          
};