/**
 * @file PurchasedBook.h
 * @brief ����� ��� ������ � ����������� � �������� ����
 */

#ifndef PURCHASEDBOOK_H
#define PURCHASEDBOOK_H

#include <string>
using namespace std;

/**
 * @class PurchasedBook
 * @brief ������������ ���������� � ��������� �����
 */
class PurchasedBook {
private:
    string book_title;      ///< �������� �����
    string purchase_date;   ///< ���� �������
    double purchase_price;  ///< ���� �������
    string user_name;       ///< ��� ������������

public:
    /**
     * @brief ����������� � �����������
     * @param title �������� �����
     * @param date ���� �������
     * @param price ���� �������
     * @param user ��� ������������
     */
    PurchasedBook(const string& title, const string& date, double price, const string& user);

    /**
     * @brief ����������� �� ���������
     */
    PurchasedBook();

    /**
     * @brief �������� �������� �����
     * @return �������� �����
     */
    string get_book_title();

    /**
     * @brief �������� ���� �������
     * @return ���� �������
     */
    string get_purchase_date();

    /**
     * @brief �������� ���� �������
     * @return ���� �������
     */
    double get_purchase_price();

    /**
     * @brief �������� ��� ������������
     * @return ��� ������������
     */
    string get_user_name();

    /**
     * @brief ���������� ���������� � �������
     */
    void display_purchase_info();
};

#endif