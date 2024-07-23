#include <iostream>
#include <pqxx/pqxx>
#include "infra/db/configure.h"

int main() {
    pqxx::connection *conn = connectDataBase();
    loadTables(conn);

    return 0;
}