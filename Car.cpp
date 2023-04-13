#include "Car.h"
#include <cstring>

void Car::setID(int newID){
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
    setID(c.getID());
    setNumber(c.getNumber());
    setRentSum(c.getRentSum());
    setPosition(c.getPosition());
    setRented(c.isRented());
    return *this;
}