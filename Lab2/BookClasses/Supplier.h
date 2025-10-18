/**
 * @file Supplier.h
 * @brief ����� ��� ������ � ������������ ����
 */

#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "ImportCountry.h"
#include "BookCondition.h"
#include <string>
using namespace std;

/**
 * @class Supplier
 * @brief ������������ ���������� ���� � ����������� � ������ ������� � ���������
 */
class Supplier {
private:
    string supplier_name;               ///< �������� ����������
    ImportCountry associatedImportCountry; ///< ��������������� ������ �������
    BookCondition associatedBookCondition; ///< ��������������� ��������� �����

public:
    /**
     * @brief ����������� � �����������
     * @param name �������� ����������
     * @param importCountry ��������������� ������ �������
     * @param bookCondition ��������������� ��������� �����
     */
    Supplier(const string& name, const ImportCountry& importCountry, const BookCondition& bookCondition);

    /**
     * @brief ����������� �� ���������
     */
    Supplier();

    /**
     * @brief �������� �������� ����������
     * @return �������� ����������
     */
    string get_supplier();

    /**
     * @brief �������� ��������������� ������ �������
     * @return ������ �������
     */
    string get_AssociatedImportCountry();

    /**
     * @brief �������� ������ ������� �������
     * @return true ���� ������ ��������, false � ��������� ������
     */
    bool get_AssociatedImportProhibited();

    /**
     * @brief �������� ��������������� ��������� �����
     * @return ��������� �����
     */
    string get_AssociatedBookCondition();
};

#endif