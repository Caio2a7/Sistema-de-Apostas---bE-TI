#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <pqxx/pqxx>
#include "../repository/UserRepository.h"
#include "../entities/UserEntity.h"

using namespace std;

class UserService {
    public:
        optional<UserEntity> authUser(pqxx::connection* conn, string email, string password);
        
        bool save(pqxx::connection *conn, UserEntity *user);

        void update(pqxx::connection *conn, UserEntity *user);
        
        optional<UserEntity> findById(pqxx::connection *conn, size_t id);
        
        optional<UserEntity> findByEmail(pqxx::connection *conn, const string& email);
        
        optional<vector<UserEntity>> findAll(pqxx::connection *conn);

    private:
        void setTableName(QueryMetaData *queryMetaData);
};

#endif