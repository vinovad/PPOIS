#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TravelAgent.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Booking.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Hotel.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Trip.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Date.h"

class TravelAgentTest : public ::testing::Test {
protected:
    Hotel* hotel;
    Trip* trip;
    Date* date;
    Booking* booking;

    void SetUp() override {
        hotel = new Hotel("Test Hotel", 100, "test@hotel.com", "555-0000");
        trip = new Trip(1, hotel, 3);
        date = new Date(2025, 10, 30);
        booking = new Booking(1, trip, date);
    }

    void TearDown() override {
        delete booking;
        delete date;
        delete trip;
        delete hotel;
    }
};

TEST_F(TravelAgentTest, ConstructorTest) {
    TravelAgent agent("Agent Smith", "pass123", "agent@travel.com", "555-1234", 10.0);
    EXPECT_EQ(agent.name, "Agent Smith");
    EXPECT_EQ(agent.email, "agent@travel.com");
    EXPECT_EQ(agent.whoami, "TravelAgent");
}

TEST_F(TravelAgentTest, ApproveBooking) {
    TravelAgent agent("Agent A", "pass", "a@travel.com", "555-0001", 5.0);
    EXPECT_NO_THROW(agent.approveBooking(booking));
}

TEST_F(TravelAgentTest, CloseBooking) {
    TravelAgent agent("Agent B", "pass", "b@travel.com", "555-0002", 7.5);
    EXPECT_NO_THROW(agent.closeBooking(booking));
}

TEST_F(TravelAgentTest, ContactInfo) {
    TravelAgent agent("Agent D", "pass", "d@travel.com", "555-0004", 8.0);
    EXPECT_EQ(agent.email, "d@travel.com");
}

TEST_F(TravelAgentTest, CommissionRate) {
    TravelAgent agent("Agent E", "pass", "e@travel.com", "555-0005", 15.0);
    EXPECT_EQ(agent.name, "Agent E");
}

TEST_F(TravelAgentTest, WhoAmIField) {
    TravelAgent agent("Agent J", "pass", "j@travel.com", "555-0010", 10.0);
    EXPECT_EQ(agent.whoami, "TravelAgent");
}

TEST_F(TravelAgentTest, ValidateEmail) {
    TravelAgent agent("Agent M", "pass", "m@travel.com", "555-0013", 10.0);
    EXPECT_TRUE(agent.isValid()); 
}
