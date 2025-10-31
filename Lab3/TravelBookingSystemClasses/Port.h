#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Coordinates.h"

class Port {
private:
    std::string portCode;
    Coordinates* location;

public:
    std::string name;
    std::string city;
    std::string country;
    std::string portType;
    int numberOfDocks;
    bool isCruisePort;
    bool isCargoPort;
    std::vector<std::string> services;
    double latitude;
    double longitude;

    Port(std::string code, std::string name, std::string city,
        std::string country, int docks, bool cruise, bool cargo);
    std::string getPortCode();
    void addService(std::string service);
    void removeService(std::string service);
    int getServiceCount();
    bool supportsCruises();
    bool supportsCargo();
    void setCoordinates(double lat, double lon);
    void expandDocks(int count);
    std::string getFullName();
};