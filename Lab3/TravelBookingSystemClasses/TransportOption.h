#pragma once
#include <iostream>

class TransportOption {
    bool isBusy = 1;
public:
    std::string type;
    double price;
    double duration;
    TransportOption(std::string type, double price, double duration);
    double calculateCost();
    bool isAvailable();
    void makeBusy();
    void makeAvailable();
};