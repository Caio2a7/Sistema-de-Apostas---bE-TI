#include "TablesDataBaseEnum.h"

std::ostream& operator<<(std::ostream& os, TablesDataBaseEnum tables) {
    switch (tables) {
        case TablesDataBaseEnum::usuario:
            os << "usuario";
            break;
        case TablesDataBaseEnum::esporte:
            os << "esporte";
            break;
        case TablesDataBaseEnum::participantes:
            os << "participantes";
            break;
        case TablesDataBaseEnum::apostas:
            os << "apostas";
            break;
        case TablesDataBaseEnum::eventos:
            os << "eventos";
            break;
        default:
            os << "Tabela não existe";
            break;
    }
    return os;
}

std::string to_string(TablesDataBaseEnum tables) {
    switch (tables) {
        case TablesDataBaseEnum::usuario:
            return "usuario";
        case TablesDataBaseEnum::esporte:
            return "esporte";
        case TablesDataBaseEnum::participantes:
            return "participantes";
        case TablesDataBaseEnum::apostas:
            return "apostas";
        case TablesDataBaseEnum::eventos:
            return "eventos";
    }
}