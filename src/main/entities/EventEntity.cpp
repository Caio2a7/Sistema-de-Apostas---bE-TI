#include "EventEntity.h"

EventEntity::EventEntity() 
    : id(0), odds({0.0, 0.0, 0.0}), time(0) {}

EventEntity::EventEntity(int id, SportEntity sport, ParticipantsEntity teamA, ParticipantsEntity teamB, const array<double, 3>& odds, time_t timestamp, EventStatusEnum status)
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

time_t EventEntity::getTime() const { return time; }
void EventEntity::setTime(time_t time) { this->time = time; }

EventStatusEnum EventEntity::getStatus() const { return status; };
void EventEntity::setStatus(const EventStatusEnum& status) { this->status = status; };

TablesDataBaseEnum EventEntity::getTable() const { return TablesDataBaseEnum::eventos; }

std::vector<std::string> EventEntity::getColumns() {
    return {"id", "id_esporte", "id_time_a", "id_time_b", "odds", "horario", "status"};
}

void EventEntity::toString() const {
    cout << "ID: " << id << "\n";
    cout << "Horário: " << to_string(time) << endl;
    cout << "Status: " << to_string(status) << endl;
    cout << "Esporte:" << endl;
    sport.toString();
    cout << "Time A:" << endl;
    teamA.toString();
    cout << "Time B:" << endl;
    teamB.toString();
    cout << "Odds:" << endl;
    for (const auto& a : odds) {
        cout << a << endl;
    }
}