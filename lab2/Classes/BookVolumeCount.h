/**
 * @file BookVolumeCount.h
 * @brief ����� ��� ������ � ����������� ����� � �����
 */

#ifndef BOOKVOLUMECOUNT_H
#define BOOKVOLUMECOUNT_H

#include "BookSeries.h"

 /**
  * @class BookVolumeCount
  * @brief ������������ ���������� ����� � ����� ����
  */
class BookVolumeCount {
private:
    int volume_number;          ///< ����� ����
    BookSeries associatedSeries; ///< ��������������� �����

public:
    /**
     * @brief ����������� � �����������
     * @param volume ����� ����
     * @param series ��������������� �����
     */
    BookVolumeCount(int volume, const BookSeries& series);

    /**
     * @brief ����������� �� ���������
     */
    BookVolumeCount();

    /**
     * @brief �������� ����� ����
     * @return ����� ����
     */
    int get_volume_number();

    /**
     * @brief �������� ��������������� �����
     * @return �������� �����
     */
    string get_AssociatedSeries();
};

#endif