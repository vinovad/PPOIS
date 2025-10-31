#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\User.h"

class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(UserTest, ConstructorTest) {
    User user("John Doe", "password123", 1);
    EXPECT_EQ(user.name, "John Doe");
    EXPECT_EQ(user.id, 1);
}

TEST_F(UserTest, LoginWithCorrectPassword) {
    User user("John", "password123");
    EXPECT_TRUE(user.login("password123"));
}

TEST_F(UserTest, LoginWithWrongPassword) {
    User user("John", "password123");
    EXPECT_FALSE(user.login("wrongpassword"));
}

TEST_F(UserTest, EditPasswordSuccess) {
    User user("John", "oldpass");
    EXPECT_TRUE(user.editPassword("oldpass", "newpass"));
    EXPECT_TRUE(user.login("newpass"));
}

TEST_F(UserTest, EditPasswordFailure) {
    User user("John", "password");
    EXPECT_FALSE(user.editPassword("wrongold", "newpass"));
}

TEST_F(UserTest, EditNameSuccess) {
    User user("John", "password");
    EXPECT_TRUE(user.editName("Jane", "password"));
    EXPECT_EQ(user.name, "Jane");
}

TEST_F(UserTest, EditNameFailure) {
    User user("John", "password");
    EXPECT_FALSE(user.editName("Jane", "wrongpass"));
    EXPECT_EQ(user.name, "John");
}

TEST_F(UserTest, UserId) {
    User user("User", "pass", 999);
    EXPECT_EQ(user.id, 999);
}

TEST_F(UserTest, NegativeUserId) {
    User user("User", "pass", -1);
    EXPECT_EQ(user.id, -1);
}

