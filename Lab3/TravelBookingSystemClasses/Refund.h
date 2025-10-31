#pragma once
#include <iostream>
#include <string>
#include "Payment.h"
#include "Date.h"

class Refund {
private:
    std::string refundId;
    Date* refundDate;

public:
    int paymentId;
    double amount;
    std::string reason;
    std::string status;
    std::string refundMethod;
    int processingDays;
    bool isApproved;
    Payment* originalPayment;

    Refund(std::string id, int paymentId, double amount, std::string reason);
    bool approve();
    bool reject();
    bool process();
    std::string getRefundId();
    std::string getStatus();
    int getProcessingDays();
    void expediteProcessing();
    bool isComplete();
};