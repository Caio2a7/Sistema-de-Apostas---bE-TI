#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <pqxx/pqxx>

using namespace std;

struct QueryMetaData {
    string tableName;
    vector<string> columns;
    vector<string> values;
};

class QueryBuilder {
    public:
    string buildInsertQuery(QueryMetaData *metaData) {
        ostringstream query;
        query << "INSERT INTO " << metaData->tableName << " (";

        // Adiciona os nomes das colunas
        for (size_t i = 0; i < metaData->columns.size(); ++i) {
            query << metaData->columns[i];
            if (i < metaData->columns.size() - 1) {
                query << ", ";
            }
        }

        query << ") VALUES (";

        // Adiciona os valores
        for (size_t i = 0; i < metaData->values.size(); ++i) {
            query << pqxx::to_string(metaData->values[i]);
            if (i < metaData->values.size() - 1) {
                query << ", ";
            }
        }

        query << ");";

        cout << "Query: " << query.str() << endl;

        return query.str();
    }

    string buildFindByIdQuery(QueryMetaData *metaData, size_t id) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName 
              << " WHERE id = " << id << ";";

        cout << "Query: " << query.str() << endl;

        return query.str();
    }

    string buildFindAllQuery(QueryMetaData *metaData) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName << ";";

        cout << "Query: " << query.str() << endl;

        return query.str();
    }

    string buildFindByEmailQuery(const QueryMetaData& metaData, const string& email) {
        ostringstream query;
        query << "SELECT * FROM " << metaData.tableName 
              << " WHERE email = " << pqxx::to_string(email) << ";";

        cout << "Query: " << query.str() << endl;

        return query.str();
    }

    string buildUpdateQuery(const QueryMetaData& metaData, size_t id) {
        ostringstream query;
        query << "UPDATE " << metaData.tableName << " SET ";

        // Adiciona as colunas e valores
        for (size_t i = 0; i < metaData.columns.size(); ++i) {
            query << metaData.columns[i] << " = " << pqxx::to_string(metaData.values[i]);
            if (i < metaData.columns.size() - 1) {
                query << ", ";
            }
        }

        query << " WHERE id = " << id << ";";

        cout << "Query: " << query.str() << endl;

        return query.str();
    }
};

#endif