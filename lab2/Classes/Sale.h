/**
 * @file Sale.h
 * @brief ����� ��� ������ � ����������� � �������� � �������
 */

#ifndef SALE_H
#define SALE_H

#include <string>
using namespace std;

/**
 * @class Sale
 * @brief ������������ ���������� � ��������, ������� � ������
 */
class Sale {
private:
    double discount_percentage; ///< ������� ������
    string sale_period;         ///< ������ �������
    string promotion_code;      ///< ��������
    int max_uses;               ///< ������������ ���������� �������������

public:
    /**
     * @brief ����������� � �����������
     * @param discount ������� ������
     * @param period ������ �������
     */
    Sale(double discount, const string& period);

    /**
     * @brief ����������� �� ���������
     */
    Sale();

    /**
     * @brief �������� ������� ������
     * @return ������� ������
     */
    double get_discount();

    /**
     * @brief �������� ������ �������
     * @return ������ �������
     */
    string get_sale_period();
};

#endif