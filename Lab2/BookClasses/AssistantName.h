/**
 * @file AssistantName.h
 * @brief ����� ��� ������ � ����������� �� �����������
 */

#ifndef ASSISTANTNAME_H
#define ASSISTANTNAME_H

#include "WorkExperience.h"
#include <string>
using namespace std;

/**
 * @class AssistantName
 * @brief ������������ ���������� �� ���������� � ������ ������
 */
class AssistantName {
private:
    string assistantname;           ///< ��� ����������
    WorkExperience associatedExperience; ///< ��������������� ���� ������
    string department;              ///< �����
    string shift_schedule;          ///< ������ ������

public:
    /**
     * @brief ����������� � �����������
     * @param name ��� ����������
     * @param experience ��������������� ���� ������
     */
    AssistantName(const string& name, const WorkExperience& experience);

    /**
     * @brief ����������� �� ���������
     */
    AssistantName();

    /**
     * @brief �������� ��� ����������
     * @return ��� ����������
     */
    string get_name() const;

    /**
     * @brief �������� ��������������� ���� ������
     * @return ���������� ��� �����
     */
    int get_AssociatedExperience();
};

#endif