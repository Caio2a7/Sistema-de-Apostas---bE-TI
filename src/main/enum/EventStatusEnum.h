#ifndef EVENT_STATUS_ENUM_H
#define EVENT_STATUS_ENUM_H

#include <iostream>

using namespace std;

enum class EventStatusEnum {
    AGENDADA,
    ANDAMENTO,
    FINALIZADA
};

std::ostream& operator<<(std::ostream& os, EventStatusEnum color);

#endif