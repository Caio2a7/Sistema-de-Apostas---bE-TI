#include <iostream>
#include <pqxx/pqxx>
#include "cli/index.h"
#include "entities/UserEntity.h"
#include "infra/db/configure.h"
#include "repository/UserRepository.h"

int main() {
    pqxx::connection *conn = connectDataBase();
    loadTables(conn);
    // size_t choice = welcome();

    UserEntity *userEntity = new UserEntity(0, "user1", "user2@email.com", "asdfasd", 312312);
    UserRepository *userRepository = new UserRepository();

    // userRepository->saveUser(conn, userEntity);
    userRepository->countAllUsers(conn);
    userRepository->findByEmail(conn, "teste@email.com").toString();

    
    // if (choice == 2) {
    //     UserEntity user = createAccount();
    // }

    return 0;
}