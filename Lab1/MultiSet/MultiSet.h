#ifndef MULTISETS_H
#define MULTISETS_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>
class MultiSetElement {
private:
    char* value;    
    int count;  
    bool isSet;

public:
    MultiSetElement(const char* val, int cnt, bool set);
    MultiSetElement(const MultiSetElement& other);
    ~MultiSetElement();
    MultiSetElement& operator=(const MultiSetElement& other);
    const char* getValue() const { return value; }  
    int getCount() const { return count; }
    bool getIsSet() const { return isSet; } 
    void setCount(int cnt) { count = cnt; }    
    void setIsSet(bool set) { isSet = set; }  
    void incrementCount() { count++; }           
    void decrementCount() { if (count > 0) count--; } 
    bool operator==(const MultiSetElement& other) const;
    bool operator==(const char* other) const;
};
class UndirectedMultiSet {
private:
    MultiSetElement* elements;
    int capacity; 
    int size; 
    void resize(int newCapacity);
    int findElement(const char* value, bool isSet) const;
    void addElement(const char* value, int count, bool isSet);
    void removeElement(const char* value, bool isSet, int count);
    void parseSetString(const char* str);

public:
    UndirectedMultiSet();
    UndirectedMultiSet(const char* str);
    UndirectedMultiSet(const UndirectedMultiSet& other);
    ~UndirectedMultiSet();
    UndirectedMultiSet& operator=(const UndirectedMultiSet& other);
    void add(const char* value, int count, bool isSet);
    void remove(const char* value, bool isSet, int count);
    bool contains(const char* value, bool isSet) const;
    bool operator[](const char* value) const;
    int power() const;
    int uniqueCount() const;
    int totalCount() const;
    int getCount(const char* value, bool isSet) const;
    bool isEmpty() const;

public:
    static char* trim(char* str);
    UndirectedMultiSet operator+(const UndirectedMultiSet& other) const;
    UndirectedMultiSet& operator+=(const UndirectedMultiSet& other);
    UndirectedMultiSet operator*(const UndirectedMultiSet& other) const;
    UndirectedMultiSet& operator*=(const UndirectedMultiSet& other);
    UndirectedMultiSet operator-(const UndirectedMultiSet& other) const;
    UndirectedMultiSet& operator-=(const UndirectedMultiSet& other)
    UndirectedMultiSet boolean() const;
    char* toString() const;
    void print() const;
};
class SetManager {
private:
    UndirectedMultiSet* sets;   
    char** setNames;  
    int capacity;         
    int size;          
    int nextSetNumber;       
    void resize();

public:
    SetManager();
    ~SetManager();
    void addSet(const char* name, const UndirectedMultiSet& set);
    void addSetAutoName(const UndirectedMultiSet& set);
    int getSetCount() const;
 const char* getSetName(int index) const;
    const UndirectedMultiSet& getSet(int index) const;
    void listSets() const;
    int selectSet() const;
};
char* trim(char* str);
#endif

