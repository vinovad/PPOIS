#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include <string>

using namespace std;

TEST(NotificationTests, BookArrivalNotification_Complete) {
    BookArrivalNotification notification;
    EXPECT_EQ(notification.get_book_title(), "Harry Potter");
    EXPECT_FALSE(notification.is_notification_sent());
    EXPECT_EQ(notification.get_AssociatedArrivalDate(), "12-10-2025");

    testing::internal::CaptureStdout();
    notification.send_notification();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Harry Potter") != string::npos);
    EXPECT_TRUE(output.find("12-10-2025") != string::npos);
    EXPECT_TRUE(notification.is_notification_sent());

    // Повторная отправка
    testing::internal::CaptureStdout();
    notification.send_notification();
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("уже было отправлено") != string::npos);

    notification.reset_notification();
    EXPECT_FALSE(notification.is_notification_sent());
}
TEST(NotificationTests, BookArrivalNotification_AdditionalTests) {
    BookArrivalNotification notification;
    // Проверка начального состояния
    EXPECT_FALSE(notification.is_notification_sent());
    EXPECT_FALSE(notification.get_book_title().empty());
    EXPECT_FALSE(notification.get_AssociatedArrivalDate().empty());
    // Многократное использование
    notification.send_notification();
    EXPECT_TRUE(notification.is_notification_sent());
    notification.reset_notification();
    EXPECT_FALSE(notification.is_notification_sent());
    notification.send_notification();
    EXPECT_TRUE(notification.is_notification_sent());
    notification.get_book_title();
    notification.get_AssociatedArrivalDate();
    notification.is_notification_sent();
}