#ifndef CONFIGURE_DB_H
#define CONFIGURE_DB_H

#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <filesystem>

#define FILE_PATH "src/properties/db"

using namespace std;

namespace fs = filesystem; 

string readSqlFile(const fs::path& file_path);

pqxx::result executeSql(pqxx::connection* conn, const string& sql);

void loadTables(pqxx::connection* conn);

pqxx::connection* connectDataBase();

void disconnectDataBase(pqxx::connection* conn);

#endif 