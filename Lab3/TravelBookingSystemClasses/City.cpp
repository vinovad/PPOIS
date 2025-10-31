#include "City.h"

City::City(std::string city) : city(city) {}

std::string City::getName() {
    return city;
}

int City::getPopulation() {
    return 1000000;
}