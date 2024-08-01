#ifndef CRUD_REPOSITORY_IMPL_H
#define CRUD_REPOSITORY_IMPL_H

#include "ICrudRepository.h"

template <typename T>
class CrudRepositoryImpl : public ICrudRepository<T> {
public:
    string getCodeAutoIncrementId(T* entity)  {
        ostringstream tableSeq;
        ostringstream oss;
        tableSeq << entity->getTable() << "_id_seq";
        oss << "nextval('" << tableSeq.str() << "'::regclass)";
        return oss.str();
    }

    void save(pqxx::connection* conn, QueryMetaData *queryMetaData)  {
        QueryBuilder queryBuilder;
        std::string query = queryBuilder.buildInsertQuery(queryMetaData);

        executeSql(conn, query);
    }

    void update(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id) {
        QueryBuilder QueryBuilder;
        std::string query = QueryBuilder.buildUpdateQuery(queryMetaData, id);

        executeSql(conn, query);
    }

    optional<pqxx::result> findById(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id) {
        QueryBuilder queryBuilder;
        std::string query = queryBuilder.buildFindByIdQuery(queryMetaData, id);

        pqxx::result res =  executeSql(conn, query);

        if (res.empty()) {
            return std::nullopt;
        }

        return res;
    }

    optional<pqxx::result> findAll(pqxx::connection* conn, QueryMetaData *queryMetaData) {
        QueryBuilder queryBuilder;
        std::string query = queryBuilder.buildFindAllQuery(queryMetaData);

        pqxx::result res =  executeSql(conn, query);

        if (res.empty()) {
            return std::nullopt;
        }

        return res;
    }
};

#endif