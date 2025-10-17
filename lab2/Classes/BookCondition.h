/**
 * @file BookCondition.h
 * @brief ����� ��� ������ � ���������� �����
 */

#ifndef BOOKCONDITION_H
#define BOOKCONDITION_H

#include <string>
using namespace std;

/**
 * @class BookCondition
 * @brief ������������ ���������� � ��������� �����
 */
class BookCondition {
private:
    string condition;           ///< ��������� �����
    int wear_level;             ///< ������� ������
    string damage_description;  ///< �������� �����������

public:
    /**
     * @brief ����������� � ����������
     * @param cond ��������� �����
     */
    BookCondition(const string& cond);

    /**
     * @brief ����������� �� ���������
     */
    BookCondition();

    /**
     * @brief �������� ��������� �����
     * @return ��������� �����
     */
    string get_condition();
};

#endif