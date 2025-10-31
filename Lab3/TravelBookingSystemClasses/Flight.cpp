#include "Flight.h"

Flight::Flight(double price, double duration) :
    TransportOption("Flight", price, duration), flightNumber("FL123") {
}

std::string Flight::getFlightNumber() {
    return flightNumber;
}

bool Flight::isInternational() {
    return duration > 3.0;
}