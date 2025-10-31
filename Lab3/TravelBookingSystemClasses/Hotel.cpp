#include "Hotel.h"

Hotel::Hotel(std::string name, int price, std::string email, std::string phone) :
    Room(price), name(name), ContactInfo(email, phone), starRating(4) {
}

Hotel::Hotel(std::string name, int price, std::string email, std::string phone, Coordinates* coordinates) :
    Room(price, coordinates), name(name), ContactInfo(email, phone), starRating(4) {
}

int Hotel::getStarRating() {
    return starRating;
}

bool Hotel::hasPool() {
    return starRating >= 4;
}