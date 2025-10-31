#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "TimeClass.h"

class Notification {
private:
    std::string notificationId;
    Date* sentDate;
    TimeClass* sentTime;

public:
    int userId;
    std::string message;
    std::string type;
    std::string channel;
    bool isRead;
    bool isSent;
    std::string priority;
    int retryCount;

    Notification(std::string id, int userId, std::string message,
        std::string type, std::string channel);
    bool send();
    bool markAsRead();
    bool retry();
    std::string getNotificationId();
    void setPriority(std::string newPriority);
    bool isHighPriority();
    std::string getChannel();
};