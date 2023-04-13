#pragma once
#include "Position.h"

class Car{

    private:
        int ID;
        //стандартен за България номер от 8 символа
        char number[9];
        double rentSum;
        Position pos;

    public:

        int getID() const;

        //operator=

};