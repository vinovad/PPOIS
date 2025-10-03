```cpp
/**
 * @file Book.h
 * @brief Заголовочный файл для системы управления книгами
 * @details Содержит классы для работы с книгами, авторами, жанрами и связанными характеристиками
 */

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/**
 * @class Exception
 * @brief Пользовательский класс исключений для системы книг
 * @details Наследуется от std::runtime_error для обработки ошибок в системе
 */
class Exception : public runtime_error {
public:
    /**
     * @brief Конструктор исключения
     * @param msg Сообщение об ошибке
     */
    Exception(const string& msg) : runtime_error(msg) {}
};

// ------------------------------------------------------------------------
// КЛАССЫ ЖАНРОВ
// ------------------------------------------------------------------------

/**
 * @class Genre_Fantasy
 * @brief Класс для жанра Фэнтези
 */
class Genre_Fantasy {
private:
    string genre = "Жанр:Фэнтези"; ///< Название жанра
public:
    /**
     * @brief Получить название жанра
     * @return Строка с названием жанра
     */
    string get_Genre();
};

/**
 * @class Genre_Triller
 * @brief Класс для жанра Триллеры
 */
class Genre_Triller {
private:
    string genre = "Жанр:Триллеры"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Horrors
 * @brief Класс для жанра Ужасы
 */
class Genre_Horrors {
private:
    string genre = "Жанр:Ужасы"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Detective
 * @brief Класс для жанра Детектив
 */
class Genre_Detective {
private:
    string genre = "Жанр:Детектив"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Romance_novel
 * @brief Класс для жанра Любовный роман
 */
class Genre_Romance_novel {
private:
    string genre = "Жанр:Любовный роман"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Classic
 * @brief Класс для жанра Классическая литература
 */
class Genre_Classic {
private:
    string genre = "Жанр:Классическая литература"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Fairy_tale
 * @brief Класс для жанра Сказки
 */
class Genre_Fairy_tale {
private:
    string genre = "Жанр:Классическая литература"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Romance
 * @brief Класс для жанра Романтика
 */
class Genre_Romance {
private:
    string genre = "Жанр:Романтика"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Adventure
 * @brief Класс для жанра Приключения
 */
class Genre_Adventure {
private:
    string genre = "Жанр:Приключения"; ///< Название жанра
public:
    string get_Genre();
};

/**
 * @class Genre_Science_Fiction
 * @brief Класс для жанра Научная фантастика
 */
class Genre_Science_Fiction {
private:
    string genre = "Жанр:Научная фантастика"; ///< Название жанра
public:
    string get_Genre();
};

// ------------------------------------------------------------------------
// КЛАССЫ АВТОРОВ
// ------------------------------------------------------------------------

/**
 * @class Author1
 * @brief Класс для автора Джоан Роулинг
 */
class Author1 {
private:
    string name = " Автор : Joanne Rowling"; ///< Имя автора
    string birth_year = "1965 год"; ///< Год рождения
    int books_written = 15; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author2
 * @brief Класс для автора Стивена Кинга
 */
class Author2 {
private:
    string name = " Автор : Stephen King"; ///< Имя автора
    string birth_year = "1947 год"; ///< Год рождения
    int books_written = 64; ///< Количество написанных книг
public:
    string get_Author();
    void set_birth(int by);
    int get_books();
};

/**
 * @class Author3
 * @brief Класс для автора Харуки Мураками
 */
class Author3 {
private:
    string name = " Автор : Haruki Murakami"; ///< Имя автора
    string birth_year = "1949 год"; ///< Год рождения
    int books_written = 14; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    void set_books(int bw);
};

/**
 * @class Author4
 * @brief Класс для автора Умберто Эко
 */
class Author4 {
private:
    string name = " Автор : Umberto Eco"; ///< Имя автора
    string birth_year = "1932 год"; ///< Год рождения
    int books_written = 7; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author5
 * @brief Класс для автора Люси М. Монтгомери
 */
class Author5 {
private:
    string name = " Автор : Lucy M. Montgomery"; ///< Имя автора
    string birth_year = "1847 год"; ///< Год рождения
    int books_written = 20; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author6
 * @brief Класс для автора Анджея Сапковского
 */
class Author6 {
private:
    string name = " Автор : Andrzej Sapkowski"; ///< Имя автора
    string birth_year = "1948 год"; ///< Год рождения
    int books_written = 10; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author7
 * @brief Класс для автора Шарля Перро
 */
class Author7 {
private:
    string name = " Автор : Charles Perrault"; ///< Имя автора
    string birth_year = "1628 год"; ///< Год рождения
    int books_written = 8; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author8
 * @brief Класс для автора Лю Цысиня
 */
class Author8 {
private:
    string name = " Автор : Liu Cixin"; ///< Имя автора
    string birth_year = "1963 год"; ///< Год рождения
    int books_written = 5; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author9
 * @brief Класс для автора Льва Толстого
 */
class Author9 {
private:
    string name = " Автор : Leo Tolstoy"; ///< Имя автора
    string birth_year = "1828 год"; ///< Год рождения
    int books_written = 30; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

/**
 * @class Author10
 * @brief Класс для автора Виктора Гюго
 */
class Author10 {
private:
    string name = " Автор : Victor Hugo"; ///< Имя автора
    string birth_year = "1802 год"; ///< Год рождения
    int books_written = 25; ///< Количество написанных книг
public:
    string get_Author();
    string get_birth();
    int get_books();
};

// ------------------------------------------------------------------------
// КЛАССЫ ГОДОВ ИЗДАНИЯ
// ------------------------------------------------------------------------

/**
 * @class Year_of_manufacture1
 * @brief Класс для года издания книги
 */
class Year_of_manufacture1 {
private:
    int year = 1997; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture2
 * @brief Класс для года издания книги
 */
class Year_of_manufacture2 {
private:
    int year = 2019; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture3
 * @brief Класс для года издания книги
 */
class Year_of_manufacture3 {
private:
    int year = 1987; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture4
 * @brief Класс для года издания книги
 */
class Year_of_manufacture4 {
private:
    int year = 1980; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture5
 * @brief Класс для года издания книги
 */
class Year_of_manufacture5 {
private:
    int year = 1908; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture6
 * @brief Класс для года издания книги с возможностью изменения
 */
class Year_of_manufacture6 {
private:
    int year = 1990; ///< Год издания
public:
    int get_Year();
    void set_Year(int y);
};

/**
 * @class Year_of_manufacture7
 * @brief Класс для года издания книги
 */
class Year_of_manufacture7 {
private:
    int year = 1697; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture8
 * @brief Класс для года издания книги
 */
class Year_of_manufacture8 {
private:
    int year = 2008; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture9
 * @brief Класс для года издания книги
 */
class Year_of_manufacture9 {
private:
    int year = 1869; ///< Год издания
public:
    int get_Year();
};

/**
 * @class Year_of_manufacture10
 * @brief Класс для года издания книги
 */
class Year_of_manufacture10 {
private:
    int year = 1831; ///< Год издания
public:
    int get_Year();
};

// ------------------------------------------------------------------------
// КЛАССЫ ГЛАВНЫХ ПЕРСОНАЖЕЙ
// ------------------------------------------------------------------------

/**
 * @class Main_character1
 * @brief Класс для главного персонажа Гарри Поттер
 */
class Main_character1 {
private:
    string name_character = "Гарри Поттер"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character2
 * @brief Класс для главного персонажа Люк Эллис
 */
class Main_character2 {
private:
    string name_character = "Люк Эллис"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character3
 * @brief Класс для главного персонажа Тору Ватанабэ
 */
class Main_character3 {
private:
    string name_character = "Тору Ватанабэг"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character4
 * @brief Класс для главного персонажа Вильгельм из Баскервиля
 */
class Main_character4 {
private:
    string name_character = "Вильгельм из Баскервиля"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character5
 * @brief Класс для главного персонажа Энн Ширли
 */
class Main_character5 {
private:
    string name_character = "Энн Ширли"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character6
 * @brief Класс для главного персонажа Ведьмак
 */
class Main_character6 {
private:
    string name_character = "Ведьмак"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character7
 * @brief Класс для главного персонажа Золушка
 */
class Main_character7 {
private:
    string name_character = "Золушка"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character8
 * @brief Класс для главного персонажа Ван Мяо
 */
class Main_character8 {
private:
    string name_character = "Ван Мяо"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character9
 * @brief Класс для главного персонажа Пьеро Безруков
 */
class Main_character9 {
private:
    string name_character = "Пьеро Безруков"; ///< Имя персонажа
public:
    string get_character();
};

/**
 * @class Main_character10
 * @brief Класс для главного персонажа Квазимодо
 */
class Main_character10 {
private:
    string name_character = "Квазимодо"; ///< Имя персонажа
public:
    string get_character();
};

// ------------------------------------------------------------------------
// КЛАССЫ СТРАН ПРОИСХОЖДЕНИЯ
// ------------------------------------------------------------------------

/**
 * @class Country_of_origin1
 * @brief Класс для страны происхождения Великобритания
 */
class Country_of_origin1 {
private:
    string country = "United Kingdom"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin2
 * @brief Класс для страны происхождения США
 */
class Country_of_origin2 {
private:
    string country = "United States"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin3
 * @brief Класс для страны происхождения Япония
 */
class Country_of_origin3 {
private:
    string country = "Japan"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin4
 * @brief Класс для страны происхождения Италия
 */
class Country_of_origin4 {
private:
    string country = "Italy"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin5
 * @brief Класс для страны происхождения Канада
 */
class Country_of_origin5 {
private:
    string country = "Canada"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin6
 * @brief Класс для страны происхождения Польша
 */
class Country_of_origin6 {
private:
    string country = "Poland"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin7
 * @brief Класс для страны происхождения Германия
 */
class Country_of_origin7 {
private:
    string country = "Germany"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin8
 * @brief Класс для страны происхождения Китай
 */
class Country_of_origin8 {
private:
    string country = "Сhina"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin9
 * @brief Класс для страны происхождения Россия
 */
class Country_of_origin9 {
private:
    string country = "Russia"; ///< Название страны
public:
    string get_country();
};

/**
 * @class Country_of_origin10
 * @brief Класс для страны происхождения Франция
 */
class Country_of_origin10 {
private:
    string country = "France"; ///< Название страны
public:
    string get_country();
};

// ------------------------------------------------------------------------
// КЛАССЫ КНИГ
// ------------------------------------------------------------------------

/**
 * @class book_HarryPotter
 * @brief Класс для книги "Гарри Поттер"
 * @details Наследует характеристики жанра, автора, года издания, персонажа и страны
 */
class book_HarryPotter : public Genre_Fantasy, public Author1, public Year_of_manufacture1, public Main_character1, public Country_of_origin1 {
private:
    int number_pages1 = 400; ///< Количество страниц
    string book_tag1 = "Волшебство"; ///< Тег книги
    string publisher = "Bloomsbury"; ///< Издатель
    string language = "English"; ///< Язык книги
    double rating = 4.8; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 12; ///< Возрастное ограничение
protected:
    string title_book = "HarryPotter"; ///< Название книги
public:
    Author1 Author; ///< Объект автора
    Year_of_manufacture1 Year_of_manufacture; ///< Объект года издания
    Main_character1 Main_character; ///< Объект главного персонажа
    Country_of_origin1 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    void set_Genre(string gen);
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Institute
 * @brief Класс для книги "Институт"
 */
class book_Institute : private Genre_Horrors, public Author2, public Year_of_manufacture2, public Main_character2, public Country_of_origin2 {
private:
    int number_pages2 = 500; ///< Количество страниц
    string title_book = "Institute"; ///< Название книги
    string book_tag2 = "Похищение"; ///< Тег книги
    int number_pages1 = 400; ///< Дублирующая переменная (возможная ошибка)
    string publisher = "Scribner"; ///< Издатель
    string language = "English"; ///< Язык книги
    double rating = 4.3; ///< Рейтинг книги
    string format = "Paperback"; ///< Формат издания
    int age_restriction = 18; ///< Возрастное ограничение
public:
    Author2 Author; ///< Объект автора
    Year_of_manufacture2 Year_of_manufacture; ///< Объект года издания
    Main_character2 Main_character; ///< Объект главного персонажа
    Country_of_origin2 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    void set_format(string f);
    int get_age_restriction();
};

/**
 * @class book_NorwegianWood
 * @brief Класс для книги "Норвежский лес"
 */
class book_NorwegianWood : protected Genre_Triller, public Author3, public Year_of_manufacture3, public Main_character3, public Country_of_origin3 {
private:
    int number_pages3 = 296; ///< Количество страниц
    string title_book = "Norwegian Wood"; ///< Название книги
    string book_tag3 = "Nostalgia"; ///< Тег книги
    string publisher = "Kodansha"; ///< Издатель
    string language = "Japanese"; ///< Язык книги
    double rating = 4.5; ///< Рейтинг книги
    string format = "Paperback"; ///< Формат издания
    int age_restriction = 16; ///< Возрастное ограничение
public:
    Author3 Author; ///< Объект автора
    Year_of_manufacture3 Year_of_manufacture; ///< Объект года издания
    Main_character3 Main_character; ///< Объект главного персонажа
    Country_of_origin3 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    void set_Tag(string tg);
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Name_of_Rose
 * @brief Класс для книги "Имя розы"
 */
class book_Name_of_Rose : public Genre_Detective, public Author4, public Year_of_manufacture4, public Main_character4, public Country_of_origin4 {
private:
    int number_pages4 = 328; ///< Количество страниц
    string title_book = "The Name of the Rose"; ///< Название книги
    string book_tag4 = "Монастырь"; ///< Тег книги
    string publisher = "Bompiani"; ///< Издатель
    string language = "Italian"; ///< Язык книги
    double rating = 4.6; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 16; ///< Возрастное ограничение
public:
    Author4 Author; ///< Объект автора
    Year_of_manufacture4 Year_of_manufacture; ///< Объект года издания
    Main_character4 Main_character; ///< Объект главного персонажа
    Country_of_origin4 Country; ///< Объект страны происхождения

    int get_number_pages();
    void set_Book(string tb);
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Anne_Green_Gables
 * @brief Класс для книги "Энн из Зелёных Мезонинов"
 */
class book_Anne_Green_Gables : public Genre_Romance_novel, public Author5, public Year_of_manufacture5, public Main_character5, public Country_of_origin5 {
private:
    int number_pages5 = 310; ///< Количество страниц
    string title_book = "Anne of Green Gables"; ///< Название книги
    string book_tag5 = "Сирота"; ///< Тег книги
    string publisher = "L.C. Page & Co. "; ///< Издатель
    string language = "English"; ///< Язык книги
    double rating = 4.7; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 10; ///< Возрастное ограничение
public:
    Author5 Author; ///< Объект автора
    Year_of_manufacture5 Year_of_manufacture; ///< Объект года издания
    Main_character5 Main_character; ///< Объект главного персонажа
    Country_of_origin5 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    void set_language(string l);
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_The_Witcher
 * @brief Класс для книги "Ведьмак"
 */
class book_The_Witcher : public Genre_Adventure, public Author6, public Year_of_manufacture6, public Main_character6, public Country_of_origin6 {
private:
    int number_pages6 = 635; ///< Количество страниц
    string title_book = "The Witcher"; ///< Название книги
    string book_tag6 = "Adventure"; ///< Тег книги
    string publisher = "superNOWA"; ///< Издатель
    string language = "Polish"; ///< Язык книги
    double rating = 4.4; ///< Рейтинг книги
    string format = "Paperback"; ///< Формат издания
    int age_restriction = 16; ///< Возрастное ограничение
public:
    Author6 Author; ///< Объект автора
    Year_of_manufacture6 Year_of_manufacture; ///< Объект года издания
    Main_character6 Main_character; ///< Объект главного персонажа
    Country_of_origin6 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    void set_Year(string g);
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Cinderella
 * @brief Класс для книги "Золушка"
 */
class book_Cinderella : public Genre_Fairy_tale, public Author7, public Year_of_manufacture7, public Main_character7, public Country_of_origin7 {
private:
    int number_pages7 = 50; ///< Количество страниц
    string title_book = "Cinderella"; ///< Название книги
    string book_tag7 = "Надежда"; ///< Тег книги
    string publisher = "Barbin"; ///< Издатель
    string language = "French"; ///< Язык книги
    double rating = 4.9; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 6; ///< Возрастное ограничение
public:
    Author7 Author; ///< Объект автора
    Year_of_manufacture7 Year_of_manufacture; ///< Объект года издания
    Main_character7 Main_character; ///< Объект главного персонажа
    Country_of_origin7 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    void set_publisher(string p);
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Three_Body_Problem
 * @brief Класс для книги "Задача трёх тел"
 */
class book_Three_Body_Problem : public Genre_Science_Fiction, public Author8, public Year_of_manufacture8, public Main_character8, public Country_of_origin8 {
private:
    int number_pages8 = 362; ///< Количество страниц
    string title_book = "The Three-Body Problem"; ///< Название книги
    string book_tag8 = "Космос"; ///< Тег книги
    string publisher = "Chongqing Press"; ///< Издатель
    string language = "Chinese"; ///< Язык книги
    double rating = 4.2; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 14; ///< Возрастное ограничение
public:
    Author8 Author; ///< Объект автора
    Year_of_manufacture8 Year_of_manufacture; ///< Объект года издания
    Main_character8 Main_character; ///< Объект главного персонажа
    Country_of_origin8 Country; ///< Объект страны происхождения

    void set_number_pages(int n);
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_War_and_Peace
 * @brief Класс для книги "Война и мир"
 */
class book_War_and_Peace : public Genre_Classic, public Author9, public Year_of_manufacture9, public Main_character9, public Country_of_origin9 {
private:
    int number_pages9 = 1225; ///< Количество страниц
    string title_book = "War and Peace"; ///< Название книги
    string book_tag9 = "История"; ///< Тег книги
    string publisher = "The Russian Messenger"; ///< Издатель
    string language = "Russian"; ///< Язык книги
    double rating = 4.7; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 14; ///< Возрастное ограничение
public:
    Author9 Author; ///< Объект автора
    Year_of_manufacture9 Year_of_manufacture; ///< Объект года издания
    Main_character9 Main_character; ///< Объект главного персонажа
    Country_of_origin9 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    void set_rating(double r);
    string get_format();
    int get_age_restriction();
};

/**
 * @class book_Notre_Dame
 * @brief Класс для книги "Собор Парижской Богоматери"
 */
class book_Notre_Dame : public Genre_Romance, public Author10, public Year_of_manufacture10, public Main_character10, public Country_of_origin10 {
private:
    int number_pages10 = 100; ///< Количество страниц
    string title_book = "Notre-Dame de Paris)"; ///< Название книги
    string book_tag10 = "Судьба"; ///< Тег книги
    string publisher = "Gosselin"; ///< Издатель
    string language = "French"; ///< Язык книги
    double rating = 4.6; ///< Рейтинг книги
    string format = "Hardcover"; ///< Формат издания
    int age_restriction = 12; ///< Возрастное ограничение
public:
    Author10 Author; ///< Объект автора
    Year_of_manufacture10 Year_of_manufacture; ///< Объект года издания
    Main_character10 Main_character; ///< Объект главного персонажа
    Country_of_origin10 Country; ///< Объект страны происхождения

    int get_number_pages();
    string get_Book();
    string get_Genre();
    string get_Author();
    int get_Year();
    string get_character();
    string get_Tag();
    string get_publisher();
    string get_language();
    double get_rating();
    string get_format();
    void set_age_restriction(int v);
};

#endif
```
