#include "ParticipantsService.h"

void ParticipantsService::save(pqxx::connection *conn, ParticipantsEntity *entity) {
    ParticipantsRepository participantsRepository;
    QueryMetaData queryMetaData;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = entity->getColumns();

    std::vector<std::string> values;
    values.push_back(participantsRepository.getCodeAutoIncrementId(entity));
    values.push_back(w.quote(entity->getName()));
    values.push_back(w.quote(entity->getVictorys()));

    queryMetaData.values = values;

    w.commit();

    participantsRepository.save(conn, &queryMetaData);
}

optional<ParticipantsEntity> ParticipantsService::findById(pqxx::connection *conn, size_t id) {
    ParticipantsRepository participantsRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = participantsRepository.findById(conn, &queryMetaData, id);
    
    if (res.has_value()) {
        ParticipantsEntity value = participantsRepository.createEntityFromResult(res.value()[0]);
        
        return value; 
    } 

    return nullopt;
 }

optional<vector<ParticipantsEntity>> ParticipantsService::findAll(pqxx::connection *conn) {
    ParticipantsRepository participantsRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = participantsRepository.findAll(conn, &queryMetaData);

    if (res.has_value()) {
        std::vector<ParticipantsEntity> value = participantsRepository.processFindAll(res.value());
        
        return value;
    } 

    return nullopt;
}

// Métodos Private

void ParticipantsService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::participantes);
}
