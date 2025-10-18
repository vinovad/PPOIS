/**
 * @file AgeRestriction.h
 * @brief ����� ��� ������ � ����������� �������������
 */

#ifndef AGERESTRICTION_H
#define AGERESTRICTION_H

#include "TargetAudience.h"
#include "User.h"

 /**
  * @class AgeRestriction
  * @brief ������������ ���������� ����������� ��� ����� � ����������� � ������� ��������� � ������������
  */
class AgeRestriction {
private:
    int age_restriction;            ///< ���������� �����������
    TargetAudience associatedAudience; ///< ��������������� ������� ���������
    User associatedUser;            ///< ��������������� ������������

public:
    /**
     * @brief ����������� � �����������
     * @param age ���������� �����������
     * @param audience ��������������� ������� ���������
     * @param user ��������������� ������������
     */
    AgeRestriction(int age, const TargetAudience& audience, const User& user);

    /**
     * @brief ����������� �� ���������
     */
    AgeRestriction();

    /**
     * @brief �������� ���������� �����������
     * @return ���������� �����������
     */
    int get_age_restriction();

    /**
     * @brief �������� ��������������� ������� ���������
     * @return ��� ���������
     */
    string get_AssociatedAudience();

    /**
     * @brief �������� ������� ����������� ��������������� ���������
     * @return ������� �����������
     */
    string get_AssociatedAudienceEducation();

    /**
     * @brief �������� ��� ���������������� ������������
     * @return ��� ������������
     */
    string get_AssociatedUserName();

    /**
     * @brief �������� ���������� ���� ���������������� ������������
     * @return ���������� ����
     */
    int get_AssociatedUserBooks();

    /**
     * @brief ���������� ���������� �����������
     * @param v ����� ���������� �����������
     */
    void set_age_restriction(int v);
};

#endif