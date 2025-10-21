/**
 * @file Shipping.h
 * @brief ����� ��� ������ � ����������� � �������� ����
 */

#ifndef SHIPPING_H
#define SHIPPING_H

#include "User.h"
#include <string>
using namespace std;

/**
 * @class Shipping
 * @brief ������������ ���������� � ����������� �������� ��� ������������
 */
class Shipping {
private:
    bool has_shipping;          ///< ������� ��������
    User associatedUser;        ///< ��������������� ������������
    string shipping_type;       ///< ��� ��������
    double shipping_cost;       ///< ��������� ��������

public:
    /**
     * @brief ����������� � �����������
     * @param shipping ������ ��������
     * @param user ��������������� ������������
     */
    Shipping(bool shipping, const User& user);

    /**
     * @brief ����������� �� ���������
     */
    Shipping();

    /**
     * @brief ��������� ������� ��������
     * @return true ���� �������� ��������, false � ��������� ������
     */
    bool has_shipping_available();

    /**
     * @brief �������� ��� ���������������� ������������
     * @return ��� ������������
     */
    string get_AssociatedUserName();

    /**
     * @brief �������� ��� ��������
     * @return ��� ��������
     */
    string get_shipping_type();

    /**
     * @brief �������� ��������� ��������
     * @return ��������� ��������
     */
    double get_shipping_cost();

    /**
     * @brief ���������� ������ ��������
     * @param shipping ����� ������ ��������
     */
    void set_shipping_status(bool shipping);
};

#endif