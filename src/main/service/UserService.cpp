#include "UserService.h"

bool UserService::authUser(pqxx::connection* conn, string email, string password) {
    UserRepository *userRepository = new UserRepository();
    optional<UserEntity> userOptional = userRepository->findByEmail(conn, email);
    
    if (!userOptional.has_value()) {
        cerr << "Usuário não encontrado" << endl;
        return false;
    }

    UserEntity user = userOptional.value();

    if (!(password == user.getPassword())) {
        cerr << "Senha não confere" << endl;
        delete userRepository;
        return false;
    }

    cout << "Usuário autenticado com sucesso" << endl;
    delete userRepository;
    return true;
}
