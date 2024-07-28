#ifndef EVENT_SERVICE_H
#define EVENT_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <optional>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>
#include <pqxx/pqxx>
#include "SportService.h"
#include "ParticipantsService.h"
#include "../repository/EventRepository.h"
#include "../entities/EventEntity.h"

using namespace std;

class EventService {
public:
    void save(pqxx::connection *conn, EventEntity *entity);

    optional<EventEntity> findById(pqxx::connection *conn, size_t id);

    optional<vector<EventEntity>> findAll(pqxx::connection *conn);

private:
    void setTableName(QueryMetaData *queryMetaData);

    EventEntity createEntityFromResult(pqxx::connection *conn, const pqxx::row& row);

    std::vector<EventEntity> processFindAll(pqxx::connection *conn, pqxx::result res);
};

#endif
