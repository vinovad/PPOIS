#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Ticket.h"

class TicketTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(TicketTest, ConstructorTest) {
    Ticket ticket("TKT001", 1, "John Doe", "12A", "Economy", 250.0);
    EXPECT_EQ(ticket.bookingId, 1);
    EXPECT_EQ(ticket.passengerName, "John Doe");
    EXPECT_EQ(ticket.seatNumber, "12A");
    EXPECT_EQ(ticket.price, 250.0);
    EXPECT_FALSE(ticket.isCheckedIn);
    EXPECT_FALSE(ticket.isCanceled);
}

TEST_F(TicketTest, CheckIn) {
    Ticket ticket("TKT002", 2, "Alice Smith", "5B", "Business", 500.0);
    EXPECT_TRUE(ticket.checkIn());
    EXPECT_TRUE(ticket.isCheckedIn);
}

TEST_F(TicketTest, CheckInAlreadyCheckedIn) {
    Ticket ticket("TKT003", 3, "Bob Jones", "8C", "First", 1000.0);
    ticket.checkIn();
    EXPECT_FALSE(ticket.checkIn());
}

TEST_F(TicketTest, CancelTicket) {
    Ticket ticket("TKT004", 4, "Carol White", "15D", "Economy", 200.0);
    EXPECT_TRUE(ticket.cancel());
    EXPECT_TRUE(ticket.isCanceled);
}

TEST_F(TicketTest, CancelAfterCheckIn) {
    Ticket ticket("TKT005", 5, "Dave Brown", "3A", "Business", 450.0);
    ticket.checkIn();
    EXPECT_FALSE(ticket.cancel());
}

TEST_F(TicketTest, IsValid) {
    Ticket ticket("TKT006", 6, "Eve Green", "20F", "Economy", 180.0);
    EXPECT_TRUE(ticket.isValid());
    ticket.cancel();
    EXPECT_FALSE(ticket.isValid());
}

TEST_F(TicketTest, SeatNumberFormat) {
    Ticket ticket("TKT011", 11, "Iris Purple", "25F", "Economy", 250.0);
    EXPECT_EQ(ticket.seatNumber, "25F");
}

TEST_F(TicketTest, GetBookingId) {
    Ticket ticket("TKT016", 999, "Nick Brown", "7C", "Business", 400.0);
    EXPECT_EQ(ticket.bookingId, 999);
}

TEST_F(TicketTest, GenerateQRCode) {
    Ticket ticket("TKT007", 7, "Frank Black", "7E", "Premium", 600.0);
    std::string qr = ticket.generateQRCode();
    EXPECT_EQ(qr, "QR_TKT007");
}

TEST_F(TicketTest, ChangeSeat) {
    Ticket ticket("TKT008", 8, "Grace Blue", "10A", "Economy", 220.0);
    ticket.changeSeat("11B");
    EXPECT_EQ(ticket.seatNumber, "11B");
}
