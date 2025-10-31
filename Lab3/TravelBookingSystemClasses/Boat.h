#pragma once
#include "TransportOption.h"

class Boat : public TransportOption {
private:
    int passengerCapacity;
public:
    Boat(double price, double duration);
    int getPassengerCapacity(); 
    bool hasLifeJackets();      
};