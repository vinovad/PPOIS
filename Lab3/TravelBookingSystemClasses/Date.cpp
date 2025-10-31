#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

std::string Date::getDataInString() {
    return (std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year));
}

bool Date::isValid() {
    if (day > 31) {
        throw DataException();
    }
    else if (month > 12) {
        throw DataException();
    }
    else if (year < 0) {
        throw DataException();
    }
    return 1;
}