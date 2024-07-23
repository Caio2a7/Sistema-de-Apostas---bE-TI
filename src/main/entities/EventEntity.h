#ifndef EVENT_ENTITY_H
#define EVENT_ENTITY_H

#include <string>
#include <array>
#include "ParticipantsEntity.h"
#include "SportEntity.h"

using namespace std;

class EventEntity {
    private:
        int id;
        SportEntity sport;
        ParticipantsEntity teamA;
        ParticipantsEntity teamB;
        array<double, 3> odds; 
        time_t time;

    public:
        EventEntity();

        EventEntity(int id, SportEntity sport, ParticipantsEntity teamA, ParticipantsEntity teamB, const array<double, 3>& odds, time_t timestamp);

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

        time_t getTime() const;
        void setTime(time_t time);
};

#endif 
