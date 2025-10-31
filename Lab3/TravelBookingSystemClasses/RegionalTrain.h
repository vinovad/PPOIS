#pragma once
#include "TransportOption.h"

class RegionalTrain : public TransportOption {
private:
    int stopCount;
public:
    RegionalTrain(double price, double duration);
    int getStopCount();               
    bool isExpress();                 
};