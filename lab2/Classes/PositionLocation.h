/**
 * @file PositionLocation.h
 * @brief ����� ��� ������ � �������� �� �����
 */

#ifndef POSITIONLOCATION_H
#define POSITIONLOCATION_H

 /**
  * @class PositionLocation
  * @brief ������������ ������� ����� �� �����
  */
class PositionLocation {
private:
    int position; ///< ������� �� �����

public:
    /**
     * @brief ����������� � ����������
     * @param pos ������� �� �����
     */
    PositionLocation(int pos);

    /**
     * @brief ����������� �� ���������
     */
    PositionLocation();

    /**
     * @brief �������� ������� �� �����
     * @return ������� �� �����
     */
    int get_position();
};

#endif