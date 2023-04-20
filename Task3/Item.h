#pragma once
#include <ostream>

class Item{

    private:
        char* name;
        unsigned count;

        void setName(char*);

        void setCount(unsigned);

    public:

        Item();

        Item(char*, unsigned);

        Item(const Item&);

        char* getName() const;

        unsigned getCount() const;

        Item& operator=(const Item&);

        friend std::ostream& operator<<(std::ostream&, const Item&);

        ~Item();

        friend class Store;
};