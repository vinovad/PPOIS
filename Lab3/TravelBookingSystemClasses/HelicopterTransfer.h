#pragma once
#include "TransportOption.h"

class HelicopterTransfer : public TransportOption {
private:
    int maxPassengers;
public:
    HelicopterTransfer(double price, double duration);
    int getMaxPassengers();    
    bool isScenicFlight();     
};