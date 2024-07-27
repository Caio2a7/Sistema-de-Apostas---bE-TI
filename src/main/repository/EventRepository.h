#ifndef EVENT_REPOSITORY_H
#define EVENT_REPOSITORY_H

#include <pqxx/pqxx>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <optional>
#include "CrudRepositoryImpl.h"
#include "../entities/EventEntity.h"
#include "../infra/db/configure.h"

using namespace std;

class EventRepository : public CrudRepositoryImpl<EventEntity> {
    public:
        virtual ~EventRepository() = default;
};

#endif
