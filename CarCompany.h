#include "Car.h"
#include "Client.h"

class CarCompany{

    private:
        Car* cars;
        unsigned carCount;
        unsigned carsCapacity;

        Client* clients;
        unsigned clientCount;
        unsigned clientsCapacity;

    public:

        Car* getCars();

        void addCar(const Car&);

        void removeCarByID(int);

        void removeClient(int);

        Client& operator=(const Client&);

};