#include "Trip.h"

Trip::Trip(int id, Hotel* hotel, int days) : id(id), hotel(hotel), days(days) {}

double Trip::calculateCost() {
    double cost = 0;
    cost = hotel->calculateCost(days);
    cost = cost + transport->calculateCost();
    return cost;
}