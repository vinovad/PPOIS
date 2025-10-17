/**
 * @file PublisherException.h
 * @brief ���������� ��� ������ � ��������������
 */

#ifndef PUBLISHER_EXCEPTION_H
#define PUBLISHER_EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class PublisherException : public runtime_error {
public:
    PublisherException(const string& msg) : runtime_error(msg) {}
};

#endif