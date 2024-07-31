#ifndef BET_REPOSITORY_H
#define BET_REPOSITORY_H

#include <pqxx/pqxx>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <optional>
#include "CrudRepositoryImpl.h"
#include "../entities/BetEntity.h"
#include "../infra/db/configure.h"

using namespace std;

class BetRepository : public CrudRepositoryImpl<BetEntity> {
    public:
        virtual ~BetRepository() = default;

        optional<pqxx::result> findAllByEventId(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id);
};

#endif
