#include "Car.h"

Car::Car(double price, double duration, CarAgent* agent) :
    TransportOption("Car", price, duration), agent(agent) {
}

std::string Car::getAgentName() {
    return agent->name;
}

bool Car::isAvailableForRent() {
    return true;
}