#include "EventService.h"


// Para o horário conseguir ser salvo no banco de dados ele tem que seguir o padrão abaixo
// ano-mes-dia hora:minutos:segundos.centesimos
// 2024-07-26 23:20:02.818
void EventService::save(pqxx::connection *conn, EventEntity *entity) {
    EventRepository EventRepository;
    QueryMetaData queryMetaData;
    QueryBuilder queryBuilder;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = entity->getColumns();

    std::array<double, 3> arr = entity->getOdds();

    std::vector<double> vec(arr.begin(), arr.end());
    
    std::string valueOdds = queryBuilder.buildValueArray(vec);

    std::vector<std::string> values;
    values.push_back(EventRepository.getCodeAutoIncrementId(entity));
    values.push_back(w.quote(entity->getSport().getId()));
    values.push_back(w.quote(entity->getTeamA().getId()));
    values.push_back(w.quote(entity->getTeamB().getId()));
    values.push_back(w.quote(valueOdds));
    values.push_back(w.quote(entity->getTime()));
    values.push_back(w.quote(to_string(entity->getStatus())));

    queryMetaData.values = values;

    w.commit();

    EventRepository.save(conn, &queryMetaData);
}

optional<EventEntity> EventService::findById(pqxx::connection *conn, size_t id) {
    EventRepository eventRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = eventRepository.findById(conn, &queryMetaData, id);
    
    if (res.has_value()) {
        EventEntity value = createEntityFromResult(conn, res.value()[0]);
        
        return value; 
    } 

    return nullopt;
 }

optional<vector<EventEntity>> EventService::findAll(pqxx::connection *conn) {
    EventRepository eventRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = eventRepository.findAll(conn, &queryMetaData);

    if (res.has_value()) {
        std::vector<EventEntity> value = processFindAll(conn, res.value());
        
        return value;
    } 

    return nullopt;
}

// Métodos privados

void EventService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::eventos);
}

EventEntity EventService::createEntityFromResult(pqxx::connection *conn, const pqxx::row& row) {
    SportService sportService;
    ParticipantsService participantsService;

    auto sportId = row["id_esporte"].as<int>();
    auto teamAId = row["id_time_a"].as<int>();
    auto teamBId = row["id_time_b"].as<int>();

    std::optional<SportEntity> optionalSport = sportService.findById(conn, sportId);
    std::optional<ParticipantsEntity> optionalTeamA = participantsService.findById(conn, teamAId);
    std::optional<ParticipantsEntity> optionalTeamB = participantsService.findById(conn, teamBId);

    if (!optionalSport) {
        std::cerr << "Esporte com ID " << sportId << " não encontrado." << std::endl;
        throw std::runtime_error("Esporte não encontrado");
    }

    if (!optionalTeamA) {
        std::cerr << "Time A com ID " << teamAId << " não está cadastrado." << std::endl;
        throw std::runtime_error("Time A não encontrado");
    }

    if (!optionalTeamB) {
        std::cerr << "Time B com ID " << teamBId << " não está cadastrado." << std::endl;
        throw std::runtime_error("Time B não encontrado");
    }

    std::string statusValue = row["status"].as<std::string>();
    EventStatusEnum statusEnum = convertStringToEventStatusEnum(statusValue);

    std::string stringOdds = row["odds"].as<std::string>();
    std::cout << "Valor das ODDS: " << stringOdds << std::endl;

    std::array<double, 3> odds = parseNumbers(stringOdds);

    return EventEntity(
        row["id"].as<size_t>(), 
        optionalSport.value(),
        optionalTeamA.value(),
        optionalTeamB.value(),
        odds, 
        row["horario"].as<string>(),
        statusEnum
    );
}

// Vai processar o vetor do método findAll para construir as entidades
vector<EventEntity> EventService::processFindAll(pqxx::connection *conn, pqxx::result res) {
    vector<EventEntity> results;
    try {
        for (const auto& row : res) {
            // Criação da entidade a partir da linha do resultado
            EventEntity entity = createEntityFromResult(conn, row);
            results.push_back(entity);
        }
    } catch (const exception& e) {
        cerr << "Erro ao buscar registros: " << e.what() << endl;
    }

    return results;
}

// As odds serão retornadas do banco de dados nesse formato {n1,n2,n3}
// Esse método irá pegar apenas os valores, adicioná-los em um array
// e retornar esse array
std::array<double, 3> EventService::parseNumbers(const std::string& str) {
    std::array<double, 3> numbers;
    std::string cleanedStr;
    size_t index = 0;

    for (char ch : str) {
        // Remove caracteres '{', '}', e ','
        if (ch != '{' && ch != '}' && ch != ',') {
            cleanedStr += ch;
        } else if (!cleanedStr.empty()) {
            std::stringstream ss(cleanedStr);
            double num;
            ss >> num;
            numbers[index++] = num;
            cleanedStr.clear();
        }
    }

    // Add the last number if there's any
    if (!cleanedStr.empty() && index < numbers.size()) {
        std::stringstream ss(cleanedStr);
        double num;
        ss >> num;
        numbers[index] = num;
    }

    return numbers;
}