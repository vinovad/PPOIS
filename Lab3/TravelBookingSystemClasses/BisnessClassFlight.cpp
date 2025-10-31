#include "BisnessClassFlight.h"

BisnessClassFlight::BisnessClassFlight(double price, double duration) :
    Flight(price, duration), loungeAccess(true) {
}

bool BisnessClassFlight::hasLoungeAccess() {
    return loungeAccess;
}

int BisnessClassFlight::getExtraBaggageAllowance() {
    return 2;
}