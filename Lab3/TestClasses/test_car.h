#pragma once
#include <gtest/gtest.h>
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\ElectricCar.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\SUVCar.h"
#include "D:\Óíèê\ÏÏÎÈÑ\3LABA\Lab3\Lab3\CarAgent.h"

class CarTest : public ::testing::Test {
protected:
    CarAgent* agent;

    void SetUp() override {
        agent = new CarAgent("Test Agent", "agent@test.com", "+375447654321");
    }

    void TearDown() override {
        delete agent;
    }
};

TEST_F(CarTest, AllCarTypesConstructor) {
    ElectricCar electric(100.0, 2.0, agent);
    SUVCar suv(120.0, 2.5, agent);
    ElectricCar electricNull(80.0, 1.5, nullptr);
    SUVCar suvNull(90.0, 2.0, nullptr);

    EXPECT_GT(electric.calculateCost(), 0);
    EXPECT_GT(suv.calculateCost(), 0);
    EXPECT_GT(electricNull.calculateCost(), 0);
    EXPECT_GT(suvNull.calculateCost(), 0);
}

TEST_F(CarTest, CostCalculation) {
    ElectricCar electric(100.0, 3.0, agent);
    SUVCar suv(120.0, 2.0, agent);

    EXPECT_EQ(electric.calculateCost(), 300.0);
    EXPECT_EQ(suv.calculateCost(), 240.0);
}

TEST_F(CarTest, ZeroCostCases) {
    ElectricCar zeroDuration(100.0, 0.0, agent);
    SUVCar zeroPrice(0.0, 2.0, agent);

    EXPECT_EQ(zeroDuration.calculateCost(), 0.0);
    EXPECT_EQ(zeroPrice.calculateCost(), 0.0);
}

TEST_F(CarTest, NegativeValues) {
    ElectricCar negativePrice(-50.0, 2.0, agent);
    SUVCar negativeDuration(100.0, -1.0, agent);

    EXPECT_LE(negativePrice.calculateCost(), 0);
    EXPECT_LE(negativeDuration.calculateCost(), 0);
}

TEST_F(CarTest, ElectricCarSpecificMethods) {
    ElectricCar car(100.0, 2.0, agent);
    EXPECT_NO_THROW(car.getAgentName());
    EXPECT_NO_THROW(car.getBatteryCapacity());
}

TEST_F(CarTest, SUVCarSpecificMethods) {
    SUVCar car(120.0, 2.5, agent);
    EXPECT_NO_THROW(car.getAgentName());
    EXPECT_NO_THROW(car.isFourWheelDrive());
}

TEST_F(CarTest, CarAgentProperties) {
    EXPECT_EQ(agent->name, "Test Agent");
    EXPECT_NO_THROW(agent->getContactDetails());
    EXPECT_NO_THROW(agent->getExperienceYears());
}

TEST_F(CarTest, TransportOptionInheritance) {
    ElectricCar* electric = new ElectricCar(100.0, 2.0, agent);
    SUVCar* suv = new SUVCar(120.0, 2.5, agent);

    TransportOption* transports[] = { electric, suv };

    for (auto* transport : transports) {
        EXPECT_NE(transport, nullptr);
        EXPECT_NO_THROW(transport->calculateCost());
        EXPECT_NO_THROW(transport->isAvailable());
    }

    delete electric;
    delete suv;
}

TEST_F(CarTest, CarAgentIntegration) {
    ElectricCar electric(100.0, 2.0, agent);
    SUVCar suv(120.0, 2.5, agent);

    EXPECT_EQ(electric.agent, agent);
    EXPECT_EQ(suv.agent, agent);
    EXPECT_EQ(electric.agent->name, "Test Agent");
    EXPECT_NO_THROW(electric.getAgentName());
    EXPECT_NO_THROW(suv.getAgentName());
}

