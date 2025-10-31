#pragma once
#include "Flight.h"

class EconomyClassFlight : public Flight {
private:
    bool mealIncluded;
public:
    EconomyClassFlight(double price, double duration);
    bool hasMealIncluded();    
    int getBaggageLimit();     
};