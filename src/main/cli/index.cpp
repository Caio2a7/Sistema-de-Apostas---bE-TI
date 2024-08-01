#include "index.h"
#include <regex>
#define LINE_WIDTH 60

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

bool isEmailCheck(const string& email){
    const regex pattern(R"(^\S+@\S+\.\S+$)");
    if(!regex_match(email, pattern)){
        altLinesFormat("Email Inválido");
        return false;
    }

    return true;
}
bool isPasswordCheck(const string& password){
    if(password.length() < 6){
        altLinesFormat("Senha fraca, deve possuir de 6 ou mais caracteres");
        return false;
    }
    return true;
}
bool isPositiveCheck(double balance){
    if(balance < 0){
        altLinesFormat("Saldo Inválido");
        return false;
    }
    return true;
}
optional<UserEntity> createAccount() {
    string name;
    string email;
    string password;
    double balance;
    linesFormat("CADASTRAR NOVO USUÁRIO");

    cout << "Nome: ";
    getline(cin, name);
    
    cout << "Email: ";
    getline(cin, email);
    if(!isEmailCheck(email)){
        return nullopt;
    }

    cout << "Senha: ";
    getline(cin, password);
    if(!isPasswordCheck(password)){
        return nullopt;
    }

    cout << "Saldo inicial: ";
    cin >> balance;
    if(!isPositiveCheck(balance)){
        return nullopt;
    }
    return UserEntity(0, name, email, password, UserRoleEnum::USUARIO, balance);
};

size_t menu(){
    size_t option;

    linesFormat("MENU");
    cout << "1) Ver jogos" << endl;
    cout << "2) Apostar" << endl;
    cout << "3) Status das apostas" << endl;
    cout << "4) Conta" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha a sua opção: ";
    cin >> option;
    getchar();

    return option;
}

size_t adminMenu(){
    size_t option;

    linesFormat("MENU");
    cout << "1) Ver jogos" << endl;
    cout << "2) Setar jogos" << endl;
    cout << "3) Apostar" << endl;
    cout << "4) Status das apostas" << endl;
    cout << "5) Conta" << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha a sua opção: ";
    cin >> option;
    getchar();

    return option;
}

size_t account() {
    size_t option;
    linesFormat("CONTA");

    cout << "1) Depositar" << endl;
    cout << "2) Sacar" << endl;
    cout << "3) Saldo" << endl;
    cout << "Escolha a sua opção: ";
    cin >> option;
    getchar();

    return option;
}

double depositAmount() {
    double amount;
    linesFormat("DEPOSITAR");

    cout << "Digite o saldo a ser depositado: ";
    cin >> amount;

    return amount;
}

double withdrawAmount() {
    double amount;
    linesFormat("SACAR");

    cout << "Digite o valor a ser sacado: ";
    cin >> amount;

    return amount;
}


optional<SportEntity> createSport() {
    string name;
    string type;
    linesFormat("CADASTRAR ESPORTE");

    cout << "Digite o nome do esporte: ";
    getline(cin, name);
    if(name.length() < 3) {
        altLinesFormat("NOME INVÁLIDO");
        return nullopt;
    }

    cout << "Digite o tipo do esporte: ";
    getline(cin, type);
    if(type.length() < 3) {
        altLinesFormat("TIPO INVÁLIDO");
        return nullopt;
    }

    return SportEntity(0, name, type);
}

optional<ParticipantsEntity> createParticipant() {
    string name;
    int wins;
    linesFormat("CADASTRAR PARTICIPANTE");

    cout << "Nome do participante: ";
    getline(cin, name);
    if(name.length() < 3) {
        altLinesFormat("NOME INVÁLIDO");
        return nullopt;
    }

    cout << "Quantidade de vitórias do participante";
    cin >> wins;
    getchar();

    if(wins < 0) {
        altLinesFormat("Quantidade inválida!");
        return nullopt;
    }

    return ParticipantsEntity(0, name, wins);
}