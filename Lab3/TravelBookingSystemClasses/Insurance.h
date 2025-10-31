#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Insurance {
private:
    std::string policyNumber;
    std::string provider;
    Date* startDate;
    Date* endDate;

public:
    std::string coverageType;
    double coverageAmount;
    double premium;
    std::string beneficiary;
    bool isActive;
    int customerId;

    Insurance(std::string policy, std::string provider, std::string coverage,
        double amount, double premium, int custId);
    bool isValidPolicy();
    double calculatePremium(int days);
    bool fileClaim(double amount);
    void cancelPolicy();
    void renewPolicy();
    std::string getPolicyNumber();
    std::string getProvider();
    double getRemainingCoverage();
};