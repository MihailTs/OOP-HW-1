#pragma once
#include "Position.h"

class Car{

    private:
        int ID;
        //стандартен за България регистрационен номер от 8 символа
        char* number = new char[9];
        double rentSum;
        Position position;
        bool rented = false;

        void setID(int);

        void setNumber(char*);

        void setRentSum(double);

        void setPosition(Position p);

        void setRented(bool);

    public:

        Car(int, char*, double, Position);

        Car(int, char*, double, int, int);

        Car();

        Car(const Car&);

        int getID() const;

        char* getNumber() const;

        int getRentSum() const;

        Position getPosition() const;

        bool isRented() const;

        //operator=
        Car& operator=(const Car&);

        ~Car();

        friend class Client;
};