/**
 * @file CoverFormatException.h
 * @brief ���������� ��� ������ � ��������� �������
 */

#ifndef COVER_FORMAT_EXCEPTION_H
#define COVER_FORMAT_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class CoverFormatException : public runtime_error {
public:
    CoverFormatException(const string& msg) : runtime_error(msg) {}
};

#endif