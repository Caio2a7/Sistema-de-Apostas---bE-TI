#ifndef ICRUDREPOSITORY_H
#define ICRUDREPOSITORY_H

#include <iostream>
#include <pqxx/pqxx>
#include <optional>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string>
#include "./utils/QueryBuilder.h"
#include "../enum/TablesDataBaseEnum.h"
#include "../infra/db/configure.h"

using namespace std;

template <typename T>
class ICrudRepository {
public:
    virtual ~ICrudRepository() = default;

    virtual string getCodeAutoIncrementId(T* entity) = 0;
    
    virtual void save(pqxx::connection* conn, QueryMetaData *queryMetaData);

    virtual void update(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id);
    
    optional<pqxx::result> findById(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id);

    optional<pqxx::result> findAll(pqxx::connection* conn, QueryMetaData *queryMetaData);
};

#endif
