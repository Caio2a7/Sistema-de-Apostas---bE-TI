#include "BetService.h"

void BetService::save(pqxx::connection *conn, BetEntity *entity) {
    BetRepository BetRepository;
    QueryMetaData queryMetaData;
    QueryBuilder queryBuilder;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = entity->getColumns();

    std::vector<std::string> values;
    values.push_back(BetRepository.getCodeAutoIncrementId(entity));
    values.push_back(w.quote(entity->getUser().getId()));
    values.push_back(w.quote(entity->getEvent().getId()));
    values.push_back(w.quote(entity->getAmount()));
    values.push_back(w.quote(to_string(entity->getBet())));

    queryMetaData.values = values;

    w.commit();

    BetRepository.save(conn, &queryMetaData);
}

optional<BetEntity> BetService::findById(pqxx::connection *conn, size_t id) {
    BetRepository BetRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = BetRepository.findById(conn, &queryMetaData, id);
    
    if (res.has_value()) {
        BetEntity value = createEntityFromResult(conn, res.value()[0]);
        
        return value; 
    } 

    return nullopt;
 }

optional<vector<BetEntity>> BetService::findAll(pqxx::connection *conn) {
    BetRepository BetRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = BetRepository.findAll(conn, &queryMetaData);

    if (res.has_value()) {
        std::vector<BetEntity> value = processFindAll(conn, res.value());
        
        return value;
    } 

    return nullopt;
}

// Métodos privados

void BetService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::apostas);
}

BetEntity BetService::createEntityFromResult(pqxx::connection *conn, const pqxx::row& row) {
    UserService userService;
    EventService eventService;

    int userId = row["id_usuario"].as<int>();
    int eventId = row["id_evento"].as<int>();

    std::optional<UserEntity> optionalUser = userService.findById(conn, userId);
    std::optional<EventEntity> optionalEvent = eventService.findById(conn, eventId);

    if (!optionalUser) {
        std::cerr << "Usuário com ID " << userId << " não encontrado." << std::endl;
        throw std::runtime_error("Usuário não encontrado");
    }

    if (!optionalEvent) {
        std::cerr << "Evento com ID " << eventId << " não está cadastrado." << std::endl;
        throw std::runtime_error("Evento não encontrado");
    }

    std::string betValue = row["aposta"].as<std::string>();
    TypeOfBets statusEnum = convertStringToTypeOfBetsEnum(betValue);

    return BetEntity(
        row["id"].as<size_t>(), 
        optionalUser.value(),
        optionalEvent.value(),
        row["valor"].as<double>(), 
        statusEnum
    );
}

// Vai processar o vetor do método findAll para construir as entidades
vector<BetEntity> BetService::processFindAll(pqxx::connection *conn, pqxx::result res) {
    vector<BetEntity> results;
    try {
        for (const auto& row : res) {
            // Criação da entidade a partir da linha do resultado
            BetEntity entity = createEntityFromResult(conn, row);
            results.push_back(entity);
        }
    } catch (const exception& e) {
        cerr << "Erro ao buscar registros: " << e.what() << endl;
    }

    return results;
}

