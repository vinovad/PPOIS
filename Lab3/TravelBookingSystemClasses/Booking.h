#pragma once
#include <iostream>
#include "Review.h"
#include "Trip.h"
#include "Date.h"
#include "BookingExceprion.h"
#include "BookingApplication.h"

class Booking {
public:
    int id;
    int customer_id;
    int trip_id;
    int status;
    Date* dateCreate;
    Review* r;
    Trip* trip;

    Booking(int customer_id, Trip* trip, Date* date, int id = 0);
    bool confirm();
    double calculateCost();
    bool cancel();
    int getStatus();
};