#ifndef USER_REPOSITORY_H
#define USER_RESPOSITORY_H

#include <pqxx/pqxx>
#include <list>
#include <string>
#include "../entities/UserEntity.h"
#include "../infra/db/configure.h"

using namespace std;

class UserRepository {
    public:
        size_t countAllUsers(pqxx::connection* conn);

        void saveUser(pqxx::connection* conn, UserEntity* user);

        UserEntity findByEmail(pqxx::connection* conn, string email);
};



#endif