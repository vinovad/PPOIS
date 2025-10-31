#include "TravelAgent.h"

TravelAgent::TravelAgent(std::string name, std::string password, std::string email,
    std::string phone, double commission) :
    User(name, password), ContactInfo(email, phone), commission(commission) {
    whoami = "TravelAgent";
}

void TravelAgent::approveBooking(Booking* booking) {
    try {
        if (booking->confirm() == 0) {
            throw TravelAgentException();
        }
    }
    catch (const TravelAgentException& a) {
        std::cout << "Exception : " << a.what() << std::endl;
    }
}

void TravelAgent::closeBooking(Booking* booking) {
    try {
        if (booking->cancel() == 0) {
            throw TravelAgentException();
        }
    }
    catch (const TravelAgentException& a) {
        std::cout << "Exception : " << a.what() << std::endl;
    }
}