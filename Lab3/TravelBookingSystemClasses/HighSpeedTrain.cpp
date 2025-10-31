#include "HighSpeedTrain.h"

HighSpeedTrain::HighSpeedTrain(double price, double duration) :
    TransportOption("HighSpeedTrain", price, duration), maxSpeed(300.0) {
}

double HighSpeedTrain::getMaxSpeed() {
    return maxSpeed;
}

bool HighSpeedTrain::hasFirstClass() {
    return true;
}