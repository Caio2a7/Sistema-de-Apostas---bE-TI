#ifndef SPORT_SERVICE_H
#define SPORT_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <pqxx/pqxx>
#include "../repository/SportRepository.h"
#include "../entities/SportEntity.h"

using namespace std;

class SportService {
    public:
        void save(pqxx::connection *conn, SportEntity *entity);
        
        optional<SportEntity> findById(pqxx::connection *conn, size_t id);
        
        optional<vector<SportEntity>> findAll(pqxx::connection *conn);

    private:
        void setTableName(QueryMetaData *queryMetaData);
};

#endif
