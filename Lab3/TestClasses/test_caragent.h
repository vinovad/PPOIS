#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CarAgent.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ContactInfoError.h"

class CarAgentTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CarAgentTest, CreateCarAgent) {
    EXPECT_NO_THROW(CarAgent agent("John Doe", "john@example.com", "555-1234"));
    CarAgent agent("John Doe", "john@example.com", "555-1234");
    EXPECT_EQ(agent.name, "John Doe");
    EXPECT_EQ(agent.email, "john@example.com");
    EXPECT_EQ(agent.phoneNumber, "555-1234");
}

TEST_F(CarAgentTest, GetContactDetails) {
    CarAgent agent("Jane Smith", "jane@test.com", "555-5678");
    std::string details = agent.getContactDetails();
    EXPECT_EQ(details, "Jane Smith - jane@test.com - 555-5678");
}

TEST_F(CarAgentTest, GetExperienceYears) {
    CarAgent agent("Bob Wilson", "bob@example.com", "555-9999");
    EXPECT_EQ(agent.getExperienceYears(), 5);
}

TEST_F(CarAgentTest, InheritanceFromContactInfo) {
    CarAgent agent("Test Agent", "test@email.com", "123-4567");
    EXPECT_TRUE(agent.isValid());
}

TEST_F(CarAgentTest, InvalidEmailInCarAgent) {
    CarAgent agent("Bad Agent", "bademail", "555-1234");
    EXPECT_THROW(agent.isValid(), ContactInfoError);
}


