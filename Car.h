#pragma once
#include "Position.h"

class Car{

    private:
        int ID;
        //стандартен за България номер от 8 символа
        char* number = new char[9];
        double rentSum;
        Position position;
        bool rented;

        void setID(int);

        void setNumber(char*);

        void setRentSum(double);

        void setPosition(Position p);

        void setRented(bool);

    public:

        int getID() const;

        char* getNumber() const;

        int getRentSum() const;

        Position getPosition() const;

        bool isRented() const;

        //operator=
        Car& operator=(const Car&);

};