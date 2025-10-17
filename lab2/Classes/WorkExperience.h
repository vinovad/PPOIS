/**
 * @file WorkExperience.h
 * @brief ����� ��� ������ � ������ ������
 */

#ifndef WORKEXPERIENCE_H
#define WORKEXPERIENCE_H

#include <string>
using namespace std;

/**
 * @class WorkExperience
 * @brief ������������ ���� ������ ����������
 */
class WorkExperience {
private:
    int years_of_experience;    ///< ���������� ��� �����
    string previous_companies;  ///< ���������� ��������
    string specialization;      ///< �������������

public:
    /**
     * @brief ����������� � ����������
     * @param experience ���������� ��� �����
     */
    WorkExperience(int experience);

    /**
     * @brief ����������� �� ���������
     */
    WorkExperience();

    /**
     * @brief �������� ���������� ��� �����
     * @return ���������� ��� �����
     */
    int get_years_of_experience() const;
};

#endif