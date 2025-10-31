#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "City.h"
#include "Coordinates.h"

class Destination {
private:
    std::string destinationId;
    Coordinates* location;

public:
    std::string name;
    std::string country;
    std::string description;
    std::string climate;
    std::vector<std::string> attractions;
    double averageTemperature;
    int popularityRating;
    bool requiresVisa;
    City* city;

    Destination(std::string id, std::string name, std::string country,
        std::string climate, int rating);
    void addAttraction(std::string attraction);
    void removeAttraction(int index);
    int getAttractionCount();
    std::string getDestinationId();
    bool isVisaRequired();
    void updateRating(int newRating);
    std::string getClimate();
    void setLocation(Coordinates* coords);
};