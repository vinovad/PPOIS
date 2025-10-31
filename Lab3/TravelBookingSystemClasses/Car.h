#pragma once
#include "TransportOption.h"
#include "CarAgent.h"

class Car : public TransportOption {
public:
    CarAgent* agent;
    Car(double price, double duration, CarAgent* agent);
    std::string getAgentName();  
    bool isAvailableForRent();  
};