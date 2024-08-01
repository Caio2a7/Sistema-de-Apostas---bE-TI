#ifndef BET_ENTITY_H
#define BET_ENTITY_H

#include <string>
#include "EventEntity.h"
#include "UserEntity.h"
#include "../enum/TablesDataBaseEnum.h"
#include "../enum/TypeOfBets.h"

using namespace std;

class BetEntity {
    private:
        UserEntity user;
        EventEntity event;
        double amount;
        TypeOfBets bet;

    public:
        BetEntity();

        BetEntity(UserEntity user, EventEntity event, double amount, TypeOfBets bet);

        UserEntity getUser() const;
        void setUser(const UserEntity& user);

        EventEntity getEvent() const;
        void setEvent(const EventEntity& event);

        double getAmount() const;
        void setAmount(double amount);

        TypeOfBets getBet() const;
        void setBet(const TypeOfBets& bet);

        TablesDataBaseEnum getTable() const;

        std::vector<std::string> getColumns(); 

        void toString() const;
};

#endif 
