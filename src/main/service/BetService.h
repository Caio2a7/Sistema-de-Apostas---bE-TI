#ifndef BET_SERVICE_H
#define BET_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <optional>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <pqxx/pqxx>
#include "EventService.h"
#include "UserService.h"
#include "ParticipantsService.h"
#include "../repository/BetRepository.h"
#include "../entities/BetEntity.h"
#include "../entities/EventEntity.h"
#include "../entities/UserEntity.h"
#include "../entities/ParticipantsEntity.h"
#include "../enum/TypeOfBets.h"

using namespace std;

class BetService {
public:
    void save(pqxx::connection *conn, BetEntity *entity);

    optional<BetEntity> findById(pqxx::connection *conn, size_t id);

    optional<vector<BetEntity>> findAll(pqxx::connection *conn);

    optional<vector<BetEntity>> findAllByEventId(pqxx::connection *conn, size_t id);

    void closeBet(pqxx::connection *conn, size_t idEvent, TypeOfBets eventResult);

private:
    void setTableName(QueryMetaData *queryMetaData);

    BetEntity createEntityFromResult(pqxx::connection *conn, const pqxx::row& row);

    vector<BetEntity> processFindAll(pqxx::connection *conn, pqxx::result res);

    tm convertStringToTm(const string& datetime);

    bool isDateValid(const string& dateStr);
};

#endif
