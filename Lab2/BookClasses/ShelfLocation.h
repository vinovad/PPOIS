/**
 * @file ShelfLocation.h
 * @brief ����� ��� ������ � ������������� �� �����
 */

#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H

#include "PositionLocation.h"
#include <string>
using namespace std;

/**
 * @class ShelfLocation
 * @brief ������������ ������������ ����� �� �����
 */
class ShelfLocation {
private:
    string shelf;                   ///< �������� �����
    PositionLocation associatedPosition; ///< ��������������� �������

public:
    /**
     * @brief ����������� � �����������
     * @param sh �������� �����
     * @param position ��������������� �������
     */
    ShelfLocation(const string& sh, const PositionLocation& position);

    /**
     * @brief ����������� �� ���������
     */
    ShelfLocation();

    /**
     * @brief �������� �������� �����
     * @return �������� �����
     */
    string get_shelf();

    /**
     * @brief �������� ��������������� �������
     * @return ������� �� �����
     */
    int get_AssociatedPosition();
};

#endif