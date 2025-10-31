#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Trip.h"
#include "Date.h"

class Itinerary {
private:
    std::string itineraryId;
    Date* startDate;
    Date* endDate;

public:
    std::vector<Trip*> trips;
    int customerId;
    std::string title;
    std::string description;
    int totalDays;
    double totalCost;
    bool isConfirmed;

    Itinerary(std::string id, int custId, std::string title, int days);
    void addTrip(Trip* trip);
    void removeTrip(int index);
    double calculateTotalCost();
    bool confirm();
    int getTripCount();
    std::string getItineraryId();
    void updateDuration(int newDays);
    bool isEmpty();
};