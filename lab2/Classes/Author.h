/**
 * @file Author.h
 * @brief ����� ��� ������ � ������� �����
 */

#ifndef AUTHOR_H
#define AUTHOR_H

#include "Country.h"
#include "Language.h"
#include <string>
using namespace std;

/**
 * @class Author
 * @brief ������������ ������ ����� � �������������� �����������
 */
class Author {
private:
    string name;                    ///< ��� ������
    string birth_year;              ///< ��� ��������
    int books_written;              ///< ���������� ���������� ����
    Country associatedCountry;      ///< ��������������� ������
    Language associatedLanguage;    ///< ��������������� ����
    string pseudonym;               ///< ���������
    string nationality;             ///< ��������������
    string awards;                  ///< �������
    string education;               ///< �����������

public:
    /**
     * @brief ����������� � �����������
     * @param n ��� ������
     * @param by ��� ��������
     * @param bw ���������� ���������� ����
     * @param country ��������������� ������
     * @param language ��������������� ����
     */
    Author(const string& n, const string& by, int bw, const Country& country, const Language& language);

    /**
     * @brief ����������� �� ���������
     */
    Author();

    /**
     * @brief �������� ��� ������
     * @return ��� ������
     */
    string get_Author();

    /**
     * @brief �������� ��� ��������
     * @return ��� ��������
     */
    string get_birth();

    /**
     * @brief �������� ���������� ����
     * @return ���������� ���������� ����
     */
    int get_books();

    /**
     * @brief �������� ��������������� ������
     * @return �������� ������
     */
    string get_AssociatedCountry();

    /**
     * @brief �������� ��������������� ����
     * @return ����
     */
    string get_AssociatedLanguage();

    /**
     * @brief ���������� ��� ��������
     * @param by ��� ��������
     */
    void set_birth(int by);

    /**
     * @brief ���������� ���������� ����
     * @param bw ���������� ���������� ����
     */
    void set_books(int bw);
};

#endif