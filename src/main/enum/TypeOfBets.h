#ifndef TIPOS_DE_APOSTAS
#define TIPOS_DE_APOSTAS

#include <iostream>
#include <ostream>

enum class TypeOfBets {
    VITORIA_TIME_A,
    VITORIA_TIME_B,
    EMPATE
};

std::ostream& operator<<(std::ostream& os, TypeOfBets typeBets);

std::string to_string(TypeOfBets typeBets);

TypeOfBets convertStringToTypeOfBetsEnum(const std::string& string);

#endif