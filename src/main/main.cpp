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
        UserEntity *user = new UserEntity;
        UserService userServices;
        int option = welcome();
        if(option == 2){
            *user = createAccount();
            cout << "============================================" << endl;
            cout << "           Mensagem Informática" << endl;
            userServices.save(conn, user);
            cout << "============================================" << endl;
        }
        /*UserService userService;
        EventService eventService;
        SportService sportService;
        BetService betService;
        ParticipantsService participantsService;


        UserEntity userEntity = userService.findById(&conn, 17).value();
        EventEntity eventEntity = eventService.findById(&conn, 2).value();

        BetEntity betEntity1(0, userEntity, eventEntity, 100.0, TypeOfBets::VITORIA_TIME_A);

        userEntity = userService.findById(&conn, 18).value();
        eventEntity = eventService.findById(&conn, 1).value();

        BetEntity betEntity2(0, userEntity, eventEntity, 100.0, TypeOfBets::EMPATE);

        // betService.save(&conn, &betEntity1);
        // betService.save(&conn, &betEntity2);

        cout << "FIND BY ID" << endl;
        betService.findById(&conn, 3).value().toString();

        cout << "FIND ALL" << endl;
        optional<vector<BetEntity>> betFindAll = betService.findAll(&conn);
        for (const auto& bet : betFindAll.value()) {
            bet.toString();
            cout << endl;
        }

        // EventEntity user(0, "user5", "user5@email.com", "123", UserRoleEnum::user, 100);
        // SportEntity sport = sportService.findById(&conn, 2).value();
        // ParticipantsEntity p1 = participantsService.findById(&conn, 1).value();
        // ParticipantsEntity p2 = participantsService.findById(&conn, 2).value();
        // std::array<double, 3> arr = {123.45, 678.90, 234.56};
        // EventStatusEnum status = EventStatusEnum::AGENDADA;

        // Para o horário conseguir ser salvo no banco de dados ele tem que seguir o padrão abaixo
        // ano-mes-dia hora:minutos:segundos.centesimos
        // 2024-07-26 23:20:02.818
        // std::string horario = "2024-07-26 23:20:02.818";

        // EventEntity entity(0, sport, p1, p2, arr, horario, status);

        // std::optional<EventEntity> userAuth = eventService.authUser(&conn, "user1@email.com", "123456");
        // eventService.save(&conn, &entity);
        // optional<vector<EventEntity>> userFindAll =  eventService.findAll(&conn);
        // std::optional<EventEntity> userId = eventService.findById(&conn, 1);
        // std::optional<EventEntity> userEmail = eventService.findByEmail(&conn, "user2@email.com");

        // cout << "UserAuth" << endl;
        // userAuth.value().toString();
        // cout << endl;
        // cout << "UserId" << endl;
        // userId.value().toString();
        // cout << endl;
        // cout << "UserEmail" << endl;
        // userEmail.value().toString();
        // cout << endl;
        // cout << "Users" << endl;
        // for (const auto& user : userFindAll.value()) {
        //     user.toString();
        //     cout << endl;
        // }
        // cout << endl;


    */
    } catch (const std::exception& e) {
        std::cerr << "Erro ao conectar com o banco de dados: " << e.what() << std::endl;
    }
    return 0;
}
