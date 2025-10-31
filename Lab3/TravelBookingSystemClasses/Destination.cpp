#include "Destination.h"

Destination::Destination(std::string id, std::string name, std::string country,
    std::string climate, int rating)
    : destinationId(id), name(name), country(country), climate(climate),
    popularityRating(rating), averageTemperature(0.0),
    requiresVisa(false), location(nullptr), city(nullptr) {
}

void Destination::addAttraction(std::string attraction) {
    attractions.push_back(attraction);
}

void Destination::removeAttraction(int index) {
    if (index >= 0 && index < attractions.size()) {
        attractions.erase(attractions.begin() + index);
    }
}

int Destination::getAttractionCount() {
    return attractions.size();
}

std::string Destination::getDestinationId() {
    return destinationId;
}

bool Destination::isVisaRequired() {
    return requiresVisa;
}

void Destination::updateRating(int newRating) {
    if (newRating >= 0 && newRating <= 10) {
        popularityRating = newRating;
    }
}

std::string Destination::getClimate() {
    return climate;
}

void Destination::setLocation(Coordinates* coords) {
    location = coords;
}