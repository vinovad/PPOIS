#include "Train.h"

Train::Train(double price, double duration) :
    TransportOption("Train", price, duration), carriageCount(8) {
}

int Train::getCarriageCount() {
    return carriageCount;
}

bool Train::isElectric() {
    return true;
}