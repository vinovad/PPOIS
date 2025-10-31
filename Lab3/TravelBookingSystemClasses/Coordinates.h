#pragma once
#include "City.h" // 2 1 1

class Coordinates {
public:
    double latitude;
    double longitude;
    City c;
    Coordinates(double latitude, double longitude);
};