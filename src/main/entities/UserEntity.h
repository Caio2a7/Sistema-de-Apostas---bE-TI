#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <iostream>
#include <string>

using namespace std;

class UserEntity {
    private:
        int id;
        string name;
        string email;
        string password;
        string role;
        double balance;

    public:
        UserEntity();

        UserEntity(int id, const string& name, const string& email, const string& password, double balance);

        int getId() const;
        void setId(int id);

        string getName() const;
        void setName(const string& name);

        string getEmail() const;
        void setEmail(const string& email);

        string getPassword() const;
        void setPassword(const string& password);

        string getRole() const;
        void setRole(const string& role);

        double getBalance() const;
        void setBalance(double balance);

        void toString() const;
};

#endif 
