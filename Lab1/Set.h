'''cpp
/**
 * @file Set.h
 * @brief Заголовочный файл для классов работы с множествами
 * @details Содержит определения классов SetElement, Set и SetManager для операций с множествами строк
 */

#ifndef SET_H
#define SET_H
#include <iostream>
#include <cstring>
#include <cctype>

 /**
  * @class SetElement
  * @brief Класс элемента множества, хранящий строковое значение
  */ 

class SetElement {
private:
    char* value;

public:
    /**
     * @brief Конструктор по умолчанию
     * @param val Строковое значение элемента (по умолчанию пустая строка)
     */
    SetElement(const char* val = "");

    /**
    * @brief Конструктор копирования
    * @param other Объект для копирования
    */
    SetElement(const SetElement& other);

    /**
     * @brief Деструктор
     */
    ~SetElement();

    /**
     * @brief Оператор присваивания
     * @param other Объект для присваивания
     * @return Ссылка на текущий объект
     */
    SetElement& operator=(const SetElement& other);

    /**
     * @brief Получить значение элемента
     * @return Указатель на строковое значение
     */
    const char* getValue() const;

    /**
     * @brief Оператор сравнения с другим элементом
     * @param other Элемент для сравнения
     * @return true если значения равны
     */
    bool operator==(const SetElement& other) const;

    /**
     * @brief Оператор сравнения со строкой
     * @param other Строка для сравнения
     * @return true если значения равны
     */
    bool operator==(const char* other) const;
};

/**
 * @class Set
 * @brief Класс для работы с множеством строковых элементов
 */
class Set {
private:
    SetElement* elements;
    int capacity;
    int size;
    char name[50];

    /**
     * @brief Изменяет размер внутреннего массива элементов
     * @param newCapacity Новая вместимость массива
     */
    void resize(int newCapacity);
    /**
    * @brief Внутренний метод добавления элемента
    * @param value Значение добавляемого элемента
    */
    void addElement(const char* value);

    /**
     * @brief Парсит строку и заполняет множество элементами
     * @param str Строка в формате {элемент1, элемент2, ...}
     */
    void parseSet(const char* str);

    /**
     * @brief Очищает элемент от лишних пробелов
     * @param element Строка для очистки
     */
    void cleanElement(char* element);

    /**
     * @brief Ищет элемент в множестве
     * @param value Значение для поиска
     * @return Индекс элемента или -1 если не найден
     */
    int findElement(const char* value) const;

    /**
     * @brief Очищает имя от нежелательных символов
     * @param source Исходное имя
     * @param dest Буфер для очищенного имени
     */
    void cleanName(const char* source, char* dest);

    /**
     * @brief Рекурсивно строит канторово множество
     * @param elements Массив элементов
     * @param start Начальный индекс
     * @param end Конечный индекс
     * @param result Результирующее множество
     */
    void buildCantorSet(SetElement* elements, int start, int end, Set& result) const;

public:
    /**
    * @brief Конструктор множества
    * @param setName Имя множества (по умолчанию "Unnamed")
    */
    Set(const char* setName = "Unnamed");

    /**
     * @brief Конструктор множества из строки
     * @param str Строка с элементами
     * @param setName Имя множества
     */
    Set(const char* str, const char* setName);

    /**
     * @brief Конструктор копирования
     * @param other Множество для копирования
     */
    Set(const Set& other);

    /**
     * @brief Оператор присваивания
     * @param other Множество для присваивания
     * @return Ссылка на текущий объект
     */
    Set& operator=(const Set& other);

    /**
     * @brief Деструктор
     */
    ~Set();

    /**
    * @brief Получает имя множества
    * @return Имя множества
    */
    const char* getName() const;

    /**
     * @brief Устанавливает имя множества
     * @param newName Новое имя множества
     */
    void setName(const char* newName);

    /**
     * @brief Добавляет элемент в множество
     * @param value Значение элемента
     */
    void add(const char* value);

    /**
     * @brief Удаляет элемент из множества
     * @param value Значение элемента для удаления
     * @return true если элемент удален, false если не найден
     */
    bool remove(const char* value);

    /**
     * @brief Возвращает мощность множества
     * @return Количество элементов в множестве
     */
    int cardinality() const;

    /**
     * @brief Проверяет принадлежность элемента множеству
     * @param value Значение элемента
     * @return true если элемент принадлежит множеству
     */
    bool contains(const char* value) const;

    /**
     * @brief Объединяет текущее множество с другим
     * @param other Другое множество
     * @return Новое множество - результат объединения
     */
    Set unionWith(const Set& other) const;

    /**
     * @brief Находит пересечение с другим множеством
     * @param other Другое множество
     * @return Новое множество - результат пересечения
     */
    Set intersectionWith(const Set& other) const;

    /**
     * @brief Находит разность с другим множеством
     * @param other Другое множество
     * @return Новое множество - результат разности
     */
    Set differenceWith(const Set& other) const;

    /**
     * @brief Выводит булеан множества (все подмножества)
     */
    void printPowerSet() const;

    /**
     * @brief Преобразует множество в канторово множество
     * @return Канторово множество
     */
    Set toCantorSet() const;

    /**
     * @brief Получает размер множества
     * @return Количество элементов
     */
    int getSize() const;

    /**
     * @brief Получает элемент по индексу
     * @param index Индекс элемента
     * @return Ссылка на элемент
     */
    const SetElement& getElement(int index) const;

    /**
     * @brief Выводит множество в поток
     */
    void print() const;
};

/**
 * @class SetManager
 * @brief Менеджер для работы с коллекцией множеств
 */
class SetManager {
private:
    Set* sets; ///< Динамический массив множеств
    int capacity; ///< Вместимость массива множеств
    int size; ///< Текущее количество множеств

    /**
     * @brief Изменяет размер массива множеств
     * @param newCapacity Новая вместимость
     */
    void resize(int newCapacity);

    /**
     * @brief Очищает входную строку от лишних символов
     * @param str Строка для очистки
     */
    void cleanInput(char* str);

public:
    /**
     * @brief Конструктор менеджера множеств
     */
    SetManager();

    /**
     * @brief Деструктор менеджера множеств
     */
    ~SetManager();

    /**
     * @brief Проверяет синтаксис строки множества
     * @param str Строка для проверки
     * @return true если синтаксис корректен
     */
    bool validateSetSyntax(const char* str);

    /**
     * @brief Показывает синтаксические ошибки в строке
     * @param str Строка для анализа
     */
    void showSyntaxErrors(const char* str);

    /**
     * @brief Выводит все множества
     */
    void printAllSets();

    /**
     * @brief Выбирает множество из списка
     * @param prompt Приглашение для пользователя
     * @return Индекс выбранного множества
     */
    int selectSet(const char* prompt);

    /**
     * @brief Создает новое множество
     */
    void createNewSet();

    /**
     * @brief Добавляет элемент в выбранное множество
     */
    void addElement();

    /**
     * @brief Удаляет элемент из выбранного множества
     */
    void removeElement();

    /**
     * @brief Выполняет объединение двух множеств
     */
    void performUnion();

    /**
     * @brief Выполняет пересечение двух множеств
     */
    void performIntersection();

    /**
     * @brief Выполняет разность двух множеств
     */
    void performDifference();

    /**
     * @brief Выводит мощность выбранного множества
     */
    void printSetCardinality();

    /**
     * @brief Проверяет принадлежность элемента множеству
     */
    void checkElementMembership();

    /**
     * @brief Выводит булеан выбранного множества
     */
    void printPowerSet();

    /**
     * @brief Преобразует множество в канторово
     */
    void convertToCantorSet();
};

/**
 * @brief Выводит меню операций с множествами
 */


#endif
'''
