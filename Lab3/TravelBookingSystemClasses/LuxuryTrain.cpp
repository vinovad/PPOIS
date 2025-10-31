#include "LuxuryTrain.h"

LuxuryTrain::LuxuryTrain(double price, double duration) :
    TransportOption("LuxuryTrain", price, duration), hasPrivateCompartments(true) {
}

bool LuxuryTrain::getHasPrivateCompartments() {
    return hasPrivateCompartments;
}

bool LuxuryTrain::hasDiningCar() {
    return true;
}