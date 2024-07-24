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