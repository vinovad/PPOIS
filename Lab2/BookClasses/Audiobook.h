/**
 * @file Audiobook.h
 * @brief ����� ��� ������ � ������������
 */

#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

 /**
  * @class Audiobook
  * @brief ������������ ���������� � ������� ����������� �����
  */
class Audiobook {
private:
    bool has_audiobook; ///< ������� ����������

public:
    /**
     * @brief ����������� � ����������
     * @param audio ������� ����������
     */
    Audiobook(bool audio);

    /**
     * @brief ����������� �� ���������
     */
    Audiobook();

    /**
     * @brief ��������� ������� �����������
     * @return true ���� ���������� ��������, false � ��������� ������
     */
    bool has_audiobook_version();
};

#endif