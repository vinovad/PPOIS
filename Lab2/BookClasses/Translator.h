/**
 * @file Translator.h
 * @brief ����� ��� ������ � ������������ �����
 */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "NumberOfTranslations.h"
#include <string>
using namespace std;

/**
 * @class Translator
 * @brief ������������ ����������� �����
 */
class Translator {
private:
    string translator;                      ///< ��� �����������
    NumberOfTranslations associatedTranslations; ///< ��������������� ��������

public:
    /**
     * @brief ����������� � �����������
     * @param tr ��� �����������
     * @param translations ��������������� ��������
     */
    Translator(const string& tr, const NumberOfTranslations& translations);

    /**
     * @brief ����������� �� ���������
     */
    Translator();

    /**
     * @brief �������� ��� �����������
     * @return ��� �����������
     */
    string get_translator();

    /**
     * @brief �������� ���������� ��������������� ���������
     * @return ���������� ���������
     */
    int get_AssociatedTranslations();
};

#endif