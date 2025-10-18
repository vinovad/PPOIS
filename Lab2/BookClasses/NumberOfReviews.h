/**
 * @file NumberOfReviews.h
 * @brief ����� ��� ������ � ����������� �������
 */

#ifndef NUMBEROFREVIEWS_H
#define NUMBEROFREVIEWS_H

#include "Reviews.h"

 /**
  * @class NumberOfReviews
  * @brief ������������ ���������� ������� � �����
  */
class NumberOfReviews {
private:
    int number_reviews;         ///< ���������� �������
    Reviews associatedReviews;  ///< ��������������� �����
    int positive_reviews;       ///< ���������� ������������� �������
    int negative_reviews;       ///< ���������� ������������� �������

public:
    /**
     * @brief ����������� � �����������
     * @param nr ���������� �������
     * @param reviews ��������������� �����
     */
    NumberOfReviews(int nr, const Reviews& reviews);

    /**
     * @brief ����������� �� ���������
     */
    NumberOfReviews();

    /**
     * @brief �������� ���������� �������
     * @return ���������� �������
     */
    int get_number_reviews();

    /**
     * @brief �������� ��������������� �����
     * @return ����� ������
     */
    string get_AssociatedReviews();
};

#endif