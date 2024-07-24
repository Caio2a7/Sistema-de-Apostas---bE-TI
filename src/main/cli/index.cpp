#include "index.h"

size_t welcome() {
    size_t option;

    cout << "     Bem-vindo ao BeTI     " << endl;
    cout << "============================" << endl;
    cout << "1) Efetuar Login" << endl;
    cout << "2) Criar conta" << endl;
    cout << "Escolha a sua opção: ";
    cin >> option;
    getchar();

    return option;
}

UserEntity createAccount() {
    string name;
    string email;
    string password;
    double balance;

    cout << "           Cadastrar Novo Usuário           " << endl;
    cout << "============================================" << endl;
    cout << "Nome: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Senha: ";
    getline(cin, password);
    cout << "Saldo inicial: ";
    cin >> balance;

    return UserEntity(0, name, email, password, UserRole::USUARIO, balance);
}