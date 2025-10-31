#pragma once
#include "TransportOption.h"

class Train : public TransportOption {
private:
    int carriageCount;
public:
    Train(double price, double duration);
    int getCarriageCount();           
    bool isElectric();                
};