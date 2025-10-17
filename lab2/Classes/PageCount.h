/**
 * @file PageCount.h
 * @brief ����� ��� ������ � ����������� � ��������� �����
 */

#ifndef PAGECOUNT_H
#define PAGECOUNT_H

 /**
  * @class PageCount
  * @brief ������������ ���������� � ���������� ������� � ��������� �����
  */
class PageCount {
private:
    int number_pages;           ///< ���������� �������
    int illustrations_count;    ///< ���������� �����������
    int chapters_count;         ///< ���������� ����

public:
    /**
     * @brief ����������� � ����������
     * @param pages ���������� �������
     */
    PageCount(int pages);

    /**
     * @brief ����������� �� ���������
     */
    PageCount();

    /**
     * @brief �������� ���������� �������
     * @return ���������� �������
     */
    int get_number_pages();

    /**
     * @brief ���������� ���������� �������
     * @param n ����� ���������� �������
     */
    void set_number_pages(int n);
};

#endif