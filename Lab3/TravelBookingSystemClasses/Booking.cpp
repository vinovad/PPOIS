#include "Booking.h"
#include "BookingExceprion.h"

Booking::Booking(int customer_id, Trip* trip, Date* date, int id)
    : customer_id(customer_id), trip(trip), id(id), dateCreate(date) {
    status = 0;
}

bool Booking::confirm() {
    try {
        if (status > 0) {
            throw BookingExceprion();
        }
        status = 1;
        return 1;
    }
    catch (BookingExceprion d) {
        std::cout << "Exception : " << d.what() << std::endl;
        return 0;
    }
}

double Booking::calculateCost() {
    return trip->calculateCost();
}

bool Booking::cancel() {
    try {
        if (status == 2) {
            throw BookingExceprion();
        }
        status = 1;
        return 1;
    }
    catch (BookingExceprion d) {
        std::cout << "Exception : " << d.what() << std::endl;
        return 0;
    }
}

int Booking::getStatus() {
    return status;
}