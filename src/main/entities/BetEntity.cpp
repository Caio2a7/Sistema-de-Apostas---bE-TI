#include "BetEntity.h"
#include <iomanip>
#include "../cli/index.h"

BetEntity::BetEntity() 
    : id(0), amount(0.0) {}

BetEntity::BetEntity(int id, UserEntity user, EventEntity event, double amount, TypeOfBets bet)
    : id(id), user(user), event(event), amount(amount), bet(bet) {}
BetEntity::BetEntity(UserEntity user, EventEntity event, double amount, TypeOfBets bet)
    : id(0), user(user), event(event), amount(amount), bet(bet) {}


int BetEntity::getId() const { return id; }
void BetEntity::setId(int id) { this->id = id; }

UserEntity BetEntity::getUser() const { return user; }
void BetEntity::setUser(const UserEntity& user) { this->user = user; }

EventEntity BetEntity::getEvent() const { return event; }
void BetEntity::setEvent(const EventEntity& event) { this->event = event; }

double BetEntity::getAmount() const { return amount; }
void BetEntity::setAmount(double amount) { this->amount = amount; }

TypeOfBets BetEntity::getBet() const { return bet; }
void BetEntity::setBet(const TypeOfBets& bet) { this->bet = bet; }

TablesDataBaseEnum BetEntity::getTable() const { return TablesDataBaseEnum::apostas; }

std::vector<std::string> BetEntity::getColumns() {
    return {"id", "id_usuario", "id_evento", "valor", "aposta"};
}

void BetEntity::toString() const {
    cout << string(159, '=') << endl;
    cout << "ID da aposta: " << id  <<endl;
    cout << "|Usuário| "  << endl;
    user.toString();
    cout << "|Evento| " << endl;
    tableFormat("ID", 0);
    tableFormat("Horário", 1);
    tableFormat("Status", 4);
    tableFormat("Esporte", 1);
    tableFormat("Odd vitória time A", 6);
    tableFormat("Odd vitória time B", 6);
    tableFormat("Odd empate", 2);
    event.toString();
    cout << "Valor da Aposta: " << fixed << setprecision(3) << amount << endl;
    cout << "Tipo da aposta: " << bet << endl;
}