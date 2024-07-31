#include "BetRepository.h"

optional<pqxx::result> BetRepository::findAllByEventId(pqxx::connection* conn, QueryMetaData *queryMetaData, size_t id) {
    QueryBuilder queryBuilder;
    std::string query = queryBuilder.buildFindAllByEventIdQuery(queryMetaData, id);

    pqxx::result res =  executeSql(conn, query);

    if (res.empty()) {
        return std::nullopt;
    }

    return res;
}