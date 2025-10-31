#pragma once
#include "TransportOption.h"

class MiniBus : public TransportOption {
private:
    int seatCount;
public:
    MiniBus(double price, double duration);
    int getSeatCount();               
    bool isEcoFriendly();             
};