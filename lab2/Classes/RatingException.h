/**
 * @file RatingException.h
 * @brief Исключение для работы с рейтингами
 */
#ifndef RATING_EXCEPTION_H
#define RATING_EXCEPTION_H
#include <stdexcept>
#include <string>
using namespace std;
class RatingException : public runtime_error {
public: RatingException(const string& msg) : runtime_error(msg) {} };
#endif
