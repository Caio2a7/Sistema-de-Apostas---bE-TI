#include "SportService.h"

void SportService::save(pqxx::connection *conn, SportEntity *entity) {
    SportRepository sportRepository;
    QueryMetaData queryMetaData;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = entity->getColumns();

    std::vector<std::string> values;
    values.push_back(sportRepository.getCodeAutoIncrementId(entity));
    values.push_back(w.quote(entity->getName()));
    values.push_back(w.quote(entity->getType()));

    queryMetaData.values = values;

    w.commit();

    sportRepository.save(conn, &queryMetaData);
}

optional<SportEntity> SportService::findById(pqxx::connection *conn, size_t id) {
    SportRepository sportRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = sportRepository.findById(conn, &queryMetaData, id);
    
    if (res.has_value()) {
        SportEntity value = sportRepository.createEntityFromResult(res.value()[0]);
        
        return value; 
    } 

    return nullopt;
 }

optional<vector<SportEntity>> SportService::findAll(pqxx::connection *conn) {
    SportRepository sportRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = sportRepository.findAll(conn, &queryMetaData);

    if (res.has_value()) {
        std::vector<SportEntity> value = sportRepository.processFindAll(res.value());
        
        return value;
    } 

    return nullopt;
}

// Métodos Private

void SportService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::esporte);
}
