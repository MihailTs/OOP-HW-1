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

        void setClientCount(unsigned);

        void setCarCount(unsigned);

        void setClientsCapacity(unsigned);

        void setCarsCapacity(unsigned);

    public:

        CarCompany();

        CarCompany(const CarCompany&);

        Car* getCars() const;

        Client* getClients() const;

        unsigned getCarCount() const;

        unsigned getClientCount() const;

        unsigned getCarsCapacity() const;

        unsigned getClientsCapacity() const;

        void addCar(const Car&);

        void addClient(const Client&);

        void removeCarByID(int);

        void removeClient(int);

        //няма оператор =, защото се предполага,
        //че ще има само една компания        

        ~CarCompany();
};