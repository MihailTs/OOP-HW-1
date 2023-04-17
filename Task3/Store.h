#pragma once
#include "Item.h"
#include <ostream>

class Store{

    private:
        Item* items;
        unsigned itemCount;
        unsigned capacity;
        const unsigned enlargement = 10;

        void setItems(Item*);

        void setItemsCount(unsigned);

        void setItemsCapacity(unsigned);

        void swapItems(unsigned, unsigned);

    private:

        Store();

        unsigned getItemsCount() const;

        unsigned getItemsCapacity() const;

        Item* getItems() const;

        void removeItem(char*);

        void sell(char*);

        bool checkAvailability(char*);

        void add(Item);

        Store operator+(const Store&);

        friend std::ostream& operator<<(std::ostream&, const Item&);

        ~Store();
};