#include "Ticket.h"

Ticket::Ticket(std::string number, int bookingId, std::string passenger,
    std::string seat, std::string ticketClass, double price)
    : ticketNumber(number), bookingId(bookingId), passengerName(passenger),
    seatNumber(seat), ticketClass(ticketClass), price(price),
    isCheckedIn(false), isCanceled(false), booking(nullptr) {
}

bool Ticket::checkIn() {
    if (!isCanceled && !isCheckedIn) {
        isCheckedIn = true;
        std::cout << "Checked in: " << passengerName << std::endl;
        return true;
    }
    return false;
}

bool Ticket::cancel() {
    if (!isCheckedIn) {
        isCanceled = true;
        return true;
    }
    return false;
}

std::string Ticket::getTicketNumber() {
    return ticketNumber;
}

std::string Ticket::generateQRCode() {
    qrCode = "QR_" + ticketNumber;
    return qrCode;
}

bool Ticket::isValid() {
    return !isCanceled && !ticketNumber.empty();
}

void Ticket::changeSeat(std::string newSeat) {
    seatNumber = newSeat;
}

double Ticket::getPrice() {
    return price;
}