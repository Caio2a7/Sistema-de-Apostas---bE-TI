#include "SportEntity.h"

SportEntity::SportEntity() : id(0) {}

SportEntity::SportEntity(int id, const string& name, const string& type)
    : id(id), name(name), type(type) {}

int SportEntity::getId() const { return id; }
void SportEntity::setId(int id) { this->id = id; }

string SportEntity::getName() const { return name; }
void SportEntity::setName(const string& name) { this->name = name; }

string SportEntity::getType() const { return type; }
void SportEntity::setType(const string& type) { this->type = type; }

void SportEntity::toString() const {
    cout << "ID: " << id << "\n"
         << "Name: " << name << "\n"
         << "Type: " << type << endl;
}

TablesDataBaseEnum SportEntity::getTable() const { return TablesDataBaseEnum::esporte; }

std::vector<std::string> SportEntity::getColumns() {
    return {"id", "nome", "tipo"};
}
