/**
 * @file BookArrivalNotification.h
 * @brief ����� ��� ������ � ������������� � ����������� ����
 */

#ifndef BOOKARRIVALNOTIFICATION_H
#define BOOKARRIVALNOTIFICATION_H

#include "ArrivalDate.h"
#include <string>
using namespace std;

/**
 * @class BookArrivalNotification
 * @brief ������������ ����������� � ����������� �����
 */
class BookArrivalNotification {
private:
    string book_title;              ///< �������� �����
    string notification_message;    ///< ����� �����������
    bool is_sent;                   ///< ������ ��������
    ArrivalDate associatedArrivalDate; ///< ��������������� ���� �����������
    string notification_type;       ///< ��� �����������
    int priority_level;             ///< ������� ����������

public:
    /**
     * @brief ����������� � �����������
     * @param title �������� �����
     * @param arrivalDate ��������������� ���� �����������
     */
    BookArrivalNotification(const string& title, const ArrivalDate& arrivalDate);

    /**
     * @brief ����������� �� ���������
     */
    BookArrivalNotification();

    /**
     * @brief ��������� �����������
     */
    void send_notification();

    /**
     * @brief �������� �������� �����
     * @return �������� �����
     */
    string get_book_title();

    /**
     * @brief ���������, ���������� �� �����������
     * @return true ���� ����������� ����������, false � ��������� ������
     */
    bool is_notification_sent();

    /**
     * @brief �������� ��������������� ���� �����������
     * @return ���� �����������
     */
    string get_AssociatedArrivalDate();

    /**
     * @brief �������� ������ �����������
     */
    void reset_notification();
};

#endif