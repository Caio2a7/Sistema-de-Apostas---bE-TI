#include "UserService.h"

optional<UserEntity> UserService::authUser(pqxx::connection* conn, string email, string password) {
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    pqxx::work w(*conn);
    email = w.quote(email); //Adicionando ' ' ao redor do email para conseguir efetuar a query
    w.commit();

    UserRepository userRepository;
    optional<pqxx::result> res = userRepository.findByEmail(conn, &queryMetaData, email);
    
    if (!res.has_value()) {
        cerr << "Usuário não encontrado" << endl;
        return std::nullopt;
    }

    UserEntity user = userRepository.createEntityFromResult(res.value()[0]);

    if (!(password == user.getPassword())) {
        cerr << "Senha não confere" << endl;
        return std::nullopt;
    }

    cout << "Usuário autenticado com sucesso" << endl;

    return user;
}

void UserService::save(pqxx::connection *conn, UserEntity *user) {
    UserRepository userRepository;
    QueryMetaData queryMetaData;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = user->getColumns();

    std::vector<std::string> values;
    values.push_back(userRepository.getCodeAutoIncrementId(user));
    values.push_back(w.quote(user->getName()));
    values.push_back(w.quote(user->getEmail()));
    values.push_back(w.quote(user->getPassword()));
    values.push_back(w.quote(to_string(user->getRole())));
    values.push_back(w.quote(user->getBalance()));

    queryMetaData.values = values;

    w.commit();

    userRepository.save(conn, &queryMetaData);
}

optional<UserEntity> UserService::findById(pqxx::connection *conn, size_t id) {
    UserRepository userRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = userRepository.findById(conn, &queryMetaData, id);
    
    if (res.has_value()) {
        UserEntity value = userRepository.createEntityFromResult(res.value()[0]);
        
        return value; 
    } 

    return nullopt;
 }

optional<UserEntity> UserService::findByEmail(pqxx::connection *conn, const string& email) {
    UserRepository userRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    pqxx::work w(*conn);
    std::string emailQuote = w.quote(email);
    w.commit();

    optional<pqxx::result> res = userRepository.findByEmail(conn, &queryMetaData, emailQuote);
    
    if (res.has_value()) {
        UserEntity value = userRepository.createEntityFromResult(res.value()[0]);
        
        return value; 
    } 

    return nullopt;
}

optional<vector<UserEntity>> UserService::findAll(pqxx::connection *conn) {
    UserRepository userRepository;
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    optional<pqxx::result> res = userRepository.findAll(conn, &queryMetaData);

    if (res.has_value()) {
        std::vector<UserEntity> value = userRepository.processFindAll(res.value());
        
        return value;
    } 

    return nullopt;
}

// Métodos Private

void UserService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::usuario);
}