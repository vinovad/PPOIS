#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Coordinates.h"

class Station {
private:
    std::string stationCode;
    Coordinates* location;

public:
    std::string name;
    std::string city;
    std::string stationType;
    int numberOfPlatforms;
    bool hasParking;
    bool hasWaitingRoom;
    std::vector<std::string> facilities;
    double latitude;
    double longitude;

    Station(std::string code, std::string name, std::string city,
        std::string type, int platforms);
    std::string getStationCode();
    void addFacility(std::string facility);
    void removeFacility(std::string facility);
    int getFacilityCount();
    bool isParkingAvailable();
    void enableParking();
    void setCoordinates(double lat, double lon);
    std::string getStationType();
};