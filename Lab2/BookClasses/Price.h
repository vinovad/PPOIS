/**
 * @file Price.h
 * @brief ����� ��� ������ � ����� �����
 */

#ifndef PRICE_H
#define PRICE_H

#include "Sale.h"
#include <string>
using namespace std;

/**
 * @class Price
 * @brief ������������ ���� ����� � ����������� � ������, ������� � ��������
 */
class Price {
private:
    double price;           ///< ���� �����
    string currency;        ///< ������
    Sale associatedSale;    ///< ��������������� ���������� � �������
    double tax_amount;      ///< ����� ������
    double shipping_cost;   ///< ��������� ��������

public:
    /**
     * @brief ����������� � �����������
     * @param p ���� �����
     * @param curr ������
     * @param sale ��������������� ���������� � �������
     */
    Price(double p, const string& curr, const Sale& sale);

    /**
     * @brief ����������� �� ���������
     */
    Price();

    /**
     * @brief �������� ���� �����
     * @return ���� �����
     */
    double get_price();

    /**
     * @brief �������� ������
     * @return ������
     */
    string get_currency();

    /**
     * @brief �������� ��������������� ������
     * @return ������� ������
     */
    double get_AssociatedDiscount();

    /**
     * @brief �������� ������ ��������������� �������
     * @return ������ �������
     */
    string get_AssociatedSalePeriod();
};

#endif