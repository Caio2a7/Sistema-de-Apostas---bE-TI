#include "UserRepository.h"

// Vai construir a entidade usuário
UserEntity UserRepository::createEntityFromResult(const pqxx::row& row) {
    std::string cargoValue = row["cargo"].as<std::string>();
    UserRoleEnum cargoEnum = convertStringToRoleEnum(cargoValue);

    return UserEntity(
        row["id"].as<size_t>(), 
        row["nome"].as<std::string>(), 
        row["email"].as<std::string>(), 
        row["senha"].as<std::string>(), 
        cargoEnum,
        row["saldo"].as<double>()
    );
}

// Vai processar o vetor do método findAll para construir as entidades
std::vector<UserEntity> UserRepository::processFindAll(pqxx::result res) {
    std::vector<UserEntity> results;
    try {
        for (const auto& row : res) {
            // Criação da entidade a partir da linha do resultado
            UserEntity entity = createEntityFromResult(row);
            results.push_back(entity);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao buscar registros: " << e.what() << endl;
    }

    return results;
}

optional<pqxx::result> UserRepository::findByEmail(pqxx::connection* conn, QueryMetaData * metaData, 
                            const string& email) {
    try {
        QueryBuilder queryBuilder;
        string query = queryBuilder.buildFindByEmailQuery(metaData, email);

        pqxx::result res = executeSql(conn, query);
        if(res.empty()){
            return std::nullopt;
        }

        return res;
    } catch (const pqxx::sql_error& e) {
        std::cerr << "Erro ao executar a consulta: " << e.what() << std::endl;
        std::cerr << "Consulta: " << e.query() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
    }

    return nullopt;
}   
