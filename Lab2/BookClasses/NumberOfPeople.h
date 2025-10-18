/**
 * @file NumberOfPeople.h
 * @brief ����� ��� ������ � ����������� �����
 */

#ifndef NUMBEROFPEOPLE_H
#define NUMBEROFPEOPLE_H

#include "User.h"

 /**
  * @class NumberOfPeople
  * @brief ������������ ���������� ����� � ��������������� �������������
  */
class NumberOfPeople {
private:
    int number_people;      ///< ���������� �����
    User associatedUser;    ///< ��������������� ������������

public:
    /**
     * @brief ����������� � �����������
     * @param people ���������� �����
     * @param user ��������������� ������������
     */
    NumberOfPeople(int people, const User& user);

    /**
     * @brief ����������� �� ���������
     */
    NumberOfPeople();

    /**
     * @brief �������� ���������� �����
     * @return ���������� �����
     */
    int get_number_people();

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
};

#endif