#include "EventStatusEnum.h"

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