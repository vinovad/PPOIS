/**
 * @file TagException.h
 * @brief ���������� ��� ������ � ������
 */

#ifndef TAG_EXCEPTION_H
#define TAG_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class TagException : public runtime_error {
public:
    TagException(const string& msg) : runtime_error(msg) {}
};

#endif