#ifndef TABLES_DATABASE_ENUM_H
#define TABLES_DATABASE_ENUM_H

#include <iostream>
#include <ostream>

using namespace std;

enum class TablesDataBaseEnum {
    usuario,
    esporte,
    participantes,
    apostas,
    eventos
};

std::ostream& operator<<(std::ostream& os, TablesDataBaseEnum tables);

std::string to_string(TablesDataBaseEnum role);

#endif