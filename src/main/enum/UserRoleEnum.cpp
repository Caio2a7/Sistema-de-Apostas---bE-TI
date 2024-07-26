#include "UserRoleEnum.h"

ostream& operator<<(ostream& os, UserRoleEnum color) {
    switch (color) {
        case UserRoleEnum::ADMIN:
            os << "ADMIN";
            break;
        case UserRoleEnum::USUARIO:
            os << "USUARIO";
            break;
        default:
            os << "ROLE NÃO EXISTE";
            break;
    }
    return os;
}

UserRoleEnum convertStringToRole(const std::string& string) {
    if (string == "ADMIN") return UserRoleEnum::ADMIN;
    if (string == "USUARIO") return UserRoleEnum::USUARIO;
}

std::string to_string(UserRoleEnum role) {
    switch (role) {
        case UserRoleEnum::ADMIN:
            return "ADMIN";
        case UserRoleEnum::USUARIO:
            return "USUARIO";
    }
}