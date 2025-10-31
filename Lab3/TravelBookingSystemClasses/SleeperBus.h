#pragma once
#include "TransportOption.h"

class SleeperBus : public TransportOption {
private:
    int bedCount;
public:
    SleeperBus(double price, double duration);
    int getBedCount();                
    bool hasToilet();                 
};