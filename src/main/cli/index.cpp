#include "index.h"
#include <regex>

#define TABLE_WIDTH 78
#define TABLE_WIDTH_BIG 159
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
void teamTableFormat(pair<string, string> teams, pair<int, int> teamsVic) {
    int leftPadding = 11;
    int rightPadding = 10;
 
    cout << string(TABLE_WIDTH-19, '-'); 
    cout << string(11, ' ') << string(TABLE_WIDTH-19, '-') << endl;
    
    cout << '|' << string(leftPadding, ' ') << "Time A" << string(rightPadding, ' ');
    cout << '|' << string(leftPadding, ' ') << "Vitórias" << string(rightPadding, ' ') << '|';
    
    cout << string(11, ' ') << '|' << string(leftPadding, ' ') << "Time B" << string(rightPadding, ' ');
    cout << '|' << string(leftPadding, ' ') << "Vitórias" << string(rightPadding, ' ') << '|' << endl;
    
    cout << string(TABLE_WIDTH-19, '-'); 
    cout << string(11, ' ') << string(TABLE_WIDTH-19, '-') << endl;
    
    if(teams.first.length() > 11){
        leftPadding = 11 - (teams.first.length()-9);

        rightPadding = 10 - (teams.first.length()-9);
    }else if(teams.first.length() > 6){
        leftPadding = 11;
        rightPadding = 10 - (teams.first.length()-6);
    }else{
        leftPadding = 11 + (6-teams.first.length());
    }

    cout << '|' << string(leftPadding, ' ') << teams.first << string(rightPadding, ' ');
    leftPadding = 11;
    rightPadding = 10-(to_string(teamsVic.first).length())-1;
    cout << '|' << string(leftPadding, ' ') << teamsVic.first << " vitórias" << string(rightPadding, ' ') << '|';

    cout << string(11, ' ');
    if(teams.second.length() > 11){
        leftPadding = 11 - (teams.second.length()-9);

        rightPadding = 10 - (teams.second.length()-9);
    }else if(teams.second.length() > 6){
        leftPadding = 11;
        rightPadding = 10 - (teams.second.length()-6);
    }else{
        leftPadding = 11;
        rightPadding = 10 - (teams.second.length()-6);
    }

    cout << '|' << string(leftPadding, ' ') << teams.second << string(rightPadding, ' ');
    leftPadding = 11;
    rightPadding = 10-(to_string(teamsVic.second).length())-1;
    cout << '|' << string(leftPadding, ' ') << teamsVic.second << " vitórias" << string(rightPadding, ' ') << '|' << endl;
    cout << string(TABLE_WIDTH-19, '-'); 
    cout << string(11, ' ') << string(TABLE_WIDTH-19, '-') << endl;
}
void tableFormat(const string& text, int type){
    int totalPadding;
    if(type == 0 || type == 3){
        totalPadding = 3+text.length();
    }
    else if(type == 4){
        totalPadding = 5+text.length();
    }else if(type == 6){
        totalPadding = text.length()-13;
    }
    else { 
        totalPadding = 10+text.length();
    }
    
    int leftPadding = totalPadding/2;
    int rightPadding = totalPadding - leftPadding;
    if(type == 0) { 
        cout << string(TABLE_WIDTH_BIG, '-') << endl; 
    }
    cout << '|' << string(leftPadding, ' ') << text << string(rightPadding, ' ');
    if(type == 2) { 
        cout << '|' <<'\n' << string(TABLE_WIDTH_BIG, '-') << endl;
    }
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
bool isDateTimeCheck(const string &dateTime) {
    // formato ano-mes-dia hora:minutos:segundos.centésimos
    regex datetime_regex(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}\.\d{2})");
    return regex_match(dateTime, datetime_regex);
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

    linesFormat("ADMIN MENU");
    cout << "1) Ver jogos" << endl;
    cout << "2) Apostar" << endl;
    cout << "3) Status das apostas" << endl;
    cout << "4) Conta" << endl;
    cout << "5) Criar esporte" << endl;
    cout << "6) Criar participantes" << endl;
    cout << "7) Criar evento" << endl;
    cout << "8) Atualizar evento" << endl;

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

    cout << "Quantidade de vitórias do " << name << ": ";
    cin >> wins;
    getchar();

    if(wins < 0) {
        altLinesFormat("Quantidade inválida!");
        return nullopt;
    }

    return ParticipantsEntity(0, name, wins);
}

optional<EventEntity> createNewEvent(pqxx::connection *conn) {
    SportService sportsService;
    EventService eventService;
    ParticipantsService participantsService;

    optional<SportEntity> sport;
    optional<ParticipantsEntity> teamA;
    optional<ParticipantsEntity> teamB;

    int sportId;
    int aTeamId;
    int bTeamId;
    
    string dateTime;
    string statusStr;
    EventStatusEnum status;

    linesFormat("CADASTRAR EVENTO");

    cout << "ID do esporte: ";
    cin >> sportId;
    sport = sportsService.findById(conn, sportId);
    if(!sport) { //Não prossegue caso o esporte não exista
        altLinesFormat("Esporte não existente!");
        return nullopt;
    }

    if(sport.has_value()) {
        linesFormat(sport.value().getName());
    }

    cout << "ID do Time A: ";
    cin >> aTeamId;
    teamA = participantsService.findById(conn, aTeamId);
    if(!teamA) { //Não prossegue caso o time não exista
        altLinesFormat("Time não existente!");
        return nullopt;
    }

    cout << "ID do Time B: ";
    cin >> bTeamId;
    cin.ignore();
    teamB = participantsService.findById(conn, bTeamId);
    if(!teamB) { //Não prossegue caso o time não exista
        altLinesFormat("Time não existente!");
        return nullopt;
    }

    cout << "Dia e horário(ano-mes-dia hora:minutos:segundos.centésimos): ";
    getline(cin, dateTime);
    if(!isDateTimeCheck(dateTime)) { // Não prossegue se a data não for no formato especificado
        altLinesFormat("Formato inválido!");
        return nullopt;
    }

    cout << "Status do evento(AGENDADA || ANDAMENTO || FINALIZADA): ";
    getline(cin, statusStr);

    status = convertStringToEventStatusEnum(statusStr);

    return EventEntity(0, sport.value(), teamA.value(), teamB.value(), {0, 0, 0}, dateTime, status);
}

bool changeEventStatus(pqxx::connection *conn) {
    EventService eventServices;
    optional<vector<EventEntity>> events;
    optional<EventEntity> event;

    QueryMetaData *queryMetaData = new QueryMetaData;
    QueryBuilder queryBuilder;

    int eventId;
    string status;

    linesFormat("EVENTOS");

    events = eventServices.findAll(conn);
    if(events) {
        for (const auto& event : events.value()) {
            cout << "\n" << endl;
            tableFormat("ID", 0);
            tableFormat("Horário", 1);
            tableFormat("Status", 4);
            tableFormat("Esporte", 1);
            tableFormat("Odd vitória time A", 6);
            tableFormat("Odd vitória time B", 6);
            tableFormat("Odd empate", 2);
            event.toString();
        }
    }

    cout << "ID do evento que você deseja alterar o status: ";
    cin >> eventId;
    cin.ignore();

    event = eventServices.findById(conn, eventId);

    if(!event) {
        altLinesFormat("Evento não existente!");
        return false; // Se o evento não existir, não prossegue
    }

    cout << "Novo status(AGENDADA || ANDAMENTO || FINALIZADA): ";
    getline(cin, status);

    queryMetaData->tableName = "eventos";
    queryMetaData->columns = {"status"};

    try {
        pqxx::work w(*conn);

        queryMetaData->values = {w.quote(status)};
        string sql = queryBuilder.buildUpdateQuery(queryMetaData, eventId);
        
        // Execute SQL dentro da transação
        pqxx::result res = w.exec(sql);
        
        // Commit da transação
        w.commit();
        
        if(res.affected_rows() > 0) {
            return true;
        }   
    } catch(const std::exception &e) {
        cerr << "Erro ao atualizar o status do evento: " << e.what() << std::endl;
        return false;
    }
}
   