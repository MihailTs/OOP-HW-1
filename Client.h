#pragma once
#include "Position.h"

class Client{

    private:
        char* name;
        char* IDNumber;
        int money;
        Position pos;

    public:

        int getID();

};