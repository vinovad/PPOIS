#pragma once
#include <iostream>
#include "User.h"
#include "ContactInfo.h"
#include "TravelAgentException.h"
#include "TravelAgentApplication.h"
#include "Booking.h"

class TravelAgent : public User, public ContactInfo {
    double commission;
public:
    TravelAgent(std::string name, std::string password, std::string email,
        std::string phone, double commission);
    void approveBooking(Booking* booking);
    void closeBooking(Booking* booking);
};