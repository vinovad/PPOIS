/**
 * @file Cover_Format.h
 * @brief ����� ��� ������ � �������� ������� �����
 */

#ifndef COVER_FORMAT_H
#define COVER_FORMAT_H

#include "Publisher.h"
#include <string>
using namespace std;

/**
 * @class Cover_Format
 * @brief ������������ ������ ������� ����� � ����������� �� ��������
 */
class Cover_Format {
private:
    string format;              ///< ������ �������
    Publisher associatedPublisher; ///< ��������������� ��������

public:
    /**
     * @brief ����������� � �����������
     * @param f ������ �������
     * @param publisher ��������������� ��������
     */
    Cover_Format(const string& f, const Publisher& publisher);

    /**
     * @brief ����������� �� ���������
     */
    Cover_Format();

    /**
     * @brief �������� ������ �������
     * @return ������ �������
     */
    string get_format();

    /**
     * @brief �������� ���������������� ��������
     * @return �������� ��������
     */
    string get_AssociatedPublisher();

    /**
     * @brief ���������� ������ �������
     * @param f ����� ������ �������
     */
    void set_format(string f);
};

#endif