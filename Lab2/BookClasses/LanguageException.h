/**
 * @file LanguageException.h
 * @brief ���������� ��� ������ � �������
 */

#ifndef LANGUAGE_EXCEPTION_H
#define LANGUAGE_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class LanguageException : public runtime_error {
public:
    LanguageException(const string& msg) : runtime_error(msg) {}
};

#endif