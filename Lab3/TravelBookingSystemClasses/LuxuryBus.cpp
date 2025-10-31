#include "LuxuryBus.h"

LuxuryBus::LuxuryBus(double price, double duration) :
    TransportOption("LuxuryBus", price, duration), hasEntertainmentSystem(true) {
}

bool LuxuryBus::getHasEntertainmentSystem() {
    return hasEntertainmentSystem;
}

int LuxuryBus::getLuxuryLevel() {
    return 5;
}