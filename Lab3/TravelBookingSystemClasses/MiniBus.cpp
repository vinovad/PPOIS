#include "MiniBus.h"

MiniBus::MiniBus(double price, double duration) :
    TransportOption("MiniBus", price, duration), seatCount(15) {
}

int MiniBus::getSeatCount() {
    return seatCount;
}

bool MiniBus::isEcoFriendly() {
    return true;
}