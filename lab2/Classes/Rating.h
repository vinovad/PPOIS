/**
 * @file Rating.h
 * @brief ����� ��� ������ � ��������� �����
 */

#ifndef RATING_H
#define RATING_H

 /**
  * @class Rating
  * @brief ������������ ������� ����� � ���������� ������
  */
class Rating {
private:
    double rating;          ///< ������� �������
    int number_of_votes;    ///< ���������� �������
    double average_rating;  ///< ������� �������

public:
    /**
     * @brief ����������� � ����������
     * @param r ��������� �������
     */
    Rating(double r);

    /**
     * @brief ����������� �� ���������
     */
    Rating();

    /**
     * @brief �������� ������� �������
     * @return ������� �������
     */
    double get_rating();

    /**
     * @brief ���������� �������
     * @param r ����� �������
     */
    void set_rating(double r);
};

#endif