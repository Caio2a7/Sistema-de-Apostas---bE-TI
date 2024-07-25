#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <pqxx/pqxx>
#include <vector>
#include <string>
#include <sstream>
#include <optional>
#include "../entities/UserEntity.h"
#include "../infra/db/configure.h"
#include "CrudRepositoryImpl.h"

using namespace std;

class UserRepository : public CrudRepositoryImpl<UserEntity> {
    public:
        virtual ~UserRepository() = default;

        UserEntity createEntityFromResult(const pqxx::row& row);

        std::vector<UserEntity> processFindAll(pqxx::result res);

        optional<pqxx::result> findByEmail(pqxx::connection* conn, QueryMetaData *metaData, const string& email);
};



#endif