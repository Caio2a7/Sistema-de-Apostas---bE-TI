#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include <iostream>
#include <string>
#include <pqxx/pqxx>
#include "../repository/UserRepository.h"

using namespace std;

class UserService {
    public:
        bool authUser(pqxx::connection* conn, string email, string password);
};

#endif