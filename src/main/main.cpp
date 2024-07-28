#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <optional>
#include "service/EventService.h"
#include "service/SportService.h"
#include "service/ParticipantsService.h"
#include "entities/EventEntity.h"
#include "entities/SportEntity.h"
#include "entities/ParticipantsEntity.h"
#include "enum/UserRoleEnum.h"
#include "enum/EventStatusEnum.h"

int main() {
    try {
        // Criar uma conexão com o banco de dados
        pqxx::connection conn("dbname=beti user=postgres password=root hostaddr=127.0.0.1 port=5432");
        EventService userService;
        SportService sportService;
        ParticipantsService participantsService;
        // EventEntity user(0, "usuario5", "usuario5@email.com", "123", UserRoleEnum::USUARIO, 100);
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

        // std::optional<EventEntity> userAuth = userService.authUser(&conn, "user1@email.com", "123456");
        // userService.save(&conn, &entity);
        optional<vector<EventEntity>> userFindAll =  userService.findAll(&conn);
        std::optional<EventEntity> userId = userService.findById(&conn, 1);
        // std::optional<EventEntity> userEmail = userService.findByEmail(&conn, "user2@email.com");

        // cout << "UserAuth" << endl;
        // userAuth.value().toString();
        // cout << endl;
        cout << "UserId" << endl;
        userId.value().toString();
        cout << endl;
        // cout << "UserEmail" << endl;
        // userEmail.value().toString();
        // cout << endl;
        cout << "Users" << endl;
        for (const auto& user : userFindAll.value()) {
            user.toString();
            cout << endl;
        }
        cout << endl;


    } catch (const std::exception& e) {
        std::cerr << "Erro ao conectar com o banco de dados: " << e.what() << std::endl;
    }

    return 0;
}
