#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Itinerary.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Trip.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Hotel.h"

class ItineraryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Don't create trip as it has null transport causing crashes
    }

    void TearDown() override {
    }
};
TEST_F(ItineraryTest, ConstructorTest) {
    Itinerary itinerary("IT001", 1, "Summer Vacation", 14);
    EXPECT_EQ(itinerary.customerId, 1);
    EXPECT_EQ(itinerary.title, "Summer Vacation");
    EXPECT_EQ(itinerary.totalDays, 14);
    EXPECT_FALSE(itinerary.isConfirmed);
}
TEST_F(ItineraryTest, IsEmptyInitially) {
    Itinerary itinerary("IT002", 1, "Weekend Trip", 3);
    EXPECT_TRUE(itinerary.isEmpty());
}

TEST_F(ItineraryTest, GetTripCount) {
    Itinerary itinerary("IT003", 1, "Business Trip", 5);
    EXPECT_EQ(itinerary.getTripCount(), 0);
}

TEST_F(ItineraryTest, ConfirmWithoutTrips) {
    Itinerary itinerary("IT006", 1, "Empty Trip", 5);
    EXPECT_FALSE(itinerary.confirm());
}

TEST_F(ItineraryTest, UpdateDuration) {
    Itinerary itinerary("IT008", 1, "Extended Stay", 10);
    itinerary.updateDuration(15);
    EXPECT_EQ(itinerary.totalDays, 15);
}

TEST_F(ItineraryTest, ZeroDays) {
    Itinerary itinerary("IT016", 1, "Day Trip", 0);
    EXPECT_EQ(itinerary.totalDays, 0);
}

TEST_F(ItineraryTest, ConfirmItinerary) {
    Itinerary itinerary("IT019", 1, "Confirmed Trip", 7);
    EXPECT_NO_THROW(itinerary.confirm());
}

TEST_F(ItineraryTest, UnconfirmedInitially) {
    Itinerary itinerary("IT020", 1, "New Itinerary", 5);
    EXPECT_FALSE(itinerary.isConfirmed);
}

TEST_F(ItineraryTest, MultipleItineraries) {
    Itinerary itin1("IT021", 1, "Trip 1", 3);
    Itinerary itin2("IT022", 1, "Trip 2", 5);
    Itinerary itin3("IT023", 2, "Trip 3", 7);
    EXPECT_NE(itin1.getItineraryId(), itin2.getItineraryId());
    EXPECT_NE(itin1.customerId, itin3.customerId);
}

