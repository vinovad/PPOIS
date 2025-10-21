#pragma once
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "D:/����/�����/2LABA/Books/Books/Book.h"
#include "D:/����/�����/2LABA/Books/Books/Shipping.h"
#include "D:/����/�����/2LABA/Books/Books/User.h"

using namespace std;

TEST(ShippingTests, Shipping_ConstructorWithParameters) {
    User user("�������� ������������");
    Shipping shipping(true, user);

    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "�������� ������������");
    EXPECT_NO_THROW(shipping.get_shipping_type());
    EXPECT_NO_THROW(shipping.get_shipping_cost());
}

TEST(ShippingTests, Shipping_DefaultConstructor) {
    Shipping shipping;

    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "�����");
    EXPECT_EQ(shipping.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
}

TEST(ShippingTests, Shipping_SetShippingStatus) {
    User user("������������ ��������");
    Shipping shipping(true, user);
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(false);
    string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(shipping.has_shipping_available());
    EXPECT_TRUE(output.find("�������� ��������� ��� ������������: ������������ ��������") != string::npos);
    testing::internal::CaptureStdout();
    shipping.set_shipping_status(true);
    output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_TRUE(output.find("�������� ������������ ��� ������������: ������������ ��������") != string::npos);
}

TEST(ShippingTests, Shipping_MultipleUsers) {
    User user1("������ ������������");
    User user2("������ ������������");

    Shipping shipping1(true, user1);
    Shipping shipping2(false, user2);

    EXPECT_TRUE(shipping1.has_shipping_available());
    EXPECT_FALSE(shipping2.has_shipping_available());
    EXPECT_EQ(shipping1.get_AssociatedUserName(), "������ ������������");
    EXPECT_EQ(shipping2.get_AssociatedUserName(), "������ ������������");
}

TEST(ShippingTests, Shipping_EdgeCases) {
    User defaultUser;
    Shipping shipping(false, defaultUser);

    EXPECT_FALSE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "�����");
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
    User user("������������ �����");
    Book book("Fantasy", 1997, "Harry Potter", "United Kingdom",
        "����� : Joanne Rowling", "1965 ���", 15, 4.8, "Hard",
        "Bloomsbury", "Magic", "English", "A5",
        "������ ���������", 80, 400, "Harry Potter", 12,
        25.99, "USD", 15.0, "", false, 50, 600.0, "12-10-2025",
        "new", "Harry Potter", 1, "A", 1, "������", 15,
        "Bloomsbury Publishing", "United Kingdom", "United Kingdom",
        "teenagers", "middle_school", false, true, true, 1000000,
        "�������� ����� � ����� � ������������!", "���������� � ���������!",
        1000, "�����", "Harry Potter", "12-10-2025", 25.99, "�����",
        "Harry Potter", user, "Ivan", 20, true);
    Shipping shipping(true, user);
    EXPECT_TRUE(shipping.has_shipping_available());
    EXPECT_EQ(shipping.get_AssociatedUserName(), "������������ �����");
}

TEST(ShippingTests, Shipping_CostAndTypeConsistency) {
    Shipping shipping;
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
    EXPECT_EQ(shipping.get_shipping_type(), "standard");

    // ��������� ������������ ������ ��������
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
    EXPECT_EQ(shipping.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shipping.get_shipping_cost(), 5.99);
}

TEST(ShippingTests, Shipping_AllMethodsCoverage) {
    User user("�������� �������");
    Shipping shipping(true, user);
    shipping.has_shipping_available();
    shipping.get_AssociatedUserName();
    shipping.get_shipping_type();
    shipping.get_shipping_cost();
    shipping.set_shipping_status(true);
    EXPECT_TRUE(true);
}

TEST(ShippingTests, Shipping_ConstructorComparison) {
    User user("��������� �������������");

    Shipping shippingWithParams(true, user);
    Shipping shippingDefault;
    EXPECT_TRUE(shippingWithParams.has_shipping_available());
    EXPECT_EQ(shippingWithParams.get_AssociatedUserName(), "��������� �������������");
    EXPECT_TRUE(shippingDefault.has_shipping_available());
    EXPECT_EQ(shippingDefault.get_AssociatedUserName(), "�����");
    EXPECT_EQ(shippingDefault.get_shipping_type(), "standard");
    EXPECT_DOUBLE_EQ(shippingDefault.get_shipping_cost(), 5.99);
}