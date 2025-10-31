#include "Refund.h"

Refund::Refund(std::string id, int paymentId, double amount, std::string reason)
    : refundId(id), paymentId(paymentId), amount(amount), reason(reason),
    status("pending"), processingDays(7), isApproved(false),
    originalPayment(nullptr), refundDate(nullptr) {
}

bool Refund::approve() {
    if (!isApproved && status == "pending") {
        isApproved = true;
        status = "approved";
        return true;
    }
    return false;
}

bool Refund::reject() {
    if (status == "pending") {
        status = "rejected";
        return true;
    }
    return false;
}

bool Refund::process() {
    if (isApproved && status == "approved") {
        status = "processed";
        std::cout << "Refund processed: " << amount << std::endl;
        return true;
    }
    return false;
}

std::string Refund::getRefundId() {
    return refundId;
}

std::string Refund::getStatus() {
    return status;
}

int Refund::getProcessingDays() {
    return processingDays;
}

void Refund::expediteProcessing() {
    processingDays = 3;
}

bool Refund::isComplete() {
    return status == "processed";
}