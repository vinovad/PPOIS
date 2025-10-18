/**
 * @file BookWeight.h
 * @brief ����� ��� ������ � ����� �����
 */

#ifndef BOOKWEIGHT_H
#define BOOKWEIGHT_H

#include "BookFormat.h"

 /**
  * @class BookWeight
  * @brief ������������ ��� ����� � ��������� ����������
  */
class BookWeight {
private:
    double weight;              ///< ��� �����
    double shipping_weight;     ///< ��� ��� ��������
    string weight_category;     ///< ��������� ����
    BookFormat associatedFormat; ///< ��������������� ������

public:
    /**
     * @brief ����������� � �����������
     * @param w ��� �����
     * @param format ��������������� ������
     */
    BookWeight(double w, const BookFormat& format);

    /**
     * @brief ����������� �� ���������
     */
    BookWeight();

    /**
     * @brief �������� ��� �����
     * @return ��� �����
     */
    double get_weight();

    /**
     * @brief �������� ��������������� ������
     * @return ������ �����
     */
    string get_AssociatedFormat();
};

#endif