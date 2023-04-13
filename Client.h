#pragma once
#include "Position.h"

class Client{

    private:
        char* name;
        char* IDNumber;
        double money;
        Position position;

        void setName(char*);

        void setID(char*);

        void setMoney(double);

        void setPosition(Position);

    public:

        char* getName() const;

        char* getIDNumber() const;

        double getMoney() const;

        Position getPosition() const;

        void rent(int, Car*);

        double findDistance(int, Car*);

        Client& operator=(const Client&);
};