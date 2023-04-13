#include "CarCompany.h"

Car* CarCompany::getCars(){
    return cars;
}

void CarCompany::addCar(const Car& c){
    //проверка дали колата е вече в списъка
    for(int i = 0; i < carCount; i++)
        if(cars[i].getID() == c.getID()) return;

    //проверка за надхвърляне капацитета на масива и разширяване
    if(carCount >= carsCapacity){
        carsCapacity += 10;
        Car* newCars = new Car[carsCapacity];

        for(int i = 0; i < carCount; i++)
            newCars[i] = cars[i];

        delete []cars;
        cars = newCars;
    }
    //добавяне на коолата
    cars[carCount] = c;
    carCount += 1;
}


//сигурни сме, че всяка кола в списъка е с уникално ID
void CarCompany::removeCarByID(int ID){
    for(int i = 0; i < carCount; i++)
        if(cars[i].getID() == ID){
            //разменяме последната и тази
            cars[i] = cars[carCount-1];
            carCount--;
    }
}

void CarCompany::removeClient(int IDNumber){
    for(int i = 0; i < carCount; i++)
        if(clients[i].getID() == IDNumber){
            //разменяме последнатя и този
            clients[i] = clients[clientCount-1];
            clientCount--;
    }
}