#include "ElectricCar.h"

ElectricCar::ElectricCar(double price, double duration, CarAgent* agent) :
    TransportOption("ElectricCar", price, duration), agent(agent) {
}

std::string ElectricCar::getAgentName() {
    return agent->name;
}

double ElectricCar::getBatteryCapacity() {
    return 75.5;
}