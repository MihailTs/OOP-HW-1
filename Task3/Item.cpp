#include "Item.h"
#include <cstring>

Item::Item(){
    name = new char[1];
    name[0] = '\0';
    count = 0;
}

Item::Item(char* n, unsigned cnt){
    setName(n);
    setCount(cnt);
}

Item::Item(const Item& i){
    setName(i.getName());
    setCount(i.getCount());
}

char* Item::getName() const{
    return name;
}

unsigned Item::getCount() const{
    return count;
}

void Item::setName(char* n){
    name = new char[strlen(n)+1];
    strcpy(name, n);
}

void Item::setCount(unsigned cnt){
    count = cnt;
}

Item& Item::operator=(const Item& i){
    if(this == &i) return *this;

    delete []name;
    setName(i.getName());
    setCount(i.getCount());
    return *this;
}

Item::~Item(){
    delete []name;
}

std::ostream& operator<<(std::ostream& out, const Item& i){
    out << i.getName() << "   " << i.getCount();
    return out;
}