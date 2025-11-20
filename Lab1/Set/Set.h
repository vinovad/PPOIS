
#ifndef SET_H
#define SET_H
#include <iostream>
#include <cstring>
#include <cctype>

class SetElement {
private:
    char* value;

public:
    SetElement(const char* val = "");
    SetElement(const SetElement& other);
    ~SetElement();
    SetElement& operator=(const SetElement& other);
    const char* getValue() const;
    bool operator==(const SetElement& other) const;
    bool operator==(const char* other) const;
};
class Set {
private:
    SetElement* elements;
    int capacity;
    int size;
    char name[50];
    void resize(int newCapacity);
    void addElement(const char* value);
    void parseSet(const char* str);
    void cleanElement(char* element);
    int findElement(const char* value) const;
    void cleanName(const char* source, char* dest);
    void buildCantorSet(SetElement* elements, int start, int end, Set& result) const;

public:
    Set(const char* setName = "Unnamed");
    Set(const char* str, const char* setName);
    Set(const Set& other);
    Set& operator=(const Set& other);
    ~Set();
    const char* getName() const;
    void setName(const char* newName);
    void add(const char* value);
    bool remove(const char* value);
    int cardinality() const;
    bool contains(const char* value) const;
    Set unionWith(const Set& other) const;
    Set intersectionWith(const Set& other) const;
    Set differenceWith(const Set& other) const;
    void printPowerSet() const;
    Set toCantorSet() const;
    int getSize() const;
    const SetElement& getElement(int index) const;
    void print() const;
};
class SetManager {
private:
    Set* sets; 
    int capacity; 
    int size;
    void resize(int newCapacity);
    void cleanInput(char* str);

public:
    SetManager();
    ~SetManager();
    bool validateSetSyntax(const char* str);
    void showSyntaxErrors(const char* str);
    void printAllSets();
    int selectSet(const char* prompt);
    void createNewSet();
    void addElement();
    void removeElement();
    void performUnion();
    void performIntersection();
    void performDifference();
    void printSetCardinality();
    void checkElementMembership();
    void printPowerSet();
    void convertToCantorSet();
};
#endif

