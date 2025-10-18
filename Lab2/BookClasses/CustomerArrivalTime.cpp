#include "Book.h"
using namespace std;

CustomerArrivalTime::CustomerArrivalTime(const string& t, const string& day, const string& dd, const User& user)
    : time(t), day_of_week(day), date_day(dd) {
}
CustomerArrivalTime::CustomerArrivalTime() : time("14:30"), day_of_week("Sunday"), date_day("12-10-2025") {}
string CustomerArrivalTime::get_time() { return time; }
string CustomerArrivalTime::get_day_w() { return day_of_week; }
string CustomerArrivalTime::get_day_d() { return date_day; }