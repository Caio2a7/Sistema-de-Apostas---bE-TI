#include "BetService.h"

void BetService::save(pqxx::connection *conn, BetEntity *entity) {
    EventService eventService;
    BetRepository BetRepository;
    QueryMetaData queryMetaData;

    optional<EventEntity> eventEntity = eventService.findById(conn, entity->getEvent().getId());

    if (eventEntity.has_value()) {
        EventEntity event = eventEntity.value();

        if (!isDateValid(event.getTime())) {
            throw runtime_error("O evento não está mais disponível.");
        }
    }

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = entity->getColumns();

    vector<string> values;
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
        vector<BetEntity> value = processFindAll(conn, res.value());
        
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

    optional<UserEntity> optionalUser = userService.findById(conn, userId);
    optional<EventEntity> optionalEvent = eventService.findById(conn, eventId);

    if (!optionalUser) {
        cerr << "Usuário com ID " << userId << " não encontrado." << endl;
        throw runtime_error("Usuário não encontrado");
    }

    if (!optionalEvent) {
        cerr << "Evento com ID " << eventId << " não está cadastrado." << endl;
        throw runtime_error("Evento não encontrado");
    }

    string betValue = row["aposta"].as<string>();
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


tm BetService::convertStringToTm(const string& datetime) {
    tm tm = {};
    istringstream ss(datetime);
    ss >> get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return tm;
}

bool BetService::isDateValid(const string& dateStr) {
    tm returned_tm = convertStringToTm(dateStr);

    auto now = chrono::system_clock::now();
    auto now_time_t = chrono::system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_time_t);

    if (difftime(mktime(&returned_tm), mktime(&now_tm)) > 0) {
        return true;
    }

    return false;
}
