#include "TimeClass.h"
#include "TimeException.h"

TimeClass::TimeClass(int seconds) {
    try {
        if (seconds < 0) { throw TimeException(); }
        this->sec = seconds % 60;
        seconds -= this->sec;
        this->min = (seconds % 3600) / 60;
        seconds -= (this->min * 60);
        this->hour = seconds / 3600;
    }
    catch (TimeException a) {
        std::cout << "Exception : " << a.what() << std::endl;
    }
}

int TimeClass::getMin() {
    return min;
}

int TimeClass::getHour() {
    return hour;
}

int TimeClass::getSec() {
    return sec;
}

std::string TimeClass::getTimeInString() {
    std::string t = std::to_string(hour) + ":" + std::to_string(min) + ":" + std::to_string(sec);
    return t;
}