#include "Notification.h"

Notification::Notification(std::string id, int userId, std::string message,
    std::string type, std::string channel)
    : notificationId(id), userId(userId), message(message),
    type(type), channel(channel), isRead(false), isSent(false),
    priority("normal"), retryCount(0), sentDate(nullptr), sentTime(nullptr) {
}

bool Notification::send() {
    if (!message.empty() && !isSent) {
        std::cout << "Sending notification to user " << userId << ": " << message << std::endl;
        isSent = true;
        return true;
    }
    return false;
}

bool Notification::markAsRead() {
    if (isSent) {
        isRead = true;
        return true;
    }
    return false;
}

bool Notification::retry() {
    if (retryCount < 3) {
        retryCount++;
        return send();
    }
    return false;
}

std::string Notification::getNotificationId() {
    return notificationId;
}

void Notification::setPriority(std::string newPriority) {
    priority = newPriority;
}

bool Notification::isHighPriority() {
    return priority == "high";
}

std::string Notification::getChannel() {
    return channel;
}