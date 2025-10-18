/**
 * @file CustomerArrivalTime.h
 * @brief ����� ��� ������ � �������� �������� ��������
 */

#ifndef CUSTOMERARRIVALTIME_H
#define CUSTOMERARRIVALTIME_H

#include "User.h"
#include <string>
using namespace std;

/**
 * @class CustomerArrivalTime
 * @brief ������������ ���������� � ������� �������� ��������
 */
class CustomerArrivalTime {
private:
    string time;            ///< ����� ��������
    string day_of_week;     ///< ���� ������
    string date_day;        ///< ����
    string visit_purpose;   ///< ���� ������
    int visit_duration;     ///< ����������������� ������

public:
    /**
     * @brief ����������� � �����������
     * @param t ����� ��������
     * @param day ���� ������
     * @param dd ����
     * @param user ��������������� ������������
     */
    CustomerArrivalTime(const string& t, const string& day, const string& dd, const User& user);

    /**
     * @brief ����������� �� ���������
     */
    CustomerArrivalTime();

    /**
     * @brief �������� ����� ��������
     * @return ����� ��������
     */
    string get_time();

    /**
     * @brief �������� ���� ������
     * @return ���� ������
     */
    string get_day_w();

    /**
     * @brief �������� ����
     * @return ����
     */
    string get_day_d();
};

#endif