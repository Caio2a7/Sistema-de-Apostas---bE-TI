#include "UserService.h"
#include "../cli/index.h" 

optional<UserEntity> UserService::authUser(pqxx::connection* conn, string email, string password) {
    QueryMetaData queryMetaData;
    setTableName(&queryMetaData);

    pqxx::work w(*conn);
    email = w.quote(email); //Adicionando ' ' ao redor do email para conseguir efetuar a query
    w.commit();

    UserRepository userRepository;
    optional<pqxx::result> res = userRepository.findByEmail(conn, &queryMetaData, email);
    
    if (!res.has_value()) {
        altLinesFormat("Usuário não encontrado");
        return std::nullopt;
    }

    UserEntity user = userRepository.createEntityFromResult(res.value()[0]);

    if (!(password == user.getPassword())) {
        altLinesFormat("Senha não confere");
        return std::nullopt;
    }
    altLinesFormat("Usuário autenticado com sucesso");
    return user;
}

bool UserService::save(pqxx::connection *conn, UserEntity *user) {
    try{
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
        return true;
    } catch(runtime_error& erro){
        cerr << "Erro: " << erro.what() << endl;
        return false;
    }
}

void UserService::update(pqxx::connection *conn, UserEntity *user) {
    UserRepository userRepository;
    QueryMetaData queryMetaData;

    pqxx::work w(*conn);

    setTableName(&queryMetaData);
    queryMetaData.columns = user->getColumns();

    size_t userId = user->getId();

    std::vector<std::string> values;
    values.push_back(w.quote(userId));
    values.push_back(w.quote(user->getName()));
    values.push_back(w.quote(user->getEmail()));
    values.push_back(w.quote(user->getPassword()));
    values.push_back(w.quote(to_string(user->getRole())));
    values.push_back(w.quote(user->getBalance()));

    queryMetaData.values = values;

    w.commit();

    userRepository.update(conn, &queryMetaData, userId);
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

bool UserService::deposit(pqxx::connection *conn, UserEntity user) {
    double amount = depositAmount();

    if(amount <= 0) {
        altLinesFormat("VALOR DE DEPOSITO DEVE SER MAIOR QUE 0!");
        return false;
    }

    string sql = "UPDATE usuario SET saldo = saldo + " + conn->quote(amount) + " WHERE id = " + conn->quote(user.getId()) + ";";

    pqxx::result res = executeSql(conn, sql);

    if(res.affected_rows() > 0) {
        altLinesFormat("DEPOSITO REALIZADO COM SUCESSO");
        return true;
    }

    altLinesFormat("NAO FOI POSSIVEL REALIZAR SEU DEPOSITO");
    return false;
}

bool UserService::withdraw(pqxx::connection *conn, UserEntity user) {
    double amount = withdrawAmount();
    string sql = "UPDATE usuario SET saldo = saldo - " + conn->quote(amount) + " WHERE id = " + conn->quote(user.getId()) + ";";
    
    if(user.getBalance() - amount < 0) {
        altLinesFormat("Saldo insuficiente!");
        return false;
    } 

    pqxx::result res = executeSql(conn, sql);

    if(res.affected_rows() > 0) {
        altLinesFormat("Saque realizado com sucesso!");
        return true;
    }

    altLinesFormat("Nao foi possivel realizar seu saque");
    return false;
}

bool UserService::alreadyExists(pqxx::connection *conn, string email) {
    UserService userServices;
    optional<UserEntity> user = userServices.findByEmail(conn, email);

    if(user) {
        return true;
    }

    return false;
}

// Métodos Private

void UserService::setTableName(QueryMetaData *queryMetaData) {
    queryMetaData->tableName = to_string(TablesDataBaseEnum::usuario);
}