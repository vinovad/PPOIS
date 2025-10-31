#pragma once
#include "TransportOption.h"

class LuxuryTrain : public TransportOption {
private:
    bool hasPrivateCompartments;
public:
    LuxuryTrain(double price, double duration);
    bool getHasPrivateCompartments(); 
    bool hasDiningCar();              
};