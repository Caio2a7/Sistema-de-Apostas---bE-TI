#ifndef USER_ROLE_ENUM_H
#define USER_ROLE_ENUM_H

#include <iostream>

using namespace std;

enum class UserRoleEnum {
    ADMIN,
    USUARIO
};

std::ostream& operator<<(std::ostream& os, UserRoleEnum color);

#endif 