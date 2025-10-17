/**
 * @file Country.h
 * @brief ����� ��� ������ �� ������� �������
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

/**
 * @class Country
 * @brief ������������ ������ ������� �����
 */
class Country {
private:
    string country; ///< �������� ������

public:
    /**
     * @brief ����������� � ����������
     * @param c �������� ������
     */
    Country(const string& c);

    /**
     * @brief ����������� �� ���������
     */
    Country();

    /**
     * @brief �������� �������� ������
     * @return �������� ������
     */
    string get_country();
};

#endif