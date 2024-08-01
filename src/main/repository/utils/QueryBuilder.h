#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
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

        return query.str();
    }

    string buildFindByIdQuery(QueryMetaData *metaData, size_t id) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName 
              << " WHERE id = " << id << ";";

        return query.str();
    }

    string buildFindAllQuery(QueryMetaData *metaData) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName << ";";

        return query.str();
    }

    string buildFindByEmailQuery(QueryMetaData *metaData, const string& email) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName 
              << " WHERE email = " << pqxx::to_string(email) << ";";

        return query.str();
    }

    string buildUpdateQuery(QueryMetaData *metaData, size_t id) {
        ostringstream query;
        query << "UPDATE " << metaData->tableName << " SET ";

        // Adiciona as colunas e valores
        for (size_t i = 0; i < metaData->columns.size(); ++i) {
            query << metaData->columns[i] << " = " << pqxx::to_string(metaData->values[i]);
            if (i < metaData->columns.size() - 1) {
                query << ", ";
            }
        }

        query << " WHERE id = " << id << ";";

        return query.str();
    }

    string buildValueArray(const std::vector<double>& arr) {
        std::ostringstream oss;
        oss << "{";

        for (size_t i = 0; i < arr.size(); ++i) {
            oss << std::fixed << std::setprecision(2) << arr[i];
            if (i != arr.size() - 1) {
                oss << ", ";
            }
        }

        oss << "}";
        return oss.str();
    }

    string buildFindAllByEventIdQuery(QueryMetaData *metaData, size_t eventId) {
        ostringstream query;
        query << "SELECT * FROM " << metaData->tableName  
              << " WHERE id_evento = " << eventId << ";";

        return query.str();
    }
};

#endif