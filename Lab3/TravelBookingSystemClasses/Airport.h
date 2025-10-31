#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Coordinates.h"
#include "City.h" 

class Airport {
private:
    std::string airportCode;
    Coordinates* location;

public:
    std::string name;
    std::string city;
    std::string country;
    int numberOfTerminals;
    int numberOfRunways;
    bool isInternational;
    std::vector<std::string> airlines;
    double latitude;
    double longitude;

    Airport(std::string code, std::string name, std::string city,
        std::string country, int terminals, bool international);

    std::string getAirportCode();
    void addAirline(std::string airline);
    void removeAirline(std::string airline);
    int getAirlineCount();
    bool hasInternationalFlights();
    void setCoordinates(double lat, double lon);
    std::string getFullName();
    void upgradeTerminals(int count);
};