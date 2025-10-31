#include "Currency.h"

Currency::Currency(std::string code, std::string name, std::string symbol,
    std::string country, double rate)
    : currencyCode(code), name(name), symbol(symbol), country(country),
    baseRate(rate), decimalPlaces(2), isActive(true) {
}

double Currency::convert(double amount, std::string toCurrency) {
    if (exchangeRates.find(toCurrency) != exchangeRates.end()) {
        return amount * exchangeRates[toCurrency];
    }
    return amount;
}

void Currency::setExchangeRate(std::string targetCurrency, double rate) {
    exchangeRates[targetCurrency] = rate;
}

double Currency::getExchangeRate(std::string targetCurrency) {
    if (exchangeRates.find(targetCurrency) != exchangeRates.end()) {
        return exchangeRates[targetCurrency];
    }
    return 0.0;
}

std::string Currency::getCurrencyCode() {
    return currencyCode;
}

std::string Currency::format(double amount) {
    return symbol + std::to_string(amount);
}

bool Currency::isSupported(std::string targetCurrency) {
    return exchangeRates.find(targetCurrency) != exchangeRates.end();
}

void Currency::updateBaseRate(double newRate) {
    baseRate = newRate;
}

int Currency::getRateCount() {
    return exchangeRates.size();
}