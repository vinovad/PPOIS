#include "Payment.h"

Payment::Payment(std::string transId, int bookingId, double amount,
    std::string method, std::string currency, int custId)
    : transactionId(transId), bookingId(bookingId), amount(amount),
    paymentMethod(method), currency(currency), customerId(custId),
    status("pending"), creditCard(nullptr), paymentDate(nullptr) {
}

bool Payment::processPayment() {
    if (amount > 0 && !paymentMethod.empty()) {
        if (paymentMethod == "credit_card" && creditCard != nullptr) {
            if (creditCard->charge(amount)) {
                status = "completed";
                return true;
            }
        }
        else {
            status = "completed";
            return true;
        }
    }
    status = "failed";
    return false;
}

bool Payment::refund() {
    if (status == "completed") {
        status = "refunded";
        std::cout << "Refunded: " << amount << " " << currency << std::endl;
        return true;
    }
    return false;
}

std::string Payment::getTransactionId() {
    return transactionId;
}

std::string Payment::generateReceipt() {
    receiptNumber = "RCP_" + transactionId;
    return receiptNumber;
}

bool Payment::isSuccessful() {
    return status == "completed";
}

std::string Payment::getStatus() {
    return status;
}

void Payment::setCreditCard(CreditCard* card) {
    creditCard = card;
}