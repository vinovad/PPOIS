#pragma once 
#include <iostream>
#include "CardError.h" 

class CreditCard {
public:
    std::string number;
    std::string holderName;
    std::string expiryDate;
    std::string cvv;
    CreditCard(std::string number, std::string holderName, std::string expiryDate, std::string cvv);
    bool validate();
    bool charge(double sum);
};