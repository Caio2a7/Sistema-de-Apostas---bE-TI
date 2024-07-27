#include "EventStatusEnum.h"

EventStatusEnum convertStringToEventStatusEnum(const std::string& string) {
    if (string == "AGENDADA") return EventStatusEnum::AGENDADA;
    if (string == "ANDAMENTO") return EventStatusEnum::ANDAMENTO;
    if (string == "FINALIZADA") return EventStatusEnum::FINALIZADA;
}


ostream& operator<<(ostream& os, EventStatusEnum status) {
    switch (status) {
        case EventStatusEnum::AGENDADA:
            os << "Agendada";
            break;
        case EventStatusEnum::ANDAMENTO:
            os << "Andamento";
            break;
        case EventStatusEnum::FINALIZADA:
            os << "Finalizada";
            break;
        default:
            os << "Status de evento não existe";
            break;
    }
    return os;
}

std::string to_string(EventStatusEnum status) {
    switch (status) {
        case EventStatusEnum::AGENDADA:
            return "AGENDADA";
        case EventStatusEnum::ANDAMENTO:
            return "ANDAMENTO";
        case EventStatusEnum::FINALIZADA:
            return "FINALIZADA";
    }
}