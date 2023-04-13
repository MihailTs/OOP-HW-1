#include "Client.h"
#include "Car.h"
#include <cstring>
#include <cmath>

void Client::setName(char* newName){
    delete []name;
    name = new char[strlen(newName)+1];
    strcpy(name, newName);
}

void Client::setID(char* newID){
    delete []IDNumber;
    IDNumber = new char[strlen(newID)+1];
    strcpy(IDNumber, newID);
}

void Client::setMoney(double m){
    money = m;
}

void Client::setPosition(Position p){
    position.x = p.x;
    position.y = p.y;
}

char* Client::getName() const{
    return name;
}

char* Client::getIDNumber() const{
    return IDNumber;
}

double Client::getMoney() const{
    return money;
}

Position Client::getPosition() const{
    return position;
}

Client& Client::operator=(const Client& c){
    setName(c.getName());
    setID(c.getIDNumber());
    setMoney(c.getMoney());
    setPosition(c.getPosition());
    return *this;
}

bool Client::rent(int carID, Car* cars, int carCnt){
    for(int i = 0; i < carCnt; i++){
        if(cars[i].getID() == carID){
            if(cars[i].isRented() && getMoney() < cars[i].getRentSum()) break;
            cars[i].setRented(true);
            return 1; 
        }
    }
    return 0;
}

double Client::findDistance(int carID, Car* cars, int carCnt){
    for(int i = 0; i < carCnt; i++){
        if(cars[i].getID() == carID){
            return abs(cars[i].getPosition().x - getPosition().x)
                + abs(cars[i].getPosition().y - getPosition().y);
        }
    }
    throw "No such car found";
    return -1;
}