/**
 * @file YearOfManufacture.h
 * @brief ����� ��� ������ � ����� ������� �����
 */

#ifndef YEAROFMANUFACTURE_H
#define YEAROFMANUFACTURE_H

#include <string>
using namespace std;

/**
 * @class YearOfManufacture
 * @brief ������������ ��� ������� �����
 */
class YearOfManufacture {
private:
    int year; ///< ��� �������

public:
    /**
     * @brief ����������� � ����������
     * @param y ��� �������
     */
    YearOfManufacture(int y);

    /**
     * @brief ����������� �� ���������
     */
    YearOfManufacture();

    /**
     * @brief �������� ��� �������
     * @return ��� �������
     */
    int get_Year();

    /**
     * @brief ���������� ��� ������� (����� �����)
     * @param y ����� ��� �������
     */
    void set_Year(int y);

    /**
     * @brief ���������� ��� ������� (������)
     * @param g ��� ������� � ���� ������
     */
    void set_Year(string g);
};

#endif