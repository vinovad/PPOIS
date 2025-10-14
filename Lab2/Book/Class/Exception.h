/**
 * @file Exception.h
 * @brief Классы исключений для системы управления книгами
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

/**
 * @class TagException
 * @brief Исключение для работы с тегами
 */
class TagException : public runtime_error {
public:
    TagException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class GenreException
 * @brief Исключение для работы с жанрами
 */
class GenreException : public runtime_error {
public:
    GenreException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class YearException
 * @brief Исключение для работы с годами издания
 */
class YearException : public runtime_error {
public:
    YearException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class LanguageException
 * @brief Исключение для работы с языками
 */
class LanguageException : public runtime_error {
public:
    LanguageException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class AuthorBirthException
 * @brief Исключение для ошибок в дате рождения автора
 */
class AuthorBirthException : public runtime_error {
public:
    AuthorBirthException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class AuthorBooksException
 * @brief Исключение для ошибок в количестве книг автора
 */
class AuthorBooksException : public runtime_error {
public:
    AuthorBooksException(const string& msg) : runtime_error(msg) {}
};
/**
 * @class RatingException
 * @brief Исключение для работы с рейтингами
 */
class RatingException : public runtime_error {
public:
    RatingException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class PublisherException
 * @brief Исключение для работы с издательствами
 */
class PublisherException : public runtime_error {
public:
    PublisherException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class PageCountException
 * @brief Исключение для работы с количеством страниц
 */
class PageCountException : public runtime_error {
public:
    PageCountException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class BookTitleException
 * @brief Исключение для работы с названиями книг
 */
class BookTitleException : public runtime_error {
public:
    BookTitleException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class AgeRestrictionException
 * @brief Исключение для работы с возрастными ограничениями
 */
class AgeRestrictionException : public runtime_error {
public:
    AgeRestrictionException(const string& msg) : runtime_error(msg) {}
};

/**
 * @class CoverFormatException
 * @brief Исключение для работы с форматами обложки
 */
class CoverFormatException : public runtime_error {
public:
    CoverFormatException(const string& msg) : runtime_error(msg) {}
};

#endif
