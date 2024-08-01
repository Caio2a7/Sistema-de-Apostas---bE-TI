#ifndef INDEX_H
#define INDEX_H

#define LINE_WIDTH 60
#include <iostream>
#include <string>
#include <optional>
#include "../entities/UserEntity.h"
#include "../entities/ParticipantsEntity.h"
#include "../entities/SportEntity.h"
#include "../entities/EventEntity.h"
#include "../service/ParticipantsService.h"
#include "../service/SportService.h"
#include "../service/EventService.h"
#include "../enum/UserRoleEnum.h"
#include "../repository/utils/QueryBuilder.h"

using namespace std;

void welcome();
void linesFormat(const std::string& text);
void altLinesFormat(const std::string& text);
void teamTableFormat(pair<string, string>, pair<int, int>);
void tableFormat(const string& text, int type);
size_t login();
bool isEmailCheck();
bool isPasswordCheck();
bool isPositiveCheck();
bool isTimeCheck();
pair<string, string> authAccount();
optional<UserEntity> createAccount();
size_t menu();
size_t adminMenu();
size_t account();
double depositAmount();
double withdrawAmount();
optional<SportEntity> createSport();
optional<ParticipantsEntity> createParticipant();
optional<EventEntity> createNewEvent(pqxx::connection *conn);
bool changeEventStatus(pqxx::connection *conn);
#endif