/**
 * @file BookFormat.h
 * @brief ����� ��� ������ � �������� �����
 */

#ifndef BOOKFORMAT_H
#define BOOKFORMAT_H

#include "PageCount.h"
#include <string>
using namespace std;

/**
 * @class BookFormat
 * @brief ������������ ������ ����� � ����������� � ���������
 */
class BookFormat {
private:
    string bookformat;          ///< ������ �����
    PageCount associatedPageCount; ///< ��������������� ���������� � ���������

public:
    /**
     * @brief ����������� � �����������
     * @param bf ������ �����
     * @param pageCount ��������������� ���������� � ���������
     */
    BookFormat(const string& bf, const PageCount& pageCount);

    /**
     * @brief ����������� �� ���������
     */
    BookFormat();

    /**
     * @brief �������� ������ �����
     * @return ������ �����
     */
    string get_bookformat();

    /**
     * @brief �������� ���������� ��������������� �������
     * @return ���������� �������
     */
    int get_AssociatedPageCount();
};

#endif