#include "Itinerary.h"

Itinerary::Itinerary(std::string id, int custId, std::string title, int days)
    : itineraryId(id), customerId(custId), title(title), totalDays(days),
    totalCost(0.0), isConfirmed(false), startDate(nullptr), endDate(nullptr) {
}

void Itinerary::addTrip(Trip* trip) {
    trips.push_back(trip);
    totalCost += trip->calculateCost();
}

void Itinerary::removeTrip(int index) {
    if (index >= 0 && index < trips.size()) {
        trips.erase(trips.begin() + index);
    }
}

double Itinerary::calculateTotalCost() {
    totalCost = 0;
    for (auto trip : trips) {
        totalCost += trip->calculateCost();
    }
    return totalCost;
}

bool Itinerary::confirm() {
    if (trips.size() > 0) {
        isConfirmed = true;
        return true;
    }
    return false;
}

int Itinerary::getTripCount() {
    return trips.size();
}

std::string Itinerary::getItineraryId() {
    return itineraryId;
}

void Itinerary::updateDuration(int newDays) {
    totalDays = newDays;
}

bool Itinerary::isEmpty() {
    return trips.empty();
}