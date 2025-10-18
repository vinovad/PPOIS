/**
 * @file NumberOfBooks.h
 * @brief ����� ��� ������ � ����������� ����
 */

#ifndef NUMBEROFBOOKS_H
#define NUMBEROFBOOKS_H

 /**
  * @class NumberOfBooks
  * @brief ������������ ���������� ��������� ����
  */
class NumberOfBooks {
private:
    int quantity; ///< ���������� ����

public:
    /**
     * @brief ����������� � ����������
     * @param qty ���������� ����
     */
    NumberOfBooks(int qty);

    /**
     * @brief ����������� �� ���������
     */
    NumberOfBooks();

    /**
     * @brief �������� ���������� ����
     * @return ���������� ����
     */
    int get_quantity();
};

#endif