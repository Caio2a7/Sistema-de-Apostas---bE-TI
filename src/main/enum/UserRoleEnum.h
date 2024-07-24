#ifndef COLORENUM_H
#define COLORENUM_H

#include <iostream>

using namespace std;

enum class UserRole {
    ADMIN,
    USUARIO
};

std::ostream& operator<<(std::ostream& os, UserRole color);

#endif 