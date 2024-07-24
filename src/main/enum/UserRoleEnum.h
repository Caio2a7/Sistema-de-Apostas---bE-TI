#ifndef USER_ROLE_ENUM_H
#define USER_ROLE_ENUM_H

#include <iostream>

using namespace std;

enum class UserRole {
    ADMIN,
    USUARIO
};

std::ostream& operator<<(std::ostream& os, UserRole color);

#endif 