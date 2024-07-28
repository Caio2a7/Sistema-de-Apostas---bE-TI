#ifndef SPORT_REPOSITORY_H
#define SPORT_REPOSITORY_H

#include <pqxx/pqxx>
#include <vector>
#include <string>
#include <sstream>
#include <optional>
#include "../entities/SportEntity.h"
#include "../infra/db/configure.h"
#include "CrudRepositoryImpl.h"

using namespace std;

class SportRepository : public CrudRepositoryImpl<SportEntity> {
    public:
        virtual ~SportRepository() = default;

        SportEntity createEntityFromResult(const pqxx::row& row);

        std::vector<SportEntity> processFindAll(pqxx::result res);
};



#endif
