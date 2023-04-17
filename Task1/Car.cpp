#include "Car.h"
#include <cstring>

Car::Car(int _ID, char* _number, double _rentSum, Position _position){
    if(_ID == 0) throw "ID can't be 0";
    setID(_ID);
    setNumber(_number);
    setRentSum(_rentSum);
    setPosition(_position);
}

Car::Car(int _ID, char* _number, double _rentSum, int x, int y){
    if(_ID == 0) throw "ID can't be 0";
    setID(_ID);
    setNumber(_number);
    setRentSum(_rentSum);
    Position p;
    p.x = x; p.y = y;
    setPosition(p);
}

Car::Car(){
    ID = 0;
    number[0] = '\0';
    rentSum = 0;
    position.x = 0;
    position.y = 0;
}

Car::Car(const Car& c){
    setID(c.getID());
    setNumber(c.getNumber());
    setRentSum(c.getRentSum());
    setPosition(c.getPosition());
    setRented(c.isRented());
}

void Car::setID(int newID){
    if(newID == 0) throw "ID can't be 0";
    ID = newID;
}

void Car::setNumber(char* newNumber){
    strcpy(number, newNumber);
}

void Car::setRentSum(double sum){
    rentSum = sum;
}

void Car::setPosition(Position p){
    position.x = p.x;
    position.y = p.y;
}

void Car::setRented(bool r){
    rented = r;
}

int Car::getID() const{
    return ID;
}

int Car::getRentSum() const{
    return rentSum;
}

char* Car::getNumber() const{
    return number;
}

Position Car::getPosition() const{
    return position;
}

bool Car::isRented() const{
    return rented;
}

Car& Car::operator=(const Car& c){
    if(this == &c) return *this;

    setID(c.getID());
    setNumber(c.getNumber());
    setRentSum(c.getRentSum());
    setPosition(c.getPosition());
    setRented(c.isRented());
    return *this;
}

Car::~Car(){
    delete []getNumber();
}