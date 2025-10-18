/**
 * @file PersonalOpinion.h
 * @brief ����� ��� ������ � ������� �������� � ������
 */

#ifndef PERSONALOPINION_H
#define PERSONALOPINION_H

#include "NumberOfPeople.h"
#include <string>
using namespace std;

/**
 * @class PersonalOpinion
 * @brief ������������ ������ ������ � ����� � ����������� � ���������� �����
 */
class PersonalOpinion {
private:
    string opinion;                 ///< ����� ������
    NumberOfPeople associatedPeople; ///< ��������������� ���������� �����
    int recommendation_score;       ///< ������ ������������
    string opinion_date;            ///< ���� ������

public:
    /**
     * @brief ����������� � �����������
     * @param op ����� ������
     * @param people ��������������� ���������� �����
     */
    PersonalOpinion(const string& op, const NumberOfPeople& people);

    /**
     * @brief ����������� �� ���������
     */
    PersonalOpinion();

    /**
     * @brief �������� ����� ������
     * @return ����� ������
     */
    string get_opinion();

    /**
     * @brief �������� ��������������� ���������� �����
     * @return ���������� �����
     */
    int get_AssociatedPeople();
};

#endif