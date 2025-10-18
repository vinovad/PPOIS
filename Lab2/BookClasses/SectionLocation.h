/**
 * @file SectionLocation.h
 * @brief ����� ��� ������ � ������������� � ������
 */

#ifndef SECTIONLOCATION_H
#define SECTIONLOCATION_H

#include "ShelfLocation.h"
#include <string>
using namespace std;

/**
 * @class SectionLocation
 * @brief ������������ ������������ ����� � ������ ����������
 */
class SectionLocation {
private:
    string section;             ///< �������� ������
    ShelfLocation associatedShelf; ///< ��������������� �����

public:
    /**
     * @brief ����������� � �����������
     * @param sec �������� ������
     * @param shelf ��������������� �����
     */
    SectionLocation(const string& sec, const ShelfLocation& shelf);

    /**
     * @brief ����������� � ����� ����������
     * @param sec �������� ������
     */
    SectionLocation(const string& sec);

    /**
     * @brief ����������� �� ���������
     */
    SectionLocation();

    /**
     * @brief �������� �������� ������
     * @return �������� ������
     */
    string get_section();

    /**
     * @brief �������� ��������������� �����
     * @return �������� �����
     */
    string get_AssociatedShelf();
};

#endif