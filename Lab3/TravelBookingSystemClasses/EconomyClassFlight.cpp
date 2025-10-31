#include "EconomyClassFlight.h"

EconomyClassFlight::EconomyClassFlight(double price, double duration) :
    Flight(price, duration), mealIncluded(false) {
}

bool EconomyClassFlight::hasMealIncluded() {
    return mealIncluded;
}

int EconomyClassFlight::getBaggageLimit() {
    return 1;
}