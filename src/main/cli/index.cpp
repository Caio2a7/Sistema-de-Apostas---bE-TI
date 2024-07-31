#include "index.h"
#define LINE_WIDTH 40

void welcome() {
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
}
void linesFormat(const string& text) {

    int textLength = text.length();

    int totalPadding = LINE_WIDTH - textLength;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;

    cout << string(LINE_WIDTH, '-') << endl;
    cout << string(leftPadding, ' ') << text << string(rightPadding, ' ') << endl;
    cout << string(LINE_WIDTH, '-') << endl;
}
void altLinesFormat(const string& text) {

    int textLength = text.length();

    int totalPadding = LINE_WIDTH - textLength;
    int leftPadding = totalPadding / 2;
    int rightPadding = totalPadding - leftPadding;
    cout << string(LINE_WIDTH, '#') << endl;
    cout << "#" <<string(leftPadding-1, ' ') << text << string(rightPadding, ' ') << "#" <<endl;
    cout << string(LINE_WIDTH, '#') << endl;
}
size_t login(){
    size_t option;

    linesFormat("LOGIN E CADASTRO");
    cout << "1) Efetuar Login" << endl;
    cout << "2) Criar conta" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha a sua opção: ";
    cin >> option;
    getchar();

    return option;
}

pair<string, string> authAccount(){
    string email;
    string password;
    linesFormat("ENTRAR NA CONTA");
    cout << "Email: ";
    getline(cin, email);
    cout << "Senha: ";
    getline(cin, password);

    return make_pair(email, password);
}

UserEntity createAccount() {
    string name;
    string email;
    string password;
    double balance;
    linesFormat("CADASTRAR NOVO USUÁRIO");
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