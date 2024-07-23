#ifndef PARTICIPANTS_ENTITY_H
#define PARTICIPANTS_ENTITY_H

#include <iostream>
#include <string>

using namespace std;

class ParticipantsEntity {
    private:
        int id;
        string name;
        int victorys;

    public:
        ParticipantsEntity();

        ParticipantsEntity(int id, const string& name, int victorys);

        int getId() const;
        void setId(int id);

        string getName() const;
        void setName(const string& name);

        int getVictorys() const;
        void setVictorys(int Victorys);

        void toString() const;
};

#endif 
