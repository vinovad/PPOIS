#pragma once
#include <gtest/gtest.h>
#include "D:\”ÌËÍ\œœŒ»—\3LABA\Lab3\Lab3\Notification.h"

class NotificationTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code
    }
};
TEST_F(NotificationTest, ConstructorTest) {
    Notification notif("N001", 1, "Booking confirmed", "booking", "email");
    EXPECT_EQ(notif.userId, 1);
    EXPECT_EQ(notif.message, "Booking confirmed");
    EXPECT_EQ(notif.type, "booking");
    EXPECT_FALSE(notif.isRead);
    EXPECT_FALSE(notif.isSent);
}

TEST_F(NotificationTest, SendNotification) {
    Notification notif("N002", 2, "Payment received", "payment", "sms");
    EXPECT_TRUE(notif.send());
    EXPECT_TRUE(notif.isSent);
}

TEST_F(NotificationTest, SendAlreadySent) {
    Notification notif("N003", 3, "Reminder", "reminder", "push");
    notif.send();
    EXPECT_FALSE(notif.send());
}

TEST_F(NotificationTest, MarkAsRead) {
    Notification notif("N004", 4, "Welcome", "welcome", "email");
    notif.send();
    EXPECT_TRUE(notif.markAsRead());
    EXPECT_TRUE(notif.isRead);
}

TEST_F(NotificationTest, MarkAsReadNotSent) {
    Notification notif("N005", 5, "Alert", "alert", "sms");
    EXPECT_FALSE(notif.markAsRead());
}

TEST_F(NotificationTest, Retry) {
    Notification notif("N006", 6, "Failed delivery", "system", "email");
    notif.retry();
    EXPECT_EQ(notif.retryCount, 1);
}

TEST_F(NotificationTest, SetPriority) {
    Notification notif("N007", 7, "Urgent", "alert", "push");
    notif.setPriority("high");
    EXPECT_EQ(notif.priority, "high");
}

TEST_F(NotificationTest, EmptyMessage) {
    Notification notif("N009", 9, "", "empty", "sms");
    EXPECT_EQ(notif.message, "");
}

TEST_F(NotificationTest, DifferentChannels) {
    Notification notif1("N011", 11, "Email test", "test", "email");
    Notification notif2("N012", 12, "SMS test", "test", "sms");
    Notification notif3("N013", 13, "Push test", "test", "push");
    EXPECT_EQ(notif1.channel, "email");
    EXPECT_EQ(notif2.channel, "sms");
    EXPECT_EQ(notif3.channel, "push");
}

TEST_F(NotificationTest, GetUserId) {
    Notification notif("N015", 999, "User test", "test", "sms");
    EXPECT_EQ(notif.userId, 999);
}

TEST_F(NotificationTest, GetChannel) {
    Notification notif("N008", 8, "News", "info", "email");
    EXPECT_EQ(notif.getChannel(), "email");
}
