/**
 * @file ArrivalDate.h
 * @brief ����� ��� ������ � ������ ����������� ����
 */

#ifndef ARRIVALDATE_H
#define ARRIVALDATE_H

#include <string>
using namespace std;

/**
 * @class ArrivalDate
 * @brief ������������ ���������� � ����� ����������� � ���������� ����
 */
class ArrivalDate {
private:
    string date;            ///< ����������� ���� �����������
    string expected_date;   ///< ��������� ���� �����������
    string restock_date;    ///< ���� ���������� �������

public:
    /**
     * @brief ����������� � ����������
     * @param d ���� �����������
     */
    ArrivalDate(const string& d);

    /**
     * @brief ����������� �� ���������
     */
    ArrivalDate();

    /**
     * @brief �������� ���� �����������
     * @return ���� �����������
     */
    string get_arrival_date();
};

#endif