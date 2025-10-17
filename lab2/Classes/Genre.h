/**
 * @file Genre.h
 * @brief ����� ��� ������ � ������� ����
 */

#ifndef GENRE_H
#define GENRE_H

#include "Tag.h"
#include <string>
using namespace std;

/**
 * @class Genre
 * @brief ������������ ���� ����� � ��������������� �����
 */
class Genre {
private:
    string genre;           ///< �������� �����
    Tag associatedTag;      ///< ��������������� ���

public:
    /**
     * @brief ����������� � �����������
     * @param g �������� �����
     * @param tag ��������������� ���
     */
    Genre(const string& g, const Tag& tag);

    /**
     * @brief ����������� �� ���������
     */
    Genre();

    /**
     * @brief �������� ����
     * @return �������� �����
     */
    string get_Genre();

    /**
     * @brief �������� ��������������� ���
     * @return �������� ����
     */
    string get_AssociatedTag();

    /**
     * @brief ���������� ����
     * @param gen ����� �������� �����
     */
    void set_Genre(string gen);
};

#endif