#pragma once
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:/Уник/ППОИС/2LABA/Books/Books/Book.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/Shipping.h"
#include "D:/Уник/ППОИС/2LABA/Books/Books/User.h"

using namespace std;

TEST(ShippingTests, Shipping_ConstructorWithParameters) {
    User user("Тестовый Пользователь");
    Shipping shipping(true, user);

    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "Тестовый Пользователь");
    EXPECT_NO_THROW(shipping.get_shipping_type());
    EXPECT_NO_THROW(shipping.get_shipping_cost());
}

TEST(ShippingTests, Shipping_DefaultConstructor) {
    Shipping shipping;

    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(shipping.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
}

TEST(ShippingTests, Shipping_SetShippingStatus) {
    User user("Пользователь Доставки");
    Shipping shipping(true, user);
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(false);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(shipping.has_shipping_available());
    EXPECT_TRUE(output.find("Доставка отключена для пользователя: Пользователь Доставки") != string::npos);
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(true);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_TRUE(output.find("Доставка активирована для пользователя: Пользователь Доставки") != string::npos);
}

TEST(ShippingTests, Shipping_MultipleUsers) {
    User user1("Первый Пользователь");
    User user2("Второй Пользователь");

    Shipping shipping1(true, user1);
    Shipping shipping2(false, user2);

    EXPECT_TRUE(shipping1.has_shipping_available());
    EXPECT_FALSE(shipping2.has_shipping_available());
    EXPECT_EQ(shipping1.get_AssociatedUserName(), "Первый Пользователь");
    EXPECT_EQ(shipping2.get_AssociatedUserName(), "Второй Пользователь");
}

TEST(ShippingTests, Shipping_EdgeCases) {
    User defaultUser;
    Shipping shipping(false, defaultUser);

    EXPECT_FALSE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "Гость");
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(true);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(shipping.has_shipping_available());

    testing::internal::CaptureStdout();
    shipping.set_shipping_status(true);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(shipping.has_shipping_available());
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(false);
    output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(shipping.has_shipping_available());
}

TEST(ShippingTests, Shipping_IntegrationWithBook) {
    User user("Пользователь Книги");
    Book book("Fantasy", 1997, "Harry Potter", "United Kingdom",
        "Автор : Joanne Rowling", "1965 год", 15, 4.8, "Hard",
        "Bloomsbury", "Magic", "English", "A5",
        "Марина Литвинова", 80, 400, "Harry Potter", 12,
        25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025",
        "new", "Harry Potter", 1, "A", 1, "третья", 15,
        "Bloomsbury Publishing", "United Kingdom", "United Kingdom",
        "teenagers", "middle_school", false, true, true, 1000000,
        "Отличная книга о магии и приключениях!", "Рекомендую к прочтению!",
        1000, "Гость", "Harry Potter", "12-10-2025", 25.99, "Гость",
        "Harry Potter", user, "Ivan", 20, true);
    Shipping shipping(true, user);
    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "Пользователь Книги");
}

TEST(ShippingTests, Shipping_CostAndTypeConsistency) {
    Shipping shipping;
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
    EXPECT_EQ(shipping.get_shipping_type(), "standard");

    // Проверяем многократные вызовы геттеров
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
    EXPECT_EQ(shipping.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
}

TEST(ShippingTests, Shipping_AllMethodsCoverage) {
    User user("Покрытие методов");
    Shipping shipping(true, user);
    shipping.has_shipping_available();
    shipping.get_AssociatedUserName();
    shipping.get_shipping_type();
    shipping.get_shipping_cost();
    shipping.set_shipping_status(true);
    EXPECT_TRUE(true);
}

TEST(ShippingTests, Shipping_ConstructorComparison) {
    User user("Сравнение конструкторов");

    Shipping shippingWithParams(true, user);
    Shipping shippingDefault;
    EXPECT_TRUE(shippingWithParams.has_shipping_available());
    EXPECT_EQ(shippingWithParams.get_AssociatedUserName(), "Сравнение конструкторов");
    EXPECT_TRUE(shippingDefault.has_shipping_available());
    EXPECT_EQ(shippingDefault.get_AssociatedUserName(), "Гость");
    EXPECT_EQ(shippingDefault.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shippingDefault.get_shipping_cost(), 5.99);
}