#pragma once
#include "TransportOption.h"

class LuxuryBus : public TransportOption {
private:
    bool hasEntertainmentSystem;
public:
    LuxuryBus(double price, double duration);
    bool getHasEntertainmentSystem(); 
    int getLuxuryLevel();             
};