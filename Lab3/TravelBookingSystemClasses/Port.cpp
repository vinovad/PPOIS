#include "Port.h"

Port::Port(std::string code, std::string name, std::string city,
    std::string country, int docks, bool cruise, bool cargo)
    : portCode(code), name(name), city(city), country(country),
    numberOfDocks(docks), isCruisePort(cruise), isCargoPort(cargo),
    latitude(0.0), longitude(0.0), location(nullptr) {
}

std::string Port::getPortCode() {
    return portCode;
}

void Port::addService(std::string service) {
    services.push_back(service);
}

void Port::removeService(std::string service) {
    for (auto it = services.begin(); it != services.end(); ++it) {
        if (*it == service) {
            services.erase(it);
            break;
        }
    }
}

int Port::getServiceCount() {
    return services.size();
}

bool Port::supportsCruises() {
    return isCruisePort;
}

bool Port::supportsCargo() {
    return isCargoPort;
}

void Port::setCoordinates(double lat, double lon) {
    latitude = lat;
    longitude = lon;
}

void Port::expandDocks(int count) {
    numberOfDocks += count;
}

std::string Port::getFullName() {
    return name + " (" + portCode + ")";
}