#pragma once
#include "TransportOption.h"

class ExpressBus : public TransportOption {
private:
    bool hasWiFi;
public:
    ExpressBus(double price, double duration);
    bool getHasWiFi();         
    int getTravelTime();       
};