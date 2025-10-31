#include "Bus.h"

Bus::Bus(double price, double duration) :
    TransportOption("Bus", price, duration), seatCount(50) {
}

int Bus::getSeatCount() {
    return seatCount;
}

bool Bus::hasAirConditioning() {
    return true;
}