'''cpp
/**
 * @file Multisets.h
 * @brief Заголовочный файл для работы с мультимножествами
 * @mainpage Система управления мультимножествами
 * 
 * Данная система предоставляет классы для работы с мультимножествами,
 * включая операции объединения, пересечения, разности и булевы операции.
 */

#ifndef MULTISETS_H
#define MULTISETS_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>

/**
 * @class MultiSetElement
 * @brief Класс, представляющий элемент мультимножества
 * 
 * Хранит значение элемента, количество вхождений и флаг принадлежности к множеству
 */
class MultiSetElement {
private:
    char* value;    ///< Значение элемента
    int count;      ///< Количество вхождений элемента
    bool isSet;     ///< Флаг принадлежности к множеству (true) или мультимножеству (false)

public:
    /**
     * @brief Конструктор элемента
     * @param val Значение элемента
     * @param cnt Количество вхождений
     * @param set Флаг принадлежности к множеству
     */
    MultiSetElement(const char* val, int cnt, bool set);

    /**
     * @brief Конструктор копирования
     * @param other Элемент для копирования
     */
    MultiSetElement(const MultiSetElement& other);
    
    /**
     * @brief Деструктор
     */
    ~MultiSetElement();
    
    /**
     * @brief Оператор присваивания
     * @param other Элемент для присваивания
     * @return Ссылка на текущий объект
     */
    MultiSetElement& operator=(const MultiSetElement& other);

    /// @name Методы доступа
    /// @{
    const char* getValue() const { return value; }  ///< Получить значение элемента
    int getCount() const { return count; }          ///< Получить количество вхождений
    bool getIsSet() const { return isSet; }         ///< Получить флаг множества
    void setCount(int cnt) { count = cnt; }         ///< Установить количество вхождений
    void setIsSet(bool set) { isSet = set; }        ///< Установить флаг множества
    void incrementCount() { count++; }              ///< Увеличить счетчик на 1
    void decrementCount() { if (count > 0) count--; } ///< Уменьшить счетчик на 1
    /// @}

    /**
     * @brief Оператор сравнения с другим элементом
     * @param other Элемент для сравнения
     * @return true если элементы равны, false в противном случае
     */
    bool operator==(const MultiSetElement& other) const;

    /**
     * @brief Оператор сравнения со строкой
     * @param other Строка для сравнения
     * @return true если значение равно строке, false в противном случае
     */
    bool operator==(const char* other) const;
};

/**
 * @class UndirectedMultiSet
 * @brief Класс, представляющий неориентированное мультимножество
 * 
 * Поддерживает операции над мультимножествами и обычными множествами
 */
class UndirectedMultiSet {
private:
    MultiSetElement* elements;  ///< Массив элементов мультимножества
    int capacity;               ///< Емкость массива элементов
    int size;                   ///< Текущий размер массива элементов

    /**
     * @brief Изменить размер массива элементов
     * @param newCapacity Новая емкость массива
     */
    void resize(int newCapacity);

    /**
     * @brief Найти индекс элемента по значению
     * @param value Значение для поиска
     * @param isSet Флаг типа элемента (множество/мультимножество)
     * @return Индекс элемента или -1 если не найден
     */
    int findElement(const char* value, bool isSet) const;

    /**
     * @brief Добавить новый элемент
     * @param value Значение элемента
     * @param count Количество вхождений
     * @param isSet Флаг типа элемента
     */
    void addElement(const char* value, int count, bool isSet);
    
    /**
     * @brief Удалить элемент
     * @param value Значение элемента
     * @param isSet Флаг типа элемента
     * @param count Количество для удаления
     */
    void removeElement(const char* value, bool isSet, int count);

    /**
     * @brief Разобрать строковое представление множества
     * @param str Строка для разбора
     */
    void parseSetString(const char* str);

public:
    /**
     * @brief Конструктор по умолчанию
     */
    UndirectedMultiSet();
    
    /**
     * @brief Конструктор из строки
     * @param str Строковое представление множества
     */
    UndirectedMultiSet(const char* str);

    /**
     * @brief Конструктор копирования
     * @param other Мультимножество для копирования
     */
    UndirectedMultiSet(const UndirectedMultiSet& other);
    
    /**
     * @brief Деструктор
     */
    ~UndirectedMultiSet();

    /**
     * @brief Оператор присваивания
     * @param other Мультимножество для присваивания
     * @return Ссылка на текущий объект
     */
    UndirectedMultiSet& operator=(const UndirectedMultiSet& other);
    
    /**
     * @brief Добавить элемент в мультимножество
     * @param value Значение элемента
     * @param count Количество вхождений
     * @param isSet Флаг типа элемента
     */
    void add(const char* value, int count, bool isSet);

    /**
     * @brief Удалить элемент из мультимножества
     * @param value Значение элемента
     * @param isSet Флаг типа элемента
     * @param count Количество для удаления
     */
    void remove(const char* value, bool isSet, int count);

    /**
     * @brief Проверить наличие элемента
     * @param value Значение элемента
     * @param isSet Флаг типа элемента
     * @return true если элемент найден, false в противном случае
     */
    bool contains(const char* value, bool isSet) const;

    /**
     * @brief Оператор проверки наличия элемента
     * @param value Значение элемента
     * @return true если элемент найден, false в противном случае
     */
    bool operator[](const char* value) const;
    
    /**
     * @brief Получить мощность множества (количество уникальных элементов)
     * @return Мощность множества
     */
    int power() const;
    
    /**
     * @brief Получить количество уникальных элементов
     * @return Количество уникальных элементов
     */
    int uniqueCount() const;

    /**
     * @brief Получить общее количество элементов (с учетом кратности)
     * @return Общее количество элементов
     */
    int totalCount() const;
    
    /**
     * @brief Получить количество вхождений элемента
     * @param value Значение элемента
     * @param isSet Флаг типа элемента
     * @return Количество вхождений элемента
     */
    int getCount(const char* value, bool isSet) const;
    
    /**
     * @brief Проверить, пусто ли мультимножество
     * @return true если мультимножество пусто, false в противном случае
     */
    bool isEmpty() const;

public:
    /**
     * @brief Удалить пробелы из строки
     * @param str Строка для обработки
     * @return Указатель на обработанную строку
     */
    static char* trim(char* str);

    /// @name Операции над мультимножествами
    /// @{
    
    /**
     * @brief Объединение мультимножеств
     * @param other Мультимножество для объединения
     * @return Новое мультимножество - результат объединения
     */
    UndirectedMultiSet operator+(const UndirectedMultiSet& other) const;

    /**
     * @brief Объединение с присваиванием
     * @param other Мультимножество для объединения
     * @return Ссылка на текущий объект
     */
    UndirectedMultiSet& operator+=(const UndirectedMultiSet& other);

    /**
     * @brief Пересечение мультимножеств
     * @param other Мультимножество для пересечения
     * @return Новое мультимножество - результат пересечения
     */
    UndirectedMultiSet operator*(const UndirectedMultiSet& other) const;

    /**
     * @brief Пересечение с присваиванием
     * @param other Мультимножество для пересечения
     * @return Ссылка на текущий объект
     */
    UndirectedMultiSet& operator*=(const UndirectedMultiSet& other);

    /**
     * @brief Разность мультимножеств
     * @param other Мультимножество для вычитания
     * @return Новое мультимножество - результат разности
     */
    UndirectedMultiSet operator-(const UndirectedMultiSet& other) const;

    /**
     * @brief Разность с присваиванием
     * @param other Мультимножество для вычитания
     * @return Ссылка на текущий объект
     */
    UndirectedMultiSet& operator-=(const UndirectedMultiSet& other);

    /**
     * @brief Булева операция (дополнение до универсума)
     * @return Новое мультимножество - результат булевой операции
     */
    UndirectedMultiSet boolean() const;
    /// @}

    /**
     * @brief Преобразовать в строковое представление
     * @return Строковое представление мультимножества
     */
    char* toString() const;
    
    /**
     * @brief Вывести мультимножество на экран
     */
    void print() const;
};

/**
 * @class SetManager
 * @brief Менеджер для управления коллекцией мультимножеств
 * 
 * Позволяет хранить несколько мультимножеств с именами и выполнять операции над ними
 */
class SetManager {
private:
    UndirectedMultiSet* sets;   ///< Массив мультимножеств
    char** setNames;            ///< Массив имен мультимножеств
    int capacity;               ///< Емкость массивов
    int size;                   ///< Текущий размер массивов
    int nextSetNumber;          ///< Счетчик для автоматического именования

    /**
     * @brief Увеличить размер массивов
     */
    void resize();

public:
    /**
     * @brief Конструктор по умолчанию
     */
    SetManager();
    
    /**
     * @brief Деструктор
     */
    ~SetManager();

    /**
     * @brief Добавить мультимножество с указанным именем
     * @param name Имя мультимножества
     * @param set Мультимножество для добавления
     */
    void addSet(const char* name, const UndirectedMultiSet& set);

    /**
     * @brief Добавить мультимножество с автоматическим именем
     * @param set Мультимножество для добавления
     */
    void addSetAutoName(const UndirectedMultiSet& set);
    
    /**
     * @brief Получить количество мультимножеств
     * @return Количество мультимножеств
     */
    int getSetCount() const;

    /**
     * @brief Получить имя мультимножества по индексу
     * @param index Индекс мультимножества
     * @return Имя мультимножества
     */
    const char* getSetName(int index) const;

    /**
     * @brief Получить мультимножество по индексу
     * @param index Индекс мультимножества
     * @return Константная ссылка на мультимножество
     */
    const UndirectedMultiSet& getSet(int index) const;
    
    /**
     * @brief Вывести список всех мультимножеств
     */
    void listSets() const;

    /**
     * @brief Выбрать мультимножество через пользовательский ввод
     * @return Индекс выбранного мультимножества
     */
    int selectSet() const;
};

/**
 * @brief Удалить пробелы из строки
 * @param str Строка для обработки
 * @return Указатель на обработанную строку
 */
char* trim(char* str);

#endif
'''
