#pragma once
#include <iostream>
#include <string>
#include <map> 

class Currency {
private:
    std::string currencyCode;
    std::map<std::string, double> exchangeRates;

public:
    std::string name;
    std::string symbol;
    std::string country;
    double baseRate;
    int decimalPlaces;
    bool isActive;

    Currency(std::string code, std::string name, std::string symbol,
        std::string country, double rate);
    double convert(double amount, std::string toCurrency);
    void setExchangeRate(std::string targetCurrency, double rate);
    double getExchangeRate(std::string targetCurrency);
    std::string getCurrencyCode();
    std::string format(double amount);
    bool isSupported(std::string targetCurrency);
    void updateBaseRate(double newRate);
    int getRateCount();
};