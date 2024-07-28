#ifndef EVENT_ENTITY_H
#define EVENT_ENTITY_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "ParticipantsEntity.h"
#include "SportEntity.h"
#include "../enum/EventStatusEnum.h"

using namespace std;

class EventEntity {
    private:
        int id;
        SportEntity sport;
        ParticipantsEntity teamA;
        ParticipantsEntity teamB;
        array<double, 3> odds; 
        string time;
        EventStatusEnum status;

    public:
        EventEntity();

        EventEntity(int id, SportEntity sport, ParticipantsEntity teamA, ParticipantsEntity teamB, const array<double, 3>& odds, string timestamp, EventStatusEnum status);

        int getId() const;
        void setId(int id);

        SportEntity getSport() const;
        void setSport(const SportEntity& sport);

        ParticipantsEntity getTeamA() const;
        void setTeamA(const ParticipantsEntity& teamA);

        ParticipantsEntity getTeamB() const;
        void setTeamB(const ParticipantsEntity& teamB);

        const array<double, 3>& getOdds() const; 
        void setOdds(const array<double, 3>& odds);
        void setOdds(size_t pos, double value);

        string getTime() const;
        void setTime(string time);

        EventStatusEnum getStatus() const;
        void setStatus(const EventStatusEnum& status);

        TablesDataBaseEnum getTable() const;

        std::vector<std::string> getColumns(); 

        void toString() const;
};

#endif 
