#include "DateRange.h"

DateRange::DateRange(int day, int month, int year) : Date(day, month, year), rangeId(1) {}

Date DateRange::getRange(Date* b) {
    int d = this->day - (b->day);
    if (d < 0) { d = d * -1; }
    int m = this->month - (b->month);
    if (m < 0) { m = m * -1; }
    int y = this->year - (b->year);
    if (y < 0) { y = y * -1; }

    return Date(d, m, y);
}

int DateRange::getRangeId() {
    return rangeId;
}

bool DateRange::isValidRange() {
    return day > 0 && month > 0 && year > 0;
}