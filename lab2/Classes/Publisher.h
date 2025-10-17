/**
 * @file Publisher.h
 * @brief ����� ��� ������ � ��������� �����
 */

#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>
using namespace std;

/**
 * @class Publisher
 * @brief ������������ �������� ����� � �������������� �����������
 */
class Publisher {
private:
    string publisher;           ///< �������� ������������
    string founder;             ///< ����������
    int foundation_year;        ///< ��� ���������
    string headquarters;        ///< �������������� ����-��������

public:
    /**
     * @brief ����������� � ����������
     * @param p �������� ������������
     */
    Publisher(const string& p);

    /**
     * @brief ����������� �� ���������
     */
    Publisher();

    /**
     * @brief �������� �������� ������������
     * @return �������� ������������
     */
    string get_publisher();

    /**
     * @brief ���������� �������� ������������
     * @param p ����� �������� ������������
     */
    void set_publisher(string p);
};

#endif