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
            //ако това не е ID на последната кола - разменяме последната и тази
            if(i != carCount-1){
                cars[i] = cars[carCount-1];
            }
            //ако е последната просто намаляме броя коли
            //това се ползва и в другия случай
            carCount--;
        }
}

void CarCompany::removeClient(int IDNumber){
    for(int i = 0; i < carCount; i++)
        if(clients[i].getID() == IDNumber){
            //ако това не е ID на последния човек - разменяме последнатя и този
            if(i != clientCount-1){
                clients[i] = clients[clientCount-1];
            }
            //ако е последната просто намаляме броя клиенти
            clientCount--;
        }
}