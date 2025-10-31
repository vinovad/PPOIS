#include "CreditCard.h"

CreditCard::CreditCard(std::string number, std::string holderName, std::string expiryDate, std::string cvv) :
    number(number), holderName(holderName), expiryDate(expiryDate), cvv(cvv) {
}

bool CreditCard::validate() {
    if (number.size() == 16 && !(expiryDate.empty()) && cvv.size() == 3) {
        return true;
    }
    else {
        throw CardError("ISN'T VALID");
    }
}

bool CreditCard::charge(double sum) {
    if (!this->validate()) {
        std::cout << "card " << number << "isn't validaty  " << std::endl;
        return 0;
    }
    std::cout << "charged " << sum << " from " << this->number << std::endl;
    return 1;
}