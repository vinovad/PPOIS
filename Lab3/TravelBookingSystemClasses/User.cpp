#include "User.h"

int User::getHash(std::string password) {
    int sum = 0;
    for (int i = 0; i < password.size(); i++) {
        sum += (int)password[i];
    }
    return sum % 512;
}

User::User(std::string name, std::string password, int id) : name(name), id(id) {
    passwordHash = getHash(password);
}

bool User::login(std::string password) {
    try {
        if (getHash(password) == this->passwordHash) {
            return true;
        }
        else {
            throw AuthException("WRONG PASSWORD");
        }
    }
    catch (AuthException error) {
        std::cout << "ERROR" << error.getError() << std::endl;
        return false;
    }
}

bool User::editPassword(std::string currentPassword, std::string newPassword) {
    if (getHash(currentPassword) == this->passwordHash) {
        this->passwordHash = getHash(newPassword);
        return true;
    }
    return false;
}

bool User::editName(std::string newName, std::string password) {
    if (getHash(password) == this->passwordHash) {
        this->name = newName;
        return true;
    }
    return false;
}