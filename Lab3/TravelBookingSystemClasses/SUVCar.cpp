#include "SUVCar.h"

SUVCar::SUVCar(double price, double duration, CarAgent* agent) :
    TransportOption("SUVCar", price, duration), agent(agent) {
}

std::string SUVCar::getAgentName() {
    return agent->name;
}

bool SUVCar::isFourWheelDrive() {
    return true;
}