/**
 * @file ExportCountry.h
 * @brief ����� ��� ������ �� ������� �������� �����
 */

#ifndef EXPORTCOUNTRY_H
#define EXPORTCOUNTRY_H

#include "Prohibited.h"
#include <string>
using namespace std;

/**
 * @class ExportCountry
 * @brief ������������ ������ �������� ����� � ����������� � ��������
 */
class ExportCountry {
private:
    string export_country;      ///< ������ ��������
    Prohibited associatedProhibited; ///< ��������������� ���������� � �������

public:
    /**
     * @brief ����������� � �����������
     * @param country2 ������ ��������
     * @param prohibited ��������������� ���������� � �������
     */
    ExportCountry(const string& country2, const Prohibited& prohibited);

    /**
     * @brief ����������� �� ���������
     */
    ExportCountry();

    /**
     * @brief �������� ������ ��������
     * @return ������ ��������
     */
    string get_export_country();

    /**
     * @brief �������� ������ ������� ��������
     * @return true ���� ������� ��������, false � ��������� ������
     */
    bool get_AssociatedProhibitedStatus();

    /**
     * @brief �������� ������ ���������������� �������
     * @return �������� ������ �������
     */
    string get_AssociatedProhibitedCountry();
};

#endif