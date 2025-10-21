#pragma once
#include "pch.h"
#include "D:/”ÌËÍ/œœŒ»—/2LABA/Books/Books/Book.h"


TEST(StateChangeTests, StateModification_Complete) {
    YearOfManufacture year;
    year.set_Year(2005);
    EXPECT_EQ(year.get_Year(), 2005);

    PageCount pages;
    pages.set_number_pages(500);
    EXPECT_EQ(pages.get_number_pages(), 500);

    User user("Test User");
    user.add_purchased_book();
    user.add_purchased_book();
    EXPECT_EQ(user.get_books_bought(), 2);

    BookArrivalNotification notification;
    notification.send_notification();
    EXPECT_TRUE(notification.is_notification_sent());
    notification.reset_notification();
    EXPECT_FALSE(notification.is_notification_sent());
}