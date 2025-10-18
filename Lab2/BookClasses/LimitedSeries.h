/**
 * @file LimitedSeries.h
 * @brief ����� ��� ������ � ������������� ������� ����
 */

#ifndef LIMITEDSERIES_H
#define LIMITEDSERIES_H

#include "BookVolumeCount.h"

 /**
  * @class LimitedSeries
  * @brief ������������ ���������� �� ������������ ������ ����
  */
class LimitedSeries {
private:
    bool is_limited;                    ///< �������� �� ����� ������������
    BookVolumeCount associatedVolumeCount; ///< ��������������� ���������� �����

public:
    /**
     * @brief ����������� � �����������
     * @param limited ������ ������������ �����
     * @param volumeCount ��������������� ���������� �����
     */
    LimitedSeries(bool limited, const BookVolumeCount& volumeCount);

    /**
     * @brief ����������� �� ���������
     */
    LimitedSeries();

    /**
     * @brief ���������, �������� �� ����� ������������
     * @return true ���� ����� ������������, false � ��������� ������
     */
    bool is_limited_edition();

    /**
     * @brief �������� ��������������� ���������� �����
     * @return ���������� �����
     */
    int get_AssociatedVolumeCount();
};

#endif