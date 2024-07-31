#ifndef INDEX_H
#define INDEX_H

#define LINE_WIDTH 40
#include <iostream>
#include <string>
#include "../entities/UserEntity.h"
#include "../enum/UserRoleEnum.h"

using namespace std;

void welcome();
void linesFormat(const std::string& text);
void altLinesFormat(const std::string& text);
size_t login();
pair<string, string> authAccount();
UserEntity createAccount();

#endif