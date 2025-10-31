#pragma once
#include "TransportOption.h"

class Ship : public TransportOption {
private:
    int deckCount;
public:
    Ship(double price, double duration);
    int getDeckCount();               
    bool hasCabinRooms();             
};