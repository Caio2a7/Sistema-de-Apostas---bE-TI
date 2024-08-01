#ifndef PARTICIPANTS_SERVICE_H
#define PARTICIPANTS_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <pqxx/pqxx>
#include "../repository/ParticipantsRepository.h"
#include "../entities/ParticipantsEntity.h"

using namespace std;

class ParticipantsService {
    public:
        void save(pqxx::connection *conn, ParticipantsEntity *entity);

        void update(pqxx::connection *conn, ParticipantsEntity *Participants);
        
        optional<ParticipantsEntity> findById(pqxx::connection *conn, size_t id);
        
        optional<vector<ParticipantsEntity>> findAll(pqxx::connection *conn);

    private:
        void setTableName(QueryMetaData *queryMetaData);
};

#endif
