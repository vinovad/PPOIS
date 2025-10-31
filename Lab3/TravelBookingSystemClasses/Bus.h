#pragma once
#include "TransportOption.h"

class Bus : public TransportOption {
private:
    int seatCount;
public:
    Bus(double price, double duration);
    int getSeatCount();        
    bool hasAirConditioning();   
};