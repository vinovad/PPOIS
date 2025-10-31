#pragma once
#include <iostream>
#include <string>
#include "CreditCard.h"
#include "Date.h"

class Payment {
private:
    std::string transactionId;
    Date* paymentDate;

public:
    int bookingId;
    double amount;
    std::string paymentMethod;
    std::string status;
    std::string currency;
    CreditCard* creditCard;
    int customerId;
    std::string receiptNumber;

    Payment(std::string transId, int bookingId, double amount,
        std::string method, std::string currency, int custId);
    bool processPayment();
    bool refund();
    std::string getTransactionId();
    std::string generateReceipt();
    bool isSuccessful();
    std::string getStatus();
    void setCreditCard(CreditCard* card);
};