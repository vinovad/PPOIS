/**
 * @file Prohibited.h
 * @brief ����� ��� ������ � ����������� � ������� �����
 */

#ifndef PROHIBITED_H
#define PROHIBITED_H

#include "Country.h"

 /**
  * @class Prohibited
  * @brief ������������ ���������� � ������� ����� � ������������ ������
  */
class Prohibited {
private:
    bool is_prohibited;        ///< ������ �������
    Country associatedCountry; ///< ��������������� ������

public:
    /**
     * @brief ����������� � �����������
     * @param prohibited ������ �������
     * @param country ��������������� ������
     */
    Prohibited(bool prohibited, const Country& country);

    /**
     * @brief ����������� �� ���������
     */
    Prohibited();

    /**
     * @brief �������� ������ �������
     * @return true ���� ����� ���������, false � ��������� ������
     */
    bool get_is_prohibited();

    /**
     * @brief �������� ��������������� ������
     * @return �������� ������
     */
    string get_AssociatedCountry();
};

#endif