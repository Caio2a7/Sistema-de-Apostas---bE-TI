#include <pqxx/pqxx>
#include <list>
#include <string>
#include <sstream>
#include "UserRepository.h"
#include "../entities/UserEntity.h"
#include "../infra/db/configure.h"

using namespace std;

size_t UserRepository::countAllUsers(pqxx::connection* conn) {
    string querySql = "SELECT COUNT(*) FROM usuario;";
    pqxx::result res = executeSql(conn, querySql);

    if (res.empty()) {
        cerr << "Erro ao contar usuários." << endl;
        return 0;
    }

    size_t count = res[0][0].as<size_t>(); // Obtém o resultado
    cout << "Total de usuários: " << count << endl;
    return count;
}

void UserRepository::saveUser(pqxx::connection* conn, UserEntity* user) {
    size_t totalUsers = this->countAllUsers(conn);
    user->setId(totalUsers+1);

    ostringstream oss;
    oss << "INSERT INTO usuario (id, nome, email, senha, saldo) VALUES ("
          << user->getId() << ", '"
          << user->getName() << "', '"
          << user->getEmail() << "', '"
          << user->getPassword() << "', "
          << user->getBalance() << ");";
    string query = oss.str();
    cout << "Query: " << query << endl;
    executeSql(conn, query);
}

UserEntity UserRepository::findByEmail(pqxx::connection* conn, string email) {
    UserEntity user;
    try {
        string query = "SELECT * FROM usuario WHERE email = '" + email + "';";

        pqxx::result result = executeSql(conn, query);

        if (result.size() == 1) {
            user.setId(result[0][0].as<int>());
            user.setName(result[0][1].as<std::string>());
            user.setEmail(result[0][2].as<std::string>());
            user.setPassword(result[0][3].as<std::string>());
            user.setBalance(result[0][4].as<double>());
        } else {
            std::cerr << "Nenhum usuário encontrado com o email: " << email << std::endl;
        }
    } catch (const pqxx::sql_error& e) {
        std::cerr << "Erro ao executar a consulta: " << e.what() << std::endl;
        std::cerr << "Consulta: " << e.query() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro geral: " << e.what() << std::endl;
    }

    return user;
}