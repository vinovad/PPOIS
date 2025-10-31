
#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Customer.h"

class CustomerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(CustomerTest, ConstructorTest) {
    Customer customer("Alice", "pass123", 1, "alice@test.com", "1234567890");
    EXPECT_EQ(customer.name, "Alice");
    EXPECT_EQ(customer.id, 1);
    EXPECT_EQ(customer.whoami, "Customer");
}

TEST_F(CustomerTest, AddBookingId) {
    Customer customer("George", "pass", 7);
    customer.bookingsID.push_back(101);
    customer.bookingsID.push_back(102);
    EXPECT_EQ(customer.bookingsID.size(), 2);
}

TEST_F(CustomerTest, GetCustomerId) {
    Customer customer("Hannah", "pass", 999);
    EXPECT_EQ(customer.id, 999);
}

TEST_F(CustomerTest, LoginAsCustomer) {
    Customer customer("Ian", "password123", 10);
    EXPECT_TRUE(customer.login("password123"));
    EXPECT_FALSE(customer.login("wrongpass"));
}

TEST_F(CustomerTest, ChangePassword) {
    Customer customer("Julia", "oldpass", 11);
    EXPECT_TRUE(customer.editPassword("oldpass", "newpass"));
    EXPECT_TRUE(customer.login("newpass"));
}

TEST_F(CustomerTest, ChangeName) {
    Customer customer("Kevin", "pass", 12);
    EXPECT_TRUE(customer.editName("Kevin Smith", "pass"));
    EXPECT_EQ(customer.name, "Kevin Smith");
}

TEST_F(CustomerTest, MultipleReviews) {
    Customer customer("Laura", "pass", 13);
    customer.addReview(5, "Excellent!", 200);
    customer.addReview(4, "Good", 201);
    customer.addReview(3, "Average", 202);
}

TEST_F(CustomerTest, EmailContact) {
    Customer customer("Mike", "pass", 14, "mike@test.com", "555-0111");
    EXPECT_EQ(customer.email, "mike@test.com");
}
