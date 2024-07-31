#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <optional>
#include "service/EventService.h"
#include "service/SportService.h"
#include "service/ParticipantsService.h"
#include "service/BetService.h"
#include "service/UserService.h"
#include "entities/EventEntity.h"
#include "entities/SportEntity.h"
#include "entities/ParticipantsEntity.h"
#include "entities/BetEntity.h"
#include "entities/UserEntity.h"
#include "enum/UserRoleEnum.h"
#include "enum/EventStatusEnum.h"
#include "enum/TypeOfBets.h"
#include "infra/db/configure.h"
#include "cli/index.h"


int main() {
    try {
        // Criar uma conexão com o banco de dados
        //pqxx::connection conn("dbname=beti user=postgres password=root hostaddr=127.0.0.1 port=5432");
        pqxx::connection *conn = connectDataBase();
        UserEntity *userData = new UserEntity;
        UserService userServices;
        size_t option;
        welcome();
        do{
            option = login();
            if(option == 1){
                pair<string, string> credentials = authAccount();
                optional<UserEntity> user = userServices.authUser(conn, credentials.first, credentials.second);
                
                
            }
            else if(option == 2){
                *userData = createAccount();
                bool isUserSaved = userServices.save(conn, userData);
                isUserSaved ? altLinesFormat("Usuário cadastrado com sucesso!") : altLinesFormat("Fechando o programa!");
            }
        }while(option != 0);
    } catch (const std::exception& e) {
        std::cerr << "Erro ao conectar com o banco de dados: " << e.what() << std::endl;
    }
    return 0;
}
