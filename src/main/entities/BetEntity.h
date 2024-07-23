#ifndef BET_ENTITY_H
#define BET_ENTITY_H

#include <string>
#include "EventEntity.h"
#include "UserEntity.h"

using namespace std;

class BetEntity {
    private:
        int id;
        UserEntity user;
        EventEntity event;
        double amount;
        string bet;

    public:
        BetEntity();

        BetEntity(int id, const UserEntity& user, const EventEntity& event, double amount, const string& bet);

        int getId() const;
        void setId(int id);

        UserEntity getUser() const;
        void setUser(const UserEntity& user);

        EventEntity getEvent() const;
        void setEvent(const EventEntity& event);

        double getAmount() const;
        void setAmount(double amount);

        string getBet() const;
        void setBet(const string& bet);
};

#endif 
