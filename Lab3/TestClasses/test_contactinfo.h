#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ContactInfo.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ContactInfoError.h"

class ContactInfoTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(ContactInfoTest, ValidContactInfo) {
    EXPECT_NO_THROW(ContactInfo info("test@example.com", "123-456-7890"));
    ContactInfo info("test@example.com", "123-456-7890");
    EXPECT_EQ(info.email, "test@example.com");
    EXPECT_EQ(info.phoneNumber, "123-456-7890");
}

TEST_F(ContactInfoTest, EmailValidation) {
    ContactInfo info("valid@email.com", "555-1234");
    EXPECT_TRUE(info.isValid());
}

TEST_F(ContactInfoTest, InvalidEmailNoAt) {
    ContactInfo info("invalidemail.com", "555-1234");
    EXPECT_THROW(info.isValid(), ContactInfoError);
}

TEST_F(ContactInfoTest, InvalidEmailThrowsCorrectMessage) {
    ContactInfo info("bademail", "555-1234");
    try {
        info.isValid();
        FAIL() << "Expected ContactInfoError to be thrown";
    }
    catch (const ContactInfoError& e) {
        EXPECT_EQ(std::string(e.what()), "NOT VALID");
    }
}

TEST_F(ContactInfoTest, EmptyEmail) {
    ContactInfo info("", "555-1234");
    EXPECT_THROW(info.isValid(), ContactInfoError);
}

TEST_F(ContactInfoTest, EmailWithMultipleAtSigns) {
    ContactInfo info("test@@example.com", "555-1234");
    EXPECT_NO_THROW(info.isValid());
    EXPECT_TRUE(info.isValid());
}

TEST_F(ContactInfoTest, ValidComplexEmail) {
    ContactInfo info("user.name+tag@example.co.uk", "555-1234");
    EXPECT_TRUE(info.isValid());
}

