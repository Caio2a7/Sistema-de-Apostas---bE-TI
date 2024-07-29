#include "TypeOfBets.h"

std::ostream& operator<<(std::ostream& os, TypeOfBets typeBets) {
    switch (typeBets) {
        case TypeOfBets::VITORIA_TIME_A:
            os << "Vitória time A";
            break;
        case TypeOfBets::VITORIA_TIME_B:
            os << "Vitória time B";
            break;
        case TypeOfBets::EMPATE:
            os << "Empate";
            break;
    }
    return os;
}

std::string to_string(TypeOfBets typeBets) {
    switch (typeBets) {
        case TypeOfBets::VITORIA_TIME_A:
            return "VITORIA_TIME_A";
        case TypeOfBets::VITORIA_TIME_B:
            return "VITORIA_TIME_B";
        case TypeOfBets::EMPATE:
            return "EMPATE";
    }
}

TypeOfBets convertStringToTypeOfBetsEnum(const std::string& string) {
    if (string == "VITORIA_TIME_A") return TypeOfBets::VITORIA_TIME_A;
    if (string == "VITORIA_TIME_B") return TypeOfBets::VITORIA_TIME_B;
    if (string == "EMPATE") return TypeOfBets::EMPATE;
}