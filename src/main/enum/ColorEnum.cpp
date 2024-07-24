#include "UserRoleEnum.h"

ostream& operator<<(ostream& os, UserRole color) {
    switch (color) {
        case UserRole::ADMIN:
            os << "ADMIN";
            break;
        case UserRole::USUARIO:
            os << "USUARIO";
            break;
        default:
            os << "ROLE NÃO EXISTE";
            break;
    }
    return os;
}