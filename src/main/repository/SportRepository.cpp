#include "SportRepository.h"

// Vai construir a entidade usuário
SportEntity SportRepository::createEntityFromResult(const pqxx::row& row) {
    return SportEntity(
        row["id"].as<size_t>(), 
        row["nome"].as<std::string>(), 
        row["tipo"].as<std::string>()
    );
}

// Vai processar o vetor do método findAll para construir as entidades
std::vector<SportEntity> SportRepository::processFindAll(pqxx::result res) {
    std::vector<SportEntity> results;
    try {
        for (const auto& row : res) {
            // Criação da entidade a partir da linha do resultado
            SportEntity entity = createEntityFromResult(row);
            results.push_back(entity);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao buscar registros: " << e.what() << endl;
    }

    return results;
}
