'''cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"

SetElement::SetElement(const char* val) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}

SetElement::SetElement(const SetElement& other) {
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

SetElement::~SetElement() {
    delete[] value;
}

SetElement& SetElement::operator=(const SetElement& other) {
    if (this != &other) {
        delete[] value;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

const char* SetElement::getValue() const {
    return value;
}

bool SetElement::operator==(const SetElement& other) const {
    return strcmp(value, other.value) == 0;
}

bool SetElement::operator==(const char* other) const {
    return strcmp(value, other) == 0;
}

// Set implementation
void Set::resize(int newCapacity) {
    SetElement* newElements = new SetElement[newCapacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

void Set::addElement(const char* value) {
    if (strlen(value) == 0) return;

    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return;
        }
    }

    if (size >= capacity) {
        resize(capacity * 2 + 1);
    }
    elements[size++] = SetElement(value);
}

void Set::parseSet(const char* str) {
    int len = strlen(str);
    int pos = 0;
    int braceCount = 0;
    char currentElement[500] = "";
    int elemPos = 0;
    bool inElement = false;

    while (pos < len) {
        char c = str[pos];

        if (c == '{') {
            braceCount++;
            if (braceCount == 1) {
                pos++;
                continue;
            }
            else {
                inElement = true;
                currentElement[elemPos++] = c;
            }
        }
        else if (c == '}') {
            braceCount--;
            if (braceCount == 0) {
                break;
            }
            else {
                currentElement[elemPos++] = c;
                if (braceCount == 1) {
                    currentElement[elemPos] = '\0';
                    addElement(currentElement);
                    elemPos = 0;
                    inElement = false;
                }
            }
        }
        else if (c == ',' && braceCount == 1) {
            if (elemPos > 0) {
                currentElement[elemPos] = '\0';
                addElement(currentElement);
                elemPos = 0;
            }
            inElement = false;
        }
        else if (!isspace(c) || inElement) {
            if (elemPos < 499) {
                currentElement[elemPos++] = c;
            }
            if (braceCount > 1) {
                inElement = true;
            }
        }
      

        pos++;
    }

    if (elemPos > 0) {
        currentElement[elemPos] = '\0';
        addElement(currentElement);
    }
}

void Set::cleanElement(char* element) {
    int len = strlen(element);
    int start = 0, end = len - 1;

    while (start < len && isspace(element[start])) {
        start++;
    }

    while (end >= 0 && isspace(element[end])) {
        end--;
    }

    if (start > end) {
        element[0] = '\0';
        return;
    }

    int newLen = end - start + 1;
    for (int i = 0; i < newLen; i++) {
        element[i] = element[start + i];
    }
    element[newLen] = '\0';
}

int Set::findElement(const char* value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return i;
        }
    }
    return -1;
}

void Set::cleanName(const char* source, char* dest) {
    int j = 0;
    for (int i = 0; source[i] != '\0' && j < 49; i++) {
        if (isprint((unsigned char)source[i]) &&
            source[i] != '\n' && source[i] != '\r') {
            dest[j++] = source[i];
        }
    }
    dest[j] = '\0';

    if (j == 0) {
        strcpy(dest, "Unnamed_Set");
    }
}

Set::Set(const char* setName) : elements(nullptr), capacity(0), size(0) {
    cleanName(setName, name);
    elements = new SetElement[10];
    capacity = 10;
}

Set::Set(const char* str, const char* setName) : elements(nullptr), capacity(0), size(0) {
    cleanName(setName, name);
    elements = new SetElement[10];
    capacity = 10;
    if (str && strlen(str) > 0) {
        parseSet(str);
    }
}

Set::Set(const Set& other) : elements(nullptr), capacity(0), size(0) {
    strncpy(name, other.name, 49);
    name[49] = '\0';
    elements = new SetElement[other.capacity];
    capacity = other.capacity;
    size = other.size;
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        delete[] elements;
        strncpy(name, other.name, 49);
        name[49] = '\0';
        elements = new SetElement[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

Set::~Set() {
    delete[] elements;
}

const char* Set::getName() const {
    return name;
}

void Set::setName(const char* newName) {
    cleanName(newName, name);
}

void Set::add(const char* value) {
    char cleaned[500];
    strcpy(cleaned, value);
    cleanElement(cleaned);
    addElement(cleaned);
}

bool Set::remove(const char* value) {
    int index = findElement(value);
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
        return true;
    }
    return false;
}

int Set::cardinality() const {
    return size;
}

bool Set::contains(const char* value) const {
    return findElement(value) != -1;
}

Set Set::unionWith(const Set& other) const {
    Set result("Union");

    for (int i = 0; i < size; i++) {
        result.add(elements[i].getValue());
    }

    for (int i = 0; i < other.size; i++) {
        result.add(other.elements[i].getValue());
    }

    return result;
}

Set Set::intersectionWith(const Set& other) const {
    Set result("Intersection");

    for (int i = 0; i < size; i++) {
        const char* value = elements[i].getValue();
        if (other.contains(value)) {
            result.add(value);
        }
    }

    return result;
}

Set Set::differenceWith(const Set& other) const {
    Set result("Difference");

    for (int i = 0; i < size; i++) {
        const char* value = elements[i].getValue();
        if (!other.contains(value)) {
            result.add(value);
        }
    }

    return result;
}

void Set::printPowerSet() const {
    std::cout << "Булеан множества " << name << " (все подмножества):" << std::endl;
    std::cout << "{}" << std::endl;

    int totalSubsets = 1 << size;
    for (int mask = 1; mask < totalSubsets; mask++) {
        std::cout << "{";
        bool first = true;

        for (int i = 0; i < size; i++) {
            if (mask & (1 << i)) {
                if (!first) {
                    std::cout << ", ";
                }
                std::cout << elements[i].getValue();
                first = false;
            }
        }
        std::cout << "}" << std::endl;
    }
}

Set Set::toCantorSet() const {
    Set result("Cantor");

    if (size == 0) {
        return result;
    }

    SetElement* tempElements = new SetElement[size];
    for (int i = 0; i < size; i++) {
        tempElements[i] = elements[i];
    }

    buildCantorSet(tempElements, 0, size - 1, result);

    delete[] tempElements;
    return result;
}

void Set::buildCantorSet(SetElement* elements, int start, int end, Set& result) const {
    if (start > end) {
        return;
    }

    int length = end - start + 1;

    if (length == 1) {
        result.add(elements[start].getValue());
        return;
    }

    if (length == 2) {
        result.add(elements[start].getValue());
        result.add(elements[end].getValue());
        return;
    }

    int removeStart, removeEnd;

    if (length % 2 == 1) {
        int middle = start + length / 2;
        removeStart = middle;
        removeEnd = middle;
    }
    else {
        int middle1 = start + length / 2 - 1;
        int middle2 = start + length / 2;
        removeStart = middle1;
        removeEnd = middle2;
    }

    buildCantorSet(elements, start, removeStart - 1, result);
    buildCantorSet(elements, removeEnd + 1, end, result);
}

int Set::getSize() const {
    return size;
}

const SetElement& Set::getElement(int index) const {
    return elements[index];
}

void Set::print() const {
    std::cout << name << " = {";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i].getValue();
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

SetManager::SetManager() : sets(nullptr), capacity(0), size(0) {
    sets = new Set[10];
    capacity = 10;
}

SetManager::~SetManager() {
    delete[] sets;
}

void SetManager::resize(int newCapacity) {
    Set* newSets = new Set[newCapacity];
    for (int i = 0; i < size; i++) {
        newSets[i] = sets[i];
    }
    delete[] sets;
    sets = newSets;
    capacity = newCapacity;
}

void SetManager::cleanInput(char* str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isprint((unsigned char)str[i]) &&
            str[i] != '\n' && str[i] != '\r') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

bool SetManager::validateSetSyntax(const char* str) {
    int len = strlen(str);
    int braceCount = 0;
    bool lastWasComma = false;
    bool hasContent = false;

    if (len == 0) return false;

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '{') {
            braceCount++;
            lastWasComma = false;
            hasContent = true;
        }
        else if (c == '}') {
            braceCount--;
            if (lastWasComma) return false;
            if (braceCount < 0) return false;
            lastWasComma = false;
        }
        else if (c == ',') {
            if (lastWasComma) return false;
            if (braceCount == 0) return false;
            lastWasComma = true;
        }
        else if (!isspace(c)) {
            lastWasComma = false;
            hasContent = true;
        }
    }

    return braceCount == 0 && hasContent;
}

void SetManager::showSyntaxErrors(const char* str) {
    int len = strlen(str);
    int braceCount = 0;
    bool lastWasComma = false;

    for (int i = 0; i < len; i++) {
        char c = str[i];

        if (c == '{') braceCount++;
        else if (c == '}') braceCount--;

        if (c == ',' && (i == 0 || i == len - 1)) {
            std::cout << "  - Запятая не может быть в начале или конце" << std::endl;
        }
        if (c == ',' && lastWasComma) {
            std::cout << "  - Две запятые подряд" << std::endl;
        }
        if (c == '}' && lastWasComma) {
            std::cout << "  - Запятая перед закрывающей скобкой" << std::endl;
        }

        lastWasComma = (c == ',');
    }

    if (braceCount > 0) {
        std::cout << "  - Не хватает " << braceCount << " закрывающих скобок" << std::endl;
    }
    else if (braceCount < 0) {
        std::cout << "  - Не хватает " << (-braceCount) << " открывающих скобок" << std::endl;
    }
}

void SetManager::createNewSet() {
    if (size >= capacity) {
        resize(capacity * 2 + 1);
    }

    char name[50];
    char elements[500];

    std::cout << "Введите имя нового множества: ";
    std::cin.getline(name, 50);
    cleanInput(name);

    if (strlen(name) == 0) {
        strcpy(name, "Set");
        char num[10];
        sprintf(num, "%d", size + 1);
        strcat(name, num);
    }

    while (true) {
        std::cout << "Введите элементы множества в формате {elem1, elem2, ...}: ";
        std::cin.getline(elements, 500);
        cleanInput(elements);

        if (validateSetSyntax(elements)) {
            sets[size++] = Set(elements, name);
            std::cout << "Множество '" << name << "' создано!" << std::endl;
            break;
        }
        else {
            std::cout << "Ошибка в синтаксисе!" << std::endl;
            std::cout << "Пожалуйста, введите множество заново." << std::endl;
        }
    }
}

void SetManager::printAllSets() {
    std::cout << "\n=== Доступные множества ===" << std::endl;
    if (size == 0) {
        std::cout << "Множеств пока нет. Создайте первое множество." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". ";
        sets[i].print();
    }
}

int SetManager::selectSet(const char* prompt) {
    if (size == 0) {
        std::cout << "Сначала создайте хотя бы одно множество!" << std::endl;
        return -1;
    }

    int choice;
    printAllSets();
    std::cout << prompt;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Неверный ввод! Пожалуйста, введите число." << std::endl;
        return -1;
    }

    std::cin.ignore(10000, '\n');

    if (choice < 1 || choice > size) {
        std::cout << "Неверный выбор! Доступны номера от 1 до " << size << std::endl;
        return -1;
    }
    return choice - 1;
}

void SetManager::addElement() {
    int setIndex = selectSet("Выберите множество для добавления элемента: ");
    if (setIndex == -1) return;

    char value[100];

    std::cout << "Введите элемент: ";
    std::cin.getline(value, 100);
    cleanInput(value);

    sets[setIndex].add(value);
    std::cout << "Элемент добавлен. Обновленное множество: ";
    sets[setIndex].print();
}

void SetManager::removeElement() {
    int setIndex = selectSet("Выберите множество для удаления элемента: ");
    if (setIndex == -1) return;

    char value[100];

    std::cout << "Введите элемент для удаления: ";
    std::cin.getline(value, 100);
    cleanInput(value);

    if (sets[setIndex].remove(value)) {
        std::cout << "Элемент удален. Обновленное множество: ";
        sets[setIndex].print();
    }
    else {
        std::cout << "Элемент не найден." << std::endl;
    }
}

void SetManager::performUnion() {
    int set1 = selectSet("Выберите первое множество: ");
    if (set1 == -1) return;

    int set2 = selectSet("Выберите второе множество: ");
    if (set2 == -1) return;

    Set result = sets[set1].unionWith(sets[set2]);
    result.setName("Union_Result");
    std::cout << "Результат объединения: ";
    result.print();
}

void SetManager::performIntersection() {
    int set1 = selectSet("Выберите первое множество: ");
    if (set1 == -1) return;

    int set2 = selectSet("Выберите второе множество: ");
    if (set2 == -1) return;

    Set result = sets[set1].intersectionWith(sets[set2]);
    result.setName("Intersection_Result");
    std::cout << "Результат пересечения: ";
    result.print();
}

void SetManager::performDifference() {
    int set1 = selectSet("Выберите первое множество (из которого вычитаем): ");
    if (set1 == -1) return;

    int set2 = selectSet("Выберите второе множество (которое вычитаем): ");
    if (set2 == -1) return;

    Set result = sets[set1].differenceWith(sets[set2]);
    result.setName("Difference_Result");
    std::cout << "Результат разности: ";
    result.print();
}

void SetManager::printSetCardinality() {
    int setIndex = selectSet("Выберите множество: ");
    if (setIndex != -1) {
        std::cout << "Мощность множества: "
            << sets[setIndex].cardinality() << std::endl;
    }
}

void SetManager::checkElementMembership() {
    int setIndex = selectSet("Выберите множество: ");
    if (setIndex != -1) {
        char value[100];
        std::cout << "Введите элемент для проверки: ";
        std::cin.getline(value, 100);
        cleanInput(value);
        bool contains = sets[setIndex].contains(value);
        std::cout << "Элемент '" << value << "' "
            << (contains ? "принадлежит" : "не принадлежит")
            << " множеству " << sets[setIndex].getName() << std::endl;
    }
}

void SetManager::printPowerSet() {
    int setIndex = selectSet("Выберите множество: ");
    if (setIndex != -1) {
        sets[setIndex].printPowerSet();
    }
}

void SetManager::convertToCantorSet() {
    int setIndex = selectSet("Выберите множество: ");
    if (setIndex != -1) {
        std::cout << "Исходное множество: ";
        sets[setIndex].print();

        Set cantorSet = sets[setIndex].toCantorSet();
        std::cout << "Канторово множество (удалена средняя часть на каждом шаге): ";
        cantorSet.print();
    }
}

'''
