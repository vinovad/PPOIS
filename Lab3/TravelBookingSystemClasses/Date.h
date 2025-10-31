#pragma once
#include <string>
#include "DataException.h" 

class Date {
public:
    int day, month, year;
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    std::string getDataInString();
    bool isValid();
};