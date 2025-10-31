#pragma once
#include "Flight.h" 

class BisnessClassFlight : public Flight {
private:
    bool loungeAccess;
public:
    BisnessClassFlight(double price, double duration);
    bool hasLoungeAccess();    
    int getExtraBaggageAllowance(); 
};