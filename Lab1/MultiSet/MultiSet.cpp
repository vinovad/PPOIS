
#define _CRT_SECURE_NO_WARNINGS
#include "MultiSet.h"

MultiSetElement::MultiSetElement(const char* val = "", int cnt = 1, bool set = false) : count(cnt), isSet(set) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}

MultiSetElement::MultiSetElement(const MultiSetElement& other) : count(other.count), isSet(other.isSet) {
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

MultiSetElement:: ~MultiSetElement() {
    delete[] value;
}

MultiSetElement& MultiSetElement::operator=(const MultiSetElement& other) {
    if (this != &other) {
        delete[] value;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
        count = other.count;
        isSet = other.isSet;
    }
    return *this;
}



bool MultiSetElement:: operator==(const MultiSetElement& other) const {
    return strcmp(value, other.value) == 0 && isSet == other.isSet;
}

bool  MultiSetElement::operator==(const char* other) const {
    return strcmp(value, other) == 0 && !isSet;
}
void UndirectedMultiSet::resize(int newCapacity) {
    MultiSetElement* newElements = new MultiSetElement[newCapacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

int  UndirectedMultiSet::findElement(const char* value, bool isSet) const {
    char normalizedValue[256];
    strcpy(normalizedValue, value);
    trim(normalizedValue);

    for (int i = 0; i < size; i++) {
        char storedValue[256];
        strcpy(storedValue, elements[i].getValue());
        trim(storedValue);

        if (strcmp(normalizedValue, storedValue) == 0 &&
            elements[i].getIsSet() == isSet) {
            return i;
        }
    }
    return -1;
}

void UndirectedMultiSet::addElement(const char* value, int count = 1, bool isSet = false) {
    if (size >= capacity) {
        resize(capacity * 2 + 1);
    }
    elements[size++] = MultiSetElement(value, count, isSet);
}
void UndirectedMultiSet::removeElement(const char* value, bool isSet = false, int count = 1) {
    int index = findElement(value, isSet);
    if (index != -1) {
        if (elements[index].getCount() <= count) {
            for (int j = index; j < size - 1; j++) {
                elements[j] = elements[j + 1];
            }
            size--;
        }
        else {
            elements[index].setCount(elements[index].getCount() - count);
        }
    }
    else {
        std::cout << "Элемент не найден!" << std::endl;
    }
}

int UndirectedMultiSet::getCount(const char* value, bool isSet = false) const {
    char normalized[256];
    strcpy(normalized, value);
    trim(normalized);

    int index = findElement(normalized, isSet);
    return (index != -1) ? elements[index].getCount() : 0;
}

void UndirectedMultiSet::parseSetString(const char* str) {
    int len = strlen(str);
    int braceCount = 0;
    int start = 0;
    char buffer[256];
    int bufIndex = 0;
    bool inSet = false;

    for (int i = 0; i < len; i++) {
        if (str[i] == '{') {
            braceCount++;
            if (braceCount == 1) {
                if (bufIndex > 0) {
                    buffer[bufIndex] = '\0';
                    char* trimmed = trim(buffer);
                    if (strlen(trimmed) > 0) {
                        addElement(trimmed, 1, false);
                    }
                    bufIndex = 0;
                }
                start = i;
                inSet = true;
            }
            buffer[bufIndex++] = str[i];
        }
        else if (str[i] == '}') {
            braceCount--;
            buffer[bufIndex++] = str[i];
            if (braceCount == 0 && inSet) {
                buffer[bufIndex] = '\0';
                addElement(buffer, 1, true);
                bufIndex = 0;
                inSet = false;
                i++;
                while (i < len && (str[i] == ' ' || str[i] == ',')) i++;
                i--;
            }
        }
        else if (braceCount == 0) {
            if (str[i] == ',') {
                if (bufIndex > 0) {
                    buffer[bufIndex] = '\0';
                    char* trimmed = trim(buffer);
                    if (strlen(trimmed) > 0) {
                        addElement(trimmed, 1, false);
                    }
                    bufIndex = 0;
                }
            }
            else if (str[i] != ' ') {
                buffer[bufIndex++] = str[i];
            }
        }
        else {
            buffer[bufIndex++] = str[i];
        }
    }

    if (bufIndex > 0 && braceCount == 0) {
        buffer[bufIndex] = '\0';
        char* trimmed = trim(buffer);
        if (strlen(trimmed) > 0) {
            addElement(trimmed, 1, false);
        }
    }
}


UndirectedMultiSet::UndirectedMultiSet() : elements(nullptr), capacity(0), size(0) {
    elements = new MultiSetElement[10];
    capacity = 10;
}

UndirectedMultiSet::UndirectedMultiSet(const char* str) : elements(nullptr), capacity(0), size(0) {
    elements = new MultiSetElement[10];
    capacity = 10;
    parseSetString(str);
}

UndirectedMultiSet::UndirectedMultiSet(const UndirectedMultiSet& other) : elements(nullptr), capacity(0), size(0) {
    elements = new MultiSetElement[other.capacity];
    capacity = other.capacity;
    size = other.size;
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

UndirectedMultiSet::    ~UndirectedMultiSet() {
    delete[] elements;
}

UndirectedMultiSet& UndirectedMultiSet:: operator=(const UndirectedMultiSet& other) {
    if (this != &other) {
        delete[] elements;
        elements = new MultiSetElement[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

void UndirectedMultiSet::add(const char* value, int count = 1, bool isSet = false) {
    addElement(value, count, isSet);
}

void UndirectedMultiSet::remove(const char* value, bool isSet = false, int count = 1) {
    if (!contains(value, isSet)) {
        std::cout << "Элемент не найден!" << std::endl;
        return;
    }
    removeElement(value, isSet, count);
}

bool UndirectedMultiSet::contains(const char* value, bool isSet = false) const {
    char normalized[256];
    strcpy(normalized, value);
    trim(normalized);

    return getCount(normalized, isSet) > 0;
}

bool UndirectedMultiSet:: operator[](const char* value) const {
    return contains(value);
}

int UndirectedMultiSet::power() const {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += elements[i].getCount();
    }
    return total;
}

int UndirectedMultiSet::uniqueCount() const {
    return size;
}

int UndirectedMultiSet::totalCount() const {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += elements[i].getCount();
    }
    return total;
}

bool UndirectedMultiSet::isEmpty() const {
    return size == 0;
}


char* UndirectedMultiSet::trim(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

UndirectedMultiSet UndirectedMultiSet:: operator+(const UndirectedMultiSet& other) const {
    UndirectedMultiSet result(*this);
    for (int i = 0; i < other.size; i++) {
        result.addElement(other.elements[i].getValue(),
            other.elements[i].getCount(),
            other.elements[i].getIsSet());
    }
    return result;
}

UndirectedMultiSet& UndirectedMultiSet:: operator+=(const UndirectedMultiSet& other) {
    for (int i = 0; i < other.size; i++) {
        addElement(other.elements[i].getValue(),
            other.elements[i].getCount(),
            other.elements[i].getIsSet());
    }
    return *this;
}

UndirectedMultiSet UndirectedMultiSet::  operator*(const UndirectedMultiSet& other) const {
    UndirectedMultiSet result;

    bool* processed = new bool[size]();

    for (int i = 0; i < size; i++) {
        if (processed[i]) continue;

        const char* currentValue = elements[i].getValue();
        bool currentIsSet = elements[i].getIsSet();

        int currentTotalCount = elements[i].getCount();
        processed[i] = true;

        for (int k = i + 1; k < size; k++) {
            if (!processed[k] && strcmp(elements[k].getValue(), currentValue) == 0 &&
                elements[k].getIsSet() == currentIsSet) {
                currentTotalCount += elements[k].getCount();
                processed[k] = true;
            }
        }

        int otherTotalCount = 0;
        for (int j = 0; j < other.size; j++) {
            if (strcmp(other.elements[j].getValue(), currentValue) == 0 &&
                other.elements[j].getIsSet() == currentIsSet) {
                otherTotalCount += other.elements[j].getCount();
            }
        }

        int minCount = (currentTotalCount < otherTotalCount) ? currentTotalCount : otherTotalCount;
        if (minCount > 0) {
            result.addElement(currentValue, minCount, currentIsSet);
        }
    }

    delete[] processed;
    return result;
}

UndirectedMultiSet& UndirectedMultiSet:: operator*=(const UndirectedMultiSet& other) {
    *this = *this * other;
    return *this;
}

UndirectedMultiSet UndirectedMultiSet:: operator-(const UndirectedMultiSet& other) const {
    UndirectedMultiSet result;

    for (int i = 0; i < size; i++) {
        const char* currentValue = elements[i].getValue();
        bool currentIsSet = elements[i].getIsSet();
        int currentCount = elements[i].getCount();

        int otherIndex = other.findElement(currentValue, currentIsSet);

        if (otherIndex == -1) {
            result.addElement(currentValue, currentCount, currentIsSet);
        }
        else {
            int otherCount = other.elements[otherIndex].getCount();
            int diffCount = currentCount - otherCount;

            if (diffCount > 0) {
                result.addElement(currentValue, diffCount, currentIsSet);
            }
        }
    }

    return result;
}

UndirectedMultiSet& UndirectedMultiSet::  operator-=(const UndirectedMultiSet& other) {
    *this = *this - other;
    return *this;
}

UndirectedMultiSet UndirectedMultiSet::boolean() const {
    UndirectedMultiSet result;
    result.add("{}", 1, true);

    int totalSubsets = 1 << size;
    for (int i = 1; i < totalSubsets; i++) {
        UndirectedMultiSet subset;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                subset.add(elements[j].getValue(), elements[j].getCount(), elements[j].getIsSet());
            }
        }
        char subsetStr[1024];
        strcpy(subsetStr, subset.toString());
        result.add(subsetStr, 1, true);
    }
    return result;
}

char* UndirectedMultiSet::toString() const {
    if (isEmpty()) {
        char* result = new char[3];
        strcpy(result, "{}");
        return result;
    }

    char* result = new char[1024];
    strcpy(result, "{");

    for (int i = 0; i < size; i++) {
        strcat(result, elements[i].getValue());
        if (elements[i].getCount() > 1) {
            char countStr[10];
            sprintf(countStr, "(%d)", elements[i].getCount());
            strcat(result, countStr);
        }
        if (i < size - 1) {
            strcat(result, ", ");
        }
    }
    strcat(result, "}");
    return result;
}

void UndirectedMultiSet::print() const {
    char* str = toString();
    std::cout << str << std::endl;
    delete[] str;
}


void SetManager::resize() {
    int newCapacity = capacity * 2 + 1;
    UndirectedMultiSet* newSets = new UndirectedMultiSet[newCapacity];
    char** newNames = new char* [newCapacity];

    for (int i = 0; i < size; i++) {
        newSets[i] = sets[i];
        newNames[i] = new char[strlen(setNames[i]) + 1];
        strcpy(newNames[i], setNames[i]);
        delete[] setNames[i];
    }

    delete[] sets;
    delete[] setNames;

    sets = newSets;
    setNames = newNames;
    capacity = newCapacity;
}

SetManager::SetManager() : sets(nullptr), setNames(nullptr), capacity(0), size(0), nextSetNumber(1) {
    sets = new UndirectedMultiSet[10];
    setNames = new char* [10];
    capacity = 10;
}

SetManager::~SetManager() {
    for (int i = 0; i < size; i++) {
        delete[] setNames[i];
    }
    delete[] sets;
    delete[] setNames;
}

void SetManager::addSet(const char* name, const UndirectedMultiSet& set) {
    if (size >= capacity) {
        resize();
    }

    sets[size] = set;
    setNames[size] = new char[strlen(name) + 1];
    strcpy(setNames[size], name);
    size++;
}

void SetManager::addSetAutoName(const UndirectedMultiSet& set) {
    char name[50];
    sprintf(name, "Set%d", nextSetNumber++);
    addSet(name, set);
}

int SetManager::getSetCount() const {
    return size;
}

const char* SetManager::getSetName(int index) const {
    if (index >= 0 && index < size) {
        return setNames[index];
    }
    return nullptr;
}

const UndirectedMultiSet& SetManager::getSet(int index) const {
    return sets[index];
}

void SetManager::listSets() const {
    if (size == 0) {
        std::cout << "Нет сохраненных множеств." << std::endl;
        return;
    }

    std::cout << "Сохраненные множества:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << setNames[i] << " = ";
        sets[i].print();
    }
}

int SetManager::selectSet() const {
    if (size == 0) {
        std::cout << "Нет множеств для выбора." << std::endl;
        return -1;
    }

    listSets();
    std::cout << "Выберите множество (1-" << size << "): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice < 1 || choice > size) {
        std::cout << "Неверный выбор!" << std::endl;
        return -1;
    }

    return choice - 1;
}



char* trim(char* str) {
    if (str == nullptr) return str;

    char* start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == 0) {
        str[0] = '\0';
        return str;
    }

    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    *(end + 1) = '\0';

    if (start != str) {
        memmove(str, start, end - start + 2);
    }

    return str;
}

