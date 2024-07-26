#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include "../enum/UserRoleEnum.h"
#include "../enum/TablesDataBaseEnum.h"

using namespace std;

class UserEntity {
    private:
        int id;
        string name;
        string email;
        string password;
        UserRoleEnum role;
        double balance;

    public:
        UserEntity();

        UserEntity(int id, const string& name, const string& email, const string& password, const UserRoleEnum role, double balance);

        int getId() const;
        void setId(int id);

        string getName() const;
        void setName(const string& name);

        string getEmail() const;
        void setEmail(const string& email);

        string getPassword() const;
        void setPassword(const string& password);

        UserRoleEnum getRole() const;
        void setRole(const UserRoleEnum role);

        double getBalance() const;
        void setBalance(double balance);

        TablesDataBaseEnum getTable() const;

        std::vector<std::string> getColumns();

        void toString() const;
};

#endif 
