#include "TransportOption.h"

TransportOption::TransportOption(std::string type, double price, double duration) :
    type(type), price(price), duration(duration) {
}

double TransportOption::calculateCost() {
    return price * duration;
}

bool TransportOption::isAvailable() {
    return !isBusy;
}

void TransportOption::makeBusy() {
    isBusy = 1;
}

void TransportOption::makeAvailable() {
    isBusy = 0;
}