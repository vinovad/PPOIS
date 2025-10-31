#include "ContactInfo.h"

ContactInfo::ContactInfo(std::string email, std::string phoneNumber) :
    email(email), phoneNumber(phoneNumber) {
}

bool ContactInfo::isValid() {
    bool was = 0;
    for (int a = 0; a < email.size(); a++) {
        if (email[a] == '@') {
            was = 1;
            break;
        }
    }
    if (!was) {
        throw ContactInfoError("NOT VALID");
    }
    else {
        return 1;
    }
}