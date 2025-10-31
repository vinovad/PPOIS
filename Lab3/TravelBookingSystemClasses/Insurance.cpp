#include "Insurance.h"

Insurance::Insurance(std::string policy, std::string provider, std::string coverage,
    double amount, double premium, int custId)
    : policyNumber(policy), provider(provider), coverageType(coverage),
    coverageAmount(amount), premium(premium), customerId(custId),
    isActive(true), startDate(nullptr), endDate(nullptr) {
}

bool Insurance::isValidPolicy() {
    return !policyNumber.empty() && isActive;
}

double Insurance::calculatePremium(int days) {
    return premium * days;
}

bool Insurance::fileClaim(double amount) {
    if (amount <= coverageAmount && isActive) {
        std::cout << "Claim filed for: " << amount << std::endl;
        return true;
    }
    return false;
}

void Insurance::cancelPolicy() {
    isActive = false;
}

void Insurance::renewPolicy() {
    isActive = true;
}

std::string Insurance::getPolicyNumber() {
    return policyNumber;
}

std::string Insurance::getProvider() {
    return provider;
}

double Insurance::getRemainingCoverage() {
    return coverageAmount;
}