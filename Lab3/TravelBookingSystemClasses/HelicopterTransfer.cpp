#include "HelicopterTransfer.h"

HelicopterTransfer::HelicopterTransfer(double price, double duration) :
    TransportOption("HelicopterTransfer", price, duration), maxPassengers(6) {
}

int HelicopterTransfer::getMaxPassengers() {
    return maxPassengers;
}

bool HelicopterTransfer::isScenicFlight() {
    return true;
}