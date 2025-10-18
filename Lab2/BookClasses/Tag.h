/**
 * @file Tag.h
 * @brief ����� ��� ������ � ������ ����
 */

#ifndef TAG_H
#define TAG_H

#include <string>
using namespace std;

/**
 * @class Tag
 * @brief ������������ ��� ��� ������������� ����
 */
class Tag {
private:
    string book_tag; ///< �������� ����

public:
    /**
     * @brief ����������� � ����������
     * @param t �������� ����
     */
    Tag(const string& t);

    /**
     * @brief ����������� �� ���������
     */
    Tag();

    /**
     * @brief �������� ���
     * @return �������� ����
     */
    string get_Tag();

    /**
     * @brief ���������� ���
     * @param tg ����� �������� ����
     */
    void set_Tag(string tg);
};

#endif