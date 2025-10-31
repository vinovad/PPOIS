#include "RegionalTrain.h"

RegionalTrain::RegionalTrain(double price, double duration) :
    TransportOption("RegionalTrain", price, duration), stopCount(10) {
}

int RegionalTrain::getStopCount() {
    return stopCount;
}

bool RegionalTrain::isExpress() {
    return stopCount < 5;
}