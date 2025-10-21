#pragma once
#include "pch.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"

TEST(LoyaltyProgramTests, LoyaltyProgram_Complete) {
    User user("Тестовый пользователь");
    LoyaltyProgram program(user);

    EXPECT_TRUE(program.has_user_set());
    EXPECT_EQ(program.get_AssociatedUserName(), "Тестовый пользователь");
    EXPECT_EQ(program.get_AssociatedUserBooks(), 0);

    testing::internal::CaptureStdout();
    double price1 = program.apply_discount(100.0);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_DOUBLE_EQ(price1, 100.0);
    EXPECT_TRUE(output.find("0%") != string::npos || output.find("0 %") != string::npos);

    User userWithDiscount("Пользователь со скидкой");
    LoyaltyProgram discountProgram(userWithDiscount);
    testing::internal::CaptureStdout();
    discountProgram.apply_discount(100.0);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("0%") != string::npos || output.find("0 %") != string::npos);

    LoyaltyProgram emptyProgram;
    EXPECT_FALSE(emptyProgram.has_user_set());
    EXPECT_EQ(emptyProgram.get_AssociatedUserName(), "Пользователь не установлен");
}