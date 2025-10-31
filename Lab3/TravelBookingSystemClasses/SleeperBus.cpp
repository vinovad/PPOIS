#include "SleeperBus.h"

SleeperBus::SleeperBus(double price, double duration) :
    TransportOption("SleeperBus", price, duration), bedCount(20) {
}

int SleeperBus::getBedCount() {
    return bedCount;
}

bool SleeperBus::hasToilet() {
    return true;
}