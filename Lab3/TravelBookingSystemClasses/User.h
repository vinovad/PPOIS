#pragma once
#include <iostream>
#include "AuthExceptions.h"

class User {
    int getHash(std::string password);
    int passwordHash;
public:
    std::string whoami;
    std::string name;
    const int id;

    User(std::string name, std::string password, int id = 0);
    bool login(std::string password);
    bool editPassword(std::string currentPassword, std::string newPassword);
    bool editName(std::string newName, std::string password);
};