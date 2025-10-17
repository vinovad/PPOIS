/**
 * @file PageCountException.h
 * @brief ���������� ��� ������ � ����������� �������
 */

#ifndef PAGE_COUNT_EXCEPTION_H
#define PAGE_COUNT_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class PageCountException : public runtime_error {
public:
    PageCountException(const string& msg) : runtime_error(msg) {}
};

#endif