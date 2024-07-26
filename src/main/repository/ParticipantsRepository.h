#ifndef PARTICIPANTS_REPOSITORY_H
#define PARTICIPANTS_REPOSITORY_H

#include <pqxx/pqxx>
#include <vector>
#include <string>
#include <sstream>
#include <optional>
#include "../entities/ParticipantsEntity.h"
#include "../infra/db/configure.h"
#include "CrudRepositoryImpl.h"

using namespace std;

class ParticipantsRepository : public CrudRepositoryImpl<ParticipantsEntity> {
    public:
        virtual ~ParticipantsRepository() = default;

        ParticipantsEntity createEntityFromResult(const pqxx::row& row);

        std::vector<ParticipantsEntity> processFindAll(pqxx::result res);
};



#endif
