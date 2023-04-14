#pragma once
#include "Position.h"
#include "Car.h"

class Client{

    private:
        char* name;
        int IDNumber;
        double money;
        Position position;

        void setName(char*);

        void setID(int);

        void setMoney(double);

        void setPosition(Position);

    public:
        
        Client(char*, int, double, Position);

        Client();

        Client(const Client&);

        char* getName() const;

        int getID() const;

        double getMoney() const;

        Position getPosition() const;

        bool rent(int, Car*, int);

        double findDistance(int, Car*, int);

        Client& operator=(const Client&);

        ~Client();
};