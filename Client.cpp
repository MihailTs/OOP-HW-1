#include "Client.h"
#include "Car.h"
#include <cstring>
#include <cmath>

Client::Client(){
    name = new char[1];
    name[0] = '\0';
    IDNumber = 0;
    money = 0;
    position.x = 0;
    position.y = 0;
}

Client::Client(char* _name, int _IDNumber, double _money, Position _position){
    name = new char[strlen(name)+1];
    strcpy(name, _name);
    setID(_IDNumber);
    setMoney(_money);
    setPosition(_position);
}

Client::Client(const Client& c){
    name = new char[strlen(c.getName())+1];
    strcpy(name, c.getName());
    setID(c.getID());
    setMoney(c.getMoney());
    setPosition(c.getPosition());
}

void Client::setName(char* newName){
    delete []name;
    name = new char[strlen(newName)+1];
    strcpy(name, newName);
}

void Client::setID(int newID){
    IDNumber = newID;
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

int Client::getID() const{
    return IDNumber;
}

double Client::getMoney() const{
    return money;
}

Position Client::getPosition() const{
    return position;
}

Client& Client::operator=(const Client& c){
    if(this == &c) return *this;

    setName(c.getName());
    setID(c.getID());
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

Client::~Client(){
    delete []getName();
}