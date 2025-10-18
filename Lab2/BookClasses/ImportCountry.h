/**
 * @file ImportCountry.h
 * @brief ����� ��� ������ �� ������� ������� �����
 */

#ifndef IMPORTCOUNTRY_H
#define IMPORTCOUNTRY_H

#include "Prohibited.h"
#include <string>
using namespace std;

/**
 * @class ImportCountry
 * @brief ������������ ������ ������� ����� � ����������� � ��������
 */
class ImportCountry {
private:
    string import_country;      ///< ������ �������
    Prohibited associatedProhibited; ///< ��������������� ���������� � �������

public:
    /**
     * @brief ����������� � �����������
     * @param country ������ �������
     * @param prohibited ��������������� ���������� � �������
     */
    ImportCountry(const string& country, const Prohibited& prohibited);

    /**
     * @brief ����������� �� ���������
     */
    ImportCountry();

    /**
     * @brief �������� ������ �������
     * @return ������ �������
     */
    string get_import_country();

    /**
     * @brief �������� ������ ������� �������
     * @return true ���� ������ ��������, false � ��������� ������
     */
    bool get_AssociatedProhibitedStatus();

    /**
     * @brief �������� ������ ���������������� �������
     * @return �������� ������ �������
     */
    string get_AssociatedProhibitedCountry();
};

#endif