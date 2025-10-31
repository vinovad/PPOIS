#pragma once
#include "TransportOption.h"

class Flight : public TransportOption {
private:
    std::string flightNumber;
public:
    Flight(double price, double duration);
    std::string getFlightNumber(); 
    bool isInternational();        
};