#pragma once
#include <gtest/gtest.h>
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\Trip.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\Hotel.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\Bus.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\EconomyClassFlight.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\ElectricCar.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\HighSpeedTrain.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\CarAgent.h"

class TripTest : public ::testing::Test {
protected:
    Hotel* hotel;
    Bus* bus;
    EconomyClassFlight* flight;
    ElectricCar* car;
    HighSpeedTrain* train;
    CarAgent* carAgent;

    void SetUp() override {
        hotel = new Hotel("Grand Hotel", 150, "grand@hotel.com", "+375291234567");
        bus = new Bus(100, 2.5);
        flight = new EconomyClassFlight(300, 1.5);
        carAgent = new CarAgent("EcoCar Rentals", "contact@ecocar.com", "+375293456789");
        car = new ElectricCar(80, 3.0, carAgent);
        train = new HighSpeedTrain(120, 2.0);
    }

    void TearDown() override {
        delete hotel;
        delete bus;
        delete flight;
        delete car;
        delete train;
        delete carAgent;
    }
};

TEST_F(TripTest, TripConstructors) {
    Trip trip1(1, hotel, 5);
    Trip trip2(2, hotel, 0);
    Trip trip3(3, nullptr, 5);
    Trip trip4(-1, hotel, 3);
    Trip trip5(999999, hotel, 5);

    SUCCEED();
}

TEST_F(TripTest, AllComponentsFeatures) {
    EXPECT_NO_THROW(bus->getSeatCount());
    EXPECT_NO_THROW(bus->hasAirConditioning());
    EXPECT_NO_THROW(flight->hasMealIncluded());
    EXPECT_NO_THROW(flight->getBaggageLimit());
    EXPECT_NO_THROW(car->getAgentName());
    EXPECT_NO_THROW(car->getBatteryCapacity());
    EXPECT_NO_THROW(train->getMaxSpeed());
    EXPECT_NO_THROW(train->hasFirstClass());

    EXPECT_EQ(carAgent->name, "EcoCar Rentals");
    EXPECT_NO_THROW(carAgent->getContactDetails());
    EXPECT_NO_THROW(carAgent->getExperienceYears());
}

TEST_F(TripTest, CostCalculations) {
    EXPECT_EQ(hotel->calculateCost(3), 450);
    EXPECT_EQ(hotel->calculateCost(0), 0);
    EXPECT_EQ(hotel->calculateCost(7), 1050);

    double busCost = bus->calculateCost();
    double flightCost = flight->calculateCost();
    double carCost = car->calculateCost();
    double trainCost = train->calculateCost();

    EXPECT_GE(busCost, 0);
    EXPECT_GE(flightCost, 0);
    EXPECT_GE(carCost, 0);
    EXPECT_GE(trainCost, 0);
}

TEST_F(TripTest, HotelFeatures) {
    EXPECT_NO_THROW(hotel->getStarRating());
    EXPECT_NO_THROW(hotel->hasPool());
    EXPECT_NO_THROW(hotel->getCoordinate());
    EXPECT_NO_THROW(hotel->isAvailable());
    EXPECT_NO_THROW(hotel->makeBusy());
    EXPECT_NO_THROW(hotel->makeAvailable());
}

TEST_F(TripTest, InheritanceAndPolymorphism) {
    TransportOption* transports[] = { bus, flight, car, train };

    for (auto* transport : transports) {
        EXPECT_NE(transport, nullptr);
        EXPECT_NO_THROW(transport->calculateCost());
        EXPECT_NO_THROW(transport->isAvailable());
    }

    EXPECT_NO_THROW(carAgent->getContactDetails());
}

TEST_F(TripTest, ElectricCarIntegration) {
    EXPECT_NE(car->agent, nullptr);
    EXPECT_EQ(car->agent->name, "EcoCar Rentals");
    EXPECT_NO_THROW(car->getAgentName());
    EXPECT_NO_THROW(car->getBatteryCapacity());
}
