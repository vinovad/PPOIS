/**
 * @file User.h
 * @brief ����� ��� ������ � �������������� �������
 */

#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

/**
 * @class User
 * @brief ������������ ������������ ������� � ����������� � ��������
 */
class User {
private:
    string name;                ///< ��� ������������
    int books_bought;           ///< ���������� ��������� ����
    string email;               ///< Email ������������
    string phone_number;        ///< ����� ��������
    string registration_date;   ///< ���� �����������
    string address;             ///< �����
    int loyalty_points;         ///< ����� ����������

public:
    /**
     * @brief ����������� � ����������
     * @param user_name ��� ������������
     */
    User(const string& user_name);

    /**
     * @brief ����������� �� ���������
     */
    User();

    /**
     * @brief �������� ��� ������������
     * @return ��� ������������
     */
    string get_name();

    /**
     * @brief �������� ���������� ��������� ����
     * @return ���������� ��������� ����
     */
    int get_books_bought();

    /**
     * @brief �������� ��������� �����
     */
    void add_purchased_book();
};

#endif