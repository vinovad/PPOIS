/**
 * @file PublisherException.h
 * @brief Исключение для работы с издательствами
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