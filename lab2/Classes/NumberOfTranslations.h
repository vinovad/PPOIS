/**
 * @file NumberOfTranslations.h
 * @brief ����� ��� ������ � ����������� ��������� �����
 */

#ifndef NUMBEROFTRANSLATIONS_H
#define NUMBEROFTRANSLATIONS_H

#include "Language.h"

 /**
  * @class NumberOfTranslations
  * @brief ������������ ���������� ��������� ����� �� ������ �����
  */
class NumberOfTranslations {
private:
    int number_translations;    ///< ���������� ���������
    Language associatedLanguage; ///< ��������������� ����

public:
    /**
     * @brief ����������� � �����������
     * @param tran ���������� ���������
     * @param language ��������������� ����
     */
    NumberOfTranslations(int tran, const Language& language);

    /**
     * @brief ����������� �� ���������
     */
    NumberOfTranslations();

    /**
     * @brief �������� ���������� ���������
     * @return ���������� ���������
     */
    int get_number_translations();

    /**
     * @brief �������� ��������������� ����
     * @return ����
     */
    string get_AssociatedLanguage();
};

#endif