
/**
 * @file CustomerArrivalTime.h
 * @brief Класс для работы с временем прибытия клиентов
 */

#ifndef CUSTOMERARRIVALTIME_H
#define CUSTOMERARRIVALTIME_H

#include "User.h"
#include <string>
using namespace std;

/**
 * @class CustomerArrivalTime
 * @brief Представляет информацию о времени прибытия клиентов
 */
class CustomerArrivalTime {
private:
    string time;            ///< Время прибытия
    string day_of_week;     ///< День недели
    string date_day;        ///< Дата
    string visit_purpose;   ///< Цель визита
    int visit_duration;     ///< Продолжительность визита

public:
    /**
     * @brief Конструктор с параметрами
     * @param t Время прибытия
     * @param day День недели
     * @param dd Дата
     * @param user Ассоциированный пользователь
     */
    CustomerArrivalTime(const string& t, const string& day, const string& dd, const User& user);
    
    /**
     * @brief Конструктор по умолчанию
     */
    CustomerArrivalTime();
    
    /**
     * @brief Получить время прибытия
     * @return Время прибытия
     */
    string get_time();
    
    /**
     * @brief Получить день недели
     * @return День недели
     */
    string get_day_w();
    
    /**
     * @brief Получить дату
     * @return Дата
     */
    string get_day_d();
};

#endif
