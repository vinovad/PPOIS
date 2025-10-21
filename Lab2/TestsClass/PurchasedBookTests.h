#pragma once
#include "pch.h"
#include "D:/Óíèê/ÏÏÎÈÑ/2LABA/Books/Books/Book.h"
#include <string>
using namespace std;
TEST(PurchasedBookTests, PurchasedBook_Complete) {
    PurchasedBook purchase;
    EXPECT_EQ(purchase.get_book_title(), "Harry Potter");
    EXPECT_EQ(purchase.get_purchase_date(), "12-10-2025");
    EXPECT_DOUBLE_EQ(purchase.get_purchase_price(), 25.99);
    EXPECT_EQ(purchase.get_user_name(), "Ãîñòü");

    testing::internal::CaptureStdout();
    purchase.display_purchase_info();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Harry Potter") != string::npos);
    EXPECT_TRUE(output.find("25.99") != string::npos);
    EXPECT_TRUE(output.find("12-10-2025") != string::npos);
}

TEST(PurchasedBookTests, PurchasedBook_AdditionalTests) {
    PurchasedBook purchase;
    EXPECT_FALSE(purchase.get_book_title().empty());
    EXPECT_FALSE(purchase.get_purchase_date().empty());
    EXPECT_GT(purchase.get_purchase_price(), 0.0);
    EXPECT_FALSE(purchase.get_user_name().empty());
    testing::internal::CaptureStdout();
    purchase.display_purchase_info();
    string output1 = testing::internal::GetCapturedStdout();
    testing::internal::CaptureStdout();
    purchase.display_purchase_info();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output1.empty());
    EXPECT_FALSE(output2.empty());
}