#include "index.h"

size_t welcome() {
    size_t option;
    cout << "========================================================================================================================" << endl;
    cout << "\t\t\t\t\t$$\\                  $$\\  $$$$$$$$\\ $$$$$$\\  \n"
                 "\t\t\t\t\t$$ |                 $$ | \\__$$  __|\\_$$  _| \n"
                 "\t\t\t\t\t$$$$$$\\   $$$$$$\\ $$$$$$\\    $$ |     $$ |   \n"
                 "\t\t\t\t\t$$  __$$\\ $$  __$$\\\\_$$  _|  $$ |     $$ |   \n"
                 "\t\t\t\t\t$$ |  $$ |$$$$$$$$ | $$ |    $$ |     $$ |   \n"
                 "\t\t\t\t\t$$ |  $$ |$$   ____| $$ |$$\\ $$ |     $$ |   \n"
                 "\t\t\t\t\t$$$$$$$  |\\$$$$$$$\\  \\$$$$  |$$ |   $$$$$$\\ \n"
                 "\t\t\t\t\t\\_______/  \\_______|  \\____/ \\__|   \\______| \n";
    cout << "========================================================================================================================" << endl;
    cout << u8"Bem vindo🌟! A sua plataforma de apostas esportivas⚽ tecnológica🖥️💻 e feita com carinho para o público informático👨‍💻" << endl;
    cout << "========================================================================================================================" << endl;
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

    cout << "============================================" << endl;
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

    return UserEntity(0, name, email, password, UserRoleEnum::USUARIO, balance);
}