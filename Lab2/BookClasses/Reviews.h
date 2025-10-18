/**
 * @file Reviews.h
 * @brief ����� ��� ������ � �������� � ������
 */

#ifndef REVIEWS_H
#define REVIEWS_H

#include <string>
using namespace std;

/**
 * @class Reviews
 * @brief ������������ ����� � ����� � �������������� �����������
 */
class Reviews {
private:
    string reviews;         ///< ����� ������
    int helpful_votes;      ///< ���������� �������� �������
    string review_date;     ///< ���� ������

public:
    /**
     * @brief ����������� � ����������
     * @param rev ����� ������
     */
    Reviews(const string& rev);

    /**
     * @brief ����������� �� ���������
     */
    Reviews();

    /**
     * @brief �������� ����� ������
     * @return ����� ������
     */
    string get_reviews();
};

#endif