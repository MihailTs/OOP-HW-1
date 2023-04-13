#pragma once
#include "Position.h"
#include "Car.h"

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

        bool rent(int, Car*, int);

        double findDistance(int, Car*, int);

        Client& operator=(const Client&);

        friend class Car;
};