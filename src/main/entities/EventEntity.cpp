#include "EventEntity.h"
#include "../cli/index.h"
#include <string>
#include <iomanip>

EventEntity::EventEntity() 
    : id(0), odds({0.0, 0.0, 0.0}), time(0) {}

EventEntity::EventEntity(int id, SportEntity sport, ParticipantsEntity teamA, ParticipantsEntity teamB, const array<double, 3>& odds, string timestamp, EventStatusEnum status)
    : id(id), sport(sport), teamA(teamA), teamB(teamB), odds(odds), time(timestamp), status(status) {}

int EventEntity::getId() const { return id; }
void EventEntity::setId(int id) {  this->id = id; }

SportEntity EventEntity::getSport() const { return sport; }
void EventEntity::setSport(const SportEntity& sport) { this->sport = sport; }

ParticipantsEntity EventEntity::getTeamA() const { return teamA; }
void EventEntity::setTeamA(const ParticipantsEntity& teamA) { this->teamA = teamA; }

ParticipantsEntity EventEntity::getTeamB() const { return teamB; }
void EventEntity::setTeamB(const ParticipantsEntity& teamB) { this->teamB = teamB; }

const array<double, 3>& EventEntity::getOdds() const { return odds; }

void EventEntity::setOdds(const array<double, 3>& odds) { this->odds = odds; }

void EventEntity::setOdds(size_t pos, double value) {
    if (pos < odds.size()) {
        odds[pos] = value;
    } else {
        cerr << "Índice fora dos limites!" << endl;
    }
}

string EventEntity::getTime() const { return time; }
void EventEntity::setTime(string time) { this->time = time; }

EventStatusEnum EventEntity::getStatus() const { return status; };
void EventEntity::setStatus(const EventStatusEnum& status) { this->status = status; };

TablesDataBaseEnum EventEntity::getTable() const { return TablesDataBaseEnum::eventos; }

std::vector<std::string> EventEntity::getColumns() {
    return {"id", "id_esporte", "id_time_a", "id_time_b", "odds", "horario", "status"};
} 

void EventEntity::toString() const {
    cout << "|" << string(4-to_string(id).length(), ' ') << id << string(3, ' ');
    cout << "|" << string(3, ' ') << time << string(3, ' ');
    cout << "|" << string(3, ' ') << to_string(status) << string(7-(to_string(status).length()-7), ' ');
    int sportLeftPadding = sport.getName().length() < 7 ? 8 : 8;
    int sportRightPadding = sport.getName().length() < 7 ? 8+(8-sport.getName().length()) : (8*2) - sport.getName().length();
    cout << "|" << string(sportLeftPadding, ' ') << sport.getName() << string(sportRightPadding, ' ');
    for (const auto& odd : odds) {
        cout << "|" << setprecision(2) << string(11, ' ') << odd << string(10, ' ');
    }
    
    cout << '\n' <<string(159, '-') << endl;


    teamTableFormat(make_pair(teamA.getName(), teamB.getName()), make_pair(teamA.getVictorys(), teamB.getVictorys()));
    cout << endl;
}