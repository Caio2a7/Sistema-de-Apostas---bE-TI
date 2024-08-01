#include "BetEntity.h"

BetEntity::BetEntity() 
    : amount(0.0) {}

BetEntity::BetEntity(UserEntity user, EventEntity event, double amount, TypeOfBets bet)
    : user(user), event(event), amount(amount), bet(bet) {}


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
    cout << "Usuário: " << endl;
    user.toString();
    cout << "Evento: " << endl;
    event.toString();
    cout << "Valor da Aposta:" << amount << endl;
    cout << "Tipo da aposta:" << bet << endl;
}