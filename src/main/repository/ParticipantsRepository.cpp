#include "ParticipantsRepository.h"

// Vai construir a entidade usuário
ParticipantsEntity ParticipantsRepository::createEntityFromResult(const pqxx::row& row) {
    return ParticipantsEntity(
        row["id"].as<size_t>(), 
        row["nome"].as<std::string>(), 
        row["vitorias"].as<size_t>()
    );
}

// Vai processar o vetor do método findAll para construir as entidades
std::vector<ParticipantsEntity> ParticipantsRepository::processFindAll(pqxx::result res) {
    std::vector<ParticipantsEntity> results;
    try {
        for (const auto& row : res) {
            // Criação da entidade a partir da linha do resultado
            ParticipantsEntity entity = createEntityFromResult(row);
            results.push_back(entity);
        }
    } catch (const std::exception& e) {
        cerr << "Erro ao buscar registros: " << e.what() << endl;
    }

    return results;
}
