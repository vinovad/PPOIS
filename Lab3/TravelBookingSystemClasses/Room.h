#pragma once
#include "Coordinates.h"
#include "RoomException.h"
#include "RoomError.h"
#include <vector>
#include <iostream>

class Room {
    Coordinates* coordinates = 0;
    double price;
    bool _isAvailable = 1;
public:
    Room(int price);
    Room(int price, Coordinates* coordinates);
    std::string getCoordinate();
    double calculateCost(int period);
    bool isAvailable();
    void makeAvailable();
    void makeBusy();
};