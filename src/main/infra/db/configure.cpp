#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include "configure.h"

#define FILE_PATH "src/properties/db"

using namespace std;

namespace fs = filesystem; 

string readSqlFile(const fs::path& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Não foi possível abrir o arquivo: " + file_path.string());
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

pqxx::result executeSql(pqxx::connection* conn, const string& sql) {
    pqxx::work txn(*conn); // Cria uma transação
    pqxx::result res = txn.exec(sql); // Executa o comando SQL
    txn.commit(); // Confirma a transação

    return res;
}

void loadTables(pqxx::connection* conn) {
    try {
        fs::path scriptsPath = FILE_PATH;
        vector<fs::path> sqlFiles;

        // Verifica se o diretório existe
        if (!fs::is_directory(scriptsPath)) {
            cerr << "O diretório não existe: " << scriptsPath << endl;
            exit(1);
        }

        // Itera sobre os arquivos no diretório
        for (const auto& entry : fs::directory_iterator(scriptsPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".sql") {
                sqlFiles.push_back(entry.path());
            }
        }

        // Ordena arquivos pelo nome
        sort(sqlFiles.begin(), sqlFiles.end());

        // Executa cada arquivo SQL
        for (const auto& file_path : sqlFiles) {
            string sql = readSqlFile(file_path);
            executeSql(conn, sql);
            cout << "Script " << file_path.filename() << " executado com sucesso!" << endl;
        }

    } catch (const exception& e) {
        cerr << "Erro ao processar arquivos ou executar comandos: " << e.what() << endl;
    }
}

pqxx::connection* connectDataBase() {
    try {
        // Cria uma nova conexão com o banco de dados
        string dbInfo = "dbname=beti user=postgres password=root hostaddr=127.0.0.1 port=5432";
        pqxx::connection* conn = new pqxx::connection(dbInfo);

        // Verifica se a conexão foi bem-sucedida
        if (!conn->is_open()) {
            cerr << "Não foi possível se conectar ao banco de dados." << endl;
            delete conn; // Limpa o ponteiro em caso de falha
            exit(EXIT_FAILURE); // Encerra o programa com um código de erro
        }

        return conn;
    } catch (const pqxx::failure& e) {
        cerr << "Não foi possível se conectar ao banco de dados: " << e.what() << endl;
        exit(EXIT_FAILURE); // Encerra o programa com um código de erro
    }
}

void disconnectDataBase(pqxx::connection* conn) {
    delete conn; // Encerra a conexão liberando o ponteiro
}