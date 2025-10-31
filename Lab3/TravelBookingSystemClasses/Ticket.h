#pragma once
#include <iostream>
#include <string>
#include "Booking.h"

class Ticket {
private:
    std::string ticketNumber;
    std::string qrCode;

public:
    int bookingId;
    std::string passengerName;
    std::string seatNumber;
    std::string ticketClass;
    double price;
    bool isCheckedIn;
    bool isCanceled;
    Booking* booking;

    Ticket(std::string number, int bookingId, std::string passenger,
        std::string seat, std::string ticketClass, double price);
    bool checkIn();
    bool cancel();
    std::string getTicketNumber();
    std::string generateQRCode();
    bool isValid();
    void changeSeat(std::string newSeat);
    double getPrice();
};