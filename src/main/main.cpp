#include <iostream>
#include <pqxx/pqxx>
#include "infra/db/configure.h"
#include "service/UserService.h"

int main() {
    pqxx::connection *conn = connectDataBase();
    loadTables(conn);

    UserService *user = new UserService();

    user->authUser(conn, "teste@email.com", "12312312");

    return 0;
}