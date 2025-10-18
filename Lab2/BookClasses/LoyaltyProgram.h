/**
 * @file LoyaltyProgram.h
 * @brief ����� ��� ������ � ���������� ����������
 */

#ifndef LOYALTYPROGRAM_H
#define LOYALTYPROGRAM_H

#include "User.h"

 /**
  * @class LoyaltyProgram
  * @brief ������������ ��������� ���������� ��� �������������
  */
class LoyaltyProgram {
private:
    User associatedUser;        ///< ��������������� ������������
    double discount_percentage; ///< ������� ������
    bool has_user;              ///< ������� �������������� ������������

public:
    /**
     * @brief ����������� � ����������
     * @param user_obj ��������������� ������������
     */
    LoyaltyProgram(const User& user_obj);

    /**
     * @brief ����������� �� ���������
     */
    LoyaltyProgram();

    /**
     * @brief �������� ������ �� ������ ���������� ������������
     */
    void update_discount();

    /**
     * @brief �������� ������� ������
     * @return ������� ������
     */
    double get_discount();

    /**
     * @brief ��������� ������ � ����
     * @param original_price �������� ����
     * @return ���� �� �������
     */
    double apply_discount(double original_price);

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
     * @brief ���������� ������������
     * @param user_obj ������������
     */
    void set_user(const User& user_obj);

    /**
     * @brief ���������, ���������� �� ������������
     * @return true ���� ������������ ����������, false � ��������� ������
     */
    bool has_user_set() const;
};

#endif