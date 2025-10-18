/**
 * @file HollLocation.h
 * @brief ����� ��� ������ � ������������� � ����
 */

#ifndef HOLLLOCATION_H
#define HOLLLOCATION_H

#include "SectionLocation.h"

 /**
  * @class HollLocation
  * @brief ������������ ������������ ����� � ���� ����������
  */
class HollLocation {
private:
    int holl;                   ///< ����� ����
    SectionLocation associatedSection; ///< ��������������� ������

public:
    /**
     * @brief ����������� � �����������
     * @param h ����� ����
     * @param section ��������������� ������
     */
    HollLocation(int h, const SectionLocation& section);

    /**
     * @brief ����������� �� ���������
     */
    HollLocation();

    /**
     * @brief �������� ����� ����
     * @return ����� ����
     */
    int get_holl();

    /**
     * @brief �������� ��������������� ������
     * @return �������� ������
     */
    string get_AssociatedSection();
};

#endif