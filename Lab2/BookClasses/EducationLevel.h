/**
 * @file EducationLevel.h
 * @brief ����� ��� ������ � �������� �����������
 */

#ifndef EDUCATIONLEVEL_H
#define EDUCATIONLEVEL_H

#include <string>
using namespace std;

/**
 * @class EducationLevel
 * @brief ������������ ������� ����������� ������� ���������
 */
class EducationLevel {
private:
    string level; ///< ������� �����������

public:
    /**
     * @brief ����������� � ����������
     * @param lvl ������� �����������
     */
    EducationLevel(const string& lvl);

    /**
     * @brief ����������� �� ���������
     */
    EducationLevel();

    /**
     * @brief �������� ������� �����������
     * @return ������� �����������
     */
    string get_education_level();
};

#endif