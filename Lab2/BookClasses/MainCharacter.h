/**
 * @file MainCharacter.h
 * @brief ����� ��� ������ � �������� ����������� ����
 */

#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include "BookVolumeCount.h"
#include <string>
using namespace std;

/**
 * @class MainCharacter
 * @brief ������������ �������� ��������� �����
 */
class MainCharacter {
private:
    string name_character;          ///< ��� ���������
    BookVolumeCount associatedVolumeCount; ///< ��������������� ���������� �����

public:
    /**
     * @brief ����������� � �����������
     * @param nc ��� ���������
     * @param volumeCount ��������������� ���������� �����
     */
    MainCharacter(const string& nc, const BookVolumeCount& volumeCount);

    /**
     * @brief ����������� �� ���������
     */
    MainCharacter();

    /**
     * @brief �������� ��� ���������
     * @return ��� ���������
     */
    string get_character();

    /**
     * @brief �������� ��������������� ���������� �����
     * @return ���������� �����
     */
    int get_AssociatedVolumeCount();

    /**
     * @brief �������� ��������������� �����
     * @return �������� �����
     */
    string get_AssociatedSeries();
};

#endif