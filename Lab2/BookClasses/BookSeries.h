/**
 * @file BookSeries.h
 * @brief ����� ��� ������ � ������� ����
 */

#ifndef BOOKSERIES_H
#define BOOKSERIES_H

#include <string>
using namespace std;

/**
 * @class BookSeries
 * @brief ������������ ���������� � ����� ����
 */
class BookSeries {
private:
    string series_name;     ///< �������� �����
    int volume_number;      ///< ����� ���� � �����

public:
    /**
     * @brief ����������� � ����������
     * @param name �������� �����
     */
    BookSeries(const string& name);

    /**
     * @brief ����������� �� ���������
     */
    BookSeries();

    /**
     * @brief �������� �������� �����
     * @return �������� �����
     */
    string get_series_name();
};

#endif