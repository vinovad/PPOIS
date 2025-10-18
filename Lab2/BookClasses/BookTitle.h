/**
 * @file BookTitle.h
 * @brief ����� ��� ������ � ��������� �����
 */

#ifndef BOOKTITLE_H
#define BOOKTITLE_H

#include <string>
using namespace std;

/**
 * @class BookTitle
 * @brief ������������ �������� ����� � ��������� ����������
 */
class BookTitle {
private:
    string title_book;          ///< �������� �����
    string original_title;      ///< ������������ ��������
    string subtitle;            ///< ������������

public:
    /**
     * @brief ����������� � ����������
     * @param title �������� �����
     */
    BookTitle(const string& title);

    /**
     * @brief ����������� �� ���������
     */
    BookTitle();

    /**
     * @brief �������� �������� �����
     * @return �������� �����
     */
    string get_Book();

    /**
     * @brief ���������� �������� �����
     * @param tb ����� �������� �����
     */
    void set_Book(string tb);
};

#endif