#include "ParticipantsEntity.h"

ParticipantsEntity::ParticipantsEntity() : id(0), victorys(0) {}

ParticipantsEntity::ParticipantsEntity(int id, const string& name, int victorys)
    : id(id), name(name), victorys(victorys) {}

int ParticipantsEntity::getId() const { return id; }
void ParticipantsEntity::setId(int id) { this->id = id; }

string ParticipantsEntity::getName() const { return name; }
void ParticipantsEntity::setName(const string& name) { this->name = name; }

int ParticipantsEntity::getVictorys() const { return victorys; }
void ParticipantsEntity::setVictorys(int victorys) { this->victorys = victorys; }

void ParticipantsEntity::toString() const {
    cout << "ID: " << id << "\n"
         << "Name: " << name << "\n"
         << "victorys: " << victorys << endl;
}
