#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\AuthExceptions.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\BookingExceprion.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CardError.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\RoomException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\AddingBonusesException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\CouponException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\DataException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TimeException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TravelAgentException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ReviewException.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\ContactInfoError.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\RoomError.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\BookingApplication.h"
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\TravelAgentApplication.h"

class ExceptionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};

TEST_F(ExceptionTest, AuthExceptionTest) {
    AuthException ex("Invalid password");
    EXPECT_EQ(ex.getError(), "Invalid password");
}

TEST_F(ExceptionTest, AuthExceptionThrow) {
    EXPECT_THROW({
        throw AuthException("Test error");
        }, AuthException);
}

TEST_F(ExceptionTest, BookingExceptionThrow) {
    EXPECT_THROW({
        throw BookingExceprion();
        }, BookingExceprion);
}

TEST_F(ExceptionTest, CardErrorThrow) {
    EXPECT_THROW({
        throw CardError("Test card error");
        }, CardError);
}

TEST_F(ExceptionTest, AddingBonusesExceptionThrow) {
    EXPECT_THROW({
        throw AddingBonusesException("Bonus limit exceeded");
        }, AddingBonusesException);
}

TEST_F(ExceptionTest, CouponExceptionThrow) {
    EXPECT_THROW({
        throw CouponException();
        }, CouponException);
}
TEST_F(ExceptionTest, DataExceptionThrow) {
    EXPECT_THROW({
        throw DataException();
        }, DataException);
}

TEST_F(ExceptionTest, DataExceptionCatch) {
    try {
        throw DataException();
    }
    catch (const DataException& e) {
        EXPECT_EQ(std::string(e.what()), "Data NOT valid");
    }
}

TEST_F(ExceptionTest, TimeExceptionThrow) {
    EXPECT_THROW({
        throw TimeException();
        }, TimeException);
}

TEST_F(ExceptionTest, TimeExceptionCatch) {
    try {
        throw TimeException();
    }
    catch (const TimeException& e) {
        EXPECT_EQ(std::string(e.what()), "sec id negative");
    }
}

TEST_F(ExceptionTest, TravelAgentExceptionThrow) {
    EXPECT_THROW({
        throw TravelAgentException();
        }, TravelAgentException);
}

TEST_F(ExceptionTest, TravelAgentExceptionCatch) {
    try {
        throw TravelAgentException();
    }
    catch (const TravelAgentException& e) {
        EXPECT_EQ(std::string(e.what()), "booking is already closed");
    }
}

TEST_F(ExceptionTest, ReviewExceptionThrow) {
    EXPECT_THROW({
        throw ReviewException();
        }, ReviewException);
}

TEST_F(ExceptionTest, ContactInfoErrorThrow) {
    EXPECT_THROW({
        throw ContactInfoError("Phone number too short");
        }, ContactInfoError);
}

TEST_F(ExceptionTest, RoomErrorThrow) {
    EXPECT_THROW({
        throw RoomError();
        }, RoomError);
}

TEST_F(ExceptionTest, MultipleExceptionsTest) {
    bool caught1 = false, caught2 = false, caught3 = false;

    try {
        throw ReviewException();
    }
    catch (const ReviewException&) {
        caught1 = true;
    }

    try {
        throw ContactInfoError("Test");
    }
    catch (const ContactInfoError&) {
        caught2 = true;
    }

    try {
        throw RoomError();
    }
    catch (const RoomError&) {
        caught3 = true;
    }

    EXPECT_TRUE(caught1);
    EXPECT_TRUE(caught2);
    EXPECT_TRUE(caught3);
}
TEST_F(ExceptionTest, BookingApplicationThrow) {
    EXPECT_THROW({
        throw BookingApplication();
        }, BookingApplication);
}

TEST_F(ExceptionTest, BookingApplicationInheritance) {
    EXPECT_THROW({
        throw BookingApplication();
        }, std::runtime_error);
}

TEST_F(ExceptionTest, TravelAgentApplicationThrow) {
    EXPECT_THROW({
        throw TravelAgentApplication();
        }, TravelAgentApplication);
}

TEST_F(ExceptionTest, TravelAgentApplicationInheritance) {
    EXPECT_THROW({
        throw TravelAgentApplication();
        }, std::runtime_error);
}

