#ifndef BOOKARRIVALNOTIFICATION_H
#define BOOKARRIVALNOTIFICATION_H
#include "ArrivalDate.h"
#include <string>
using namespace std;
class BookArrivalNotification {
private:
    string book_title;
    string notification_message;
    bool is_sent;
    ArrivalDate associatedArrivalDate;
    string notification_type;
    int priority_level;
    string notification_channel;
    int retry_count;
    string status;

public:
    BookArrivalNotification(const string& title, const ArrivalDate& arrivalDate);
    BookArrivalNotification();
    void send_notification();
    string get_book_title();
    bool is_notification_sent();
    string get_AssociatedArrivalDate();
    void reset_notification();
};

#endif

