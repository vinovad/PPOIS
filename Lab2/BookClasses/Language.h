/**
 * @file Language.h
 * @brief ����� ��� ������ � ������ �����
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>
using namespace std;

/**
 * @class Language
 * @brief ������������ ���� �����
 */
class Language {
private:
    string language; ///< ���� �����

public:
    /**
     * @brief ����������� � ����������
     * @param l ���� �����
     */
    Language(const string& l);

    /**
     * @brief ����������� �� ���������
     */
    Language();

    /**
     * @brief �������� ���� �����
     * @return ���� �����
     */
    string get_language();

    /**
     * @brief ���������� ���� �����
     * @param l ����� ���� �����
     */
    void set_language(string l);
};

#endif