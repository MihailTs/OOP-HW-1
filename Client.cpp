#include "Client.h"
#include <cstring>

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