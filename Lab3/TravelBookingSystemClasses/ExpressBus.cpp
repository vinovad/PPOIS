#include "ExpressBus.h"

ExpressBus::ExpressBus(double price, double duration) :
    TransportOption("ExpressBus", price, duration), hasWiFi(true) {
}

bool ExpressBus::getHasWiFi() {
    return hasWiFi;
}

int ExpressBus::getTravelTime() {
    return (int)duration;
}