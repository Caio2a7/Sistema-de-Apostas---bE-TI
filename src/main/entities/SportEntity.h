#ifndef SPORT_ENTITY_H
#define SPORT_ENTITY_H

#include <string>

using namespace std;

class SportEntity {
    private:
        int id;
        string name;
        string type;

    public:
        SportEntity();

        SportEntity(int id, const string& name, const string& type);

        int getId() const;
        void setId(int id);

        string getName() const;
        void setName(const string& name);

        string getType() const;
        void setType(const string& type);

        void toString() const;
};

#endif 
