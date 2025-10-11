
  /**
 * @file Exception.h
 * @brief Класс исключений для системы управления книгами
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

/**
 * @class Exception
 * @brief Пользовательский класс исключений
 * 
 * Наследует от std::runtime_error для обработки ошибок в системе.
 */
class Exception : public runtime_error {
public:
    /**
     * @brief Конструктор исключения
     * @param msg Сообщение об ошибке
     */
    Exception(const string& msg) : runtime_error(msg) {}
};

#endif
 
