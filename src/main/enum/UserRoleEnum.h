#ifndef USER_ROLE_ENUM_H
#define USER_ROLE_ENUM_H

#include <iostream>

using namespace std;

enum class UserRoleEnum {
    ADMIN,
    USUARIO
};

UserRoleEnum convertStringToRoleEnum(const std::string& string);

std::ostream& operator<<(std::ostream& os, UserRoleEnum color);

std::string to_string(UserRoleEnum role);

#endif 