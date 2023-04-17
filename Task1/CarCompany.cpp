#include "CarCompany.h"

void CarCompany::setClientCount(unsigned cnt){
    clientCount = cnt;
}

void CarCompany::setCarCount(unsigned cnt){
    carCount = cnt;
}

void CarCompany::setCarsCapacity(unsigned cap){
    carsCapacity = cap;
}

void CarCompany::setClientsCapacity(unsigned cap){
    clientsCapacity = cap;
}

CarCompany::CarCompany(const CarCompany& carComp){
    setCarCount(carComp.getCarCount());
    setCarsCapacity(carComp.getCarsCapacity());
    cars = new Car[getCarsCapacity()];
    for(int i = 0; i < getCarCount(); i++)
        cars[i] = carComp.getCars()[i];

    setClientCount(carComp.getClientCount());
    setClientsCapacity(carComp.getClientsCapacity());
    clients = new Client[getClientsCapacity()];
    for(int i = 0; i < getClientCount(); i++)
        clients[i] = carComp.getClients()[i];
}

CarCompany::CarCompany(){
    cars = new Car[1];
    carCount = 0;
    carsCapacity = 1;

    clients = new Client[1];
    clientCount = 0;
    clientsCapacity = 1;
}

Car* CarCompany::getCars() const{
    return cars;
}

Client* CarCompany::getClients() const{
    return clients;
}

unsigned CarCompany::getCarCount() const{
    return carCount;
}

unsigned CarCompany::getClientCount() const{
    return clientCount;
}

unsigned CarCompany::getCarsCapacity() const{
    return carsCapacity;
}

unsigned CarCompany::getClientsCapacity() const{
    return clientsCapacity;
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

void CarCompany::addClient(const Client& c){
    for(int i = 0; i < clientCount; i++)
        if(clients[i].getID() == c.getID() ) return;

    //проверка за надхвърляне капацитета на масива и разширяване
    if(clientCount >= clientsCapacity){
        clientsCapacity += 10;
        Client* newClients = new Client[clientsCapacity];

        for(int i = 0; i < clientCount; i++)
            newClients[i] = clients[i];

        delete []clients;
        clients = newClients;
    }
    //добавяне на коолата
    clients[clientCount] = c;
    clientCount += 1;

}

void CarCompany::removeCarByID(int ID){
    for(int i = 0; i < carCount; i++)
        if(cars[i].getID() == ID){
            cars[i] = cars[carCount-1];
            carCount--;
    }
}

void CarCompany::removeClient(int IDNumber){
    for(int i = 0; i < carCount; i++)
        if(clients[i].getID() == IDNumber){
            clients[i] = clients[clientCount-1];
            clientCount--;
    }
}

int CarCompany::findClient(int IDNumber){
    for(int i = 0; i < getClientCount(); i++)
        if(getClients()[i].getID() == IDNumber) return i;
    return -1;
}

int CarCompany::findCar(int ID){
    for(int i = 0; i < getCarCount(); i++)
        if(getCars()[i].getID() == ID) return i;
    return -1;
}

double CarCompany::findDistenceOfClientFromCar(int clientID, int carID){
    if(findClient(clientID) == -1 || findCar(carID) == -1) throw "Invalid ID numbers";
    return getClients()[findClient(clientID)].findDistanceFrom(carID, getCars(), getCarCount());
}

void CarCompany::rentCar(int clientID, int carID){
    if(findClient(clientID) == -1 || findCar(carID) == -1) throw "Invalid ID numbers";
    getClients()[findClient(clientID)].rent(carID, getCars(), getCarCount());
}

CarCompany::~CarCompany(){
    delete []clients;
    delete []cars;
}