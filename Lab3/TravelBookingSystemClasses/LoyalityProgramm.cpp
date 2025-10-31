#include "LoyalityProgramm.h"

LoyalityProgramm::LoyalityProgramm(double start_bonuses) : bonuses(start_bonuses) {}

double LoyalityProgramm::getBonuses() {
    return this->bonuses;
}

void LoyalityProgramm::addBonuses(double bonus) {
    try {
        if (bonus < 0) {
            throw AddingBonusesException("bonus < 0");
        }
        this->bonuses += bonus;
    }
    catch (AddingBonusesException a) {
        std::cout << "Exception " << a.what() << std::endl;
    }
}