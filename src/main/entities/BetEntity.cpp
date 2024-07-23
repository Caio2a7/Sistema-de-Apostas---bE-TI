#include "BetEntity.h"

BetEntity::BetEntity() 
    : id(0), amount(0.0) {}

BetEntity::BetEntity(int id, const UserEntity& user, const EventEntity& event, double amount, const string& bet)
    : id(id), user(user), event(event), amount(amount), bet(bet) {}

int BetEntity::getId() const { return id; }
void BetEntity::setId(int id) { this->id = id; }

UserEntity BetEntity::getUser() const { return user; }
void BetEntity::setUser(const UserEntity& user) { this->user = user; }

EventEntity BetEntity::getEvent() const { return event; }
void BetEntity::setEvent(const EventEntity& event) { this->event = event; }

double BetEntity::getAmount() const { return amount; }
void BetEntity::setAmount(double amount) { this->amount = amount; }

string BetEntity::getBet() const { return bet; }
void BetEntity::setBet(const string& bet) { this->bet = bet; }
