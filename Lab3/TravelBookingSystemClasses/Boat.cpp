#include "Boat.h"

Boat::Boat(double price, double duration) :
    TransportOption("Boat", price, duration), passengerCapacity(20) {
}

int Boat::getPassengerCapacity() {
    return passengerCapacity;
}

bool Boat::hasLifeJackets() {
    return true;
}