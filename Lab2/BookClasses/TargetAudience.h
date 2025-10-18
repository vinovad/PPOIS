/**
 * @file TargetAudience.h
 * @brief ����� ��� ������ � ������� ����������
 */

#ifndef TARGETAUDIENCE_H
#define TARGETAUDIENCE_H

#include "EducationLevel.h"
#include <string>
using namespace std;

/**
 * @class TargetAudience
 * @brief ������������ ������� ��������� ����� � ������� �����������
 */
class TargetAudience {
private:
    string audience_type;           ///< ��� ���������
    EducationLevel associatedEducationLevel; ///< ��������������� ������� �����������

public:
    /**
     * @brief ����������� � �����������
     * @param type ��� ���������
     * @param educationLevel ��������������� ������� �����������
     */
    TargetAudience(const string& type, const EducationLevel& educationLevel);

    /**
     * @brief ����������� �� ���������
     */
    TargetAudience();

    /**
     * @brief �������� ��� ���������
     * @return ��� ���������
     */
    string get_audience_type();

    /**
     * @brief �������� ��������������� ������� �����������
     * @return ������� �����������
     */
    string get_AssociatedEducationLevel();
};

#endif