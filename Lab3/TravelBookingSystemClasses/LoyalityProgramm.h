#pragma once 
#include <iostream>
#include "AddingBonusesException.h"

class LoyalityProgramm {
    double bonuses = 0;
public:
    LoyalityProgramm(double start_bonuses);
    double getBonuses();
    void addBonuses(double bonus);
};