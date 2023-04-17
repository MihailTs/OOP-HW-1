#include "Store.h"
#include <cstring>

Store::Store(){
    items = new Item[1];
    setItemsCount(0);
    setItemsCapacity(1);
}

void Store::setItemsCount(unsigned cnt){
    itemCount = cnt;
}

void Store::setItems(Item* newItems){
    delete []items;
    items = newItems;
}

void Store::setItemsCapacity(unsigned cap){
    capacity = cap;
}

unsigned Store::getItemsCount() const{
    return itemCount;
}

unsigned Store::getItemsCapacity() const{
    return capacity;
}

Item* Store::getItems() const{
    return items;
}

bool Store::checkAvailability(char* name){
    for(int i = 0; i < getItemsCount(); i++)
        if(strcmp(getItems()[i].getName(), name) == 0 && getItems()[i].getCount() > 0) return true;
    return false;
}

void Store::swapItems(unsigned i, unsigned j){
    Item temp;
    temp = getItems()[i];
    getItems()[i] = getItems()[j];
    getItems()[j] = temp;
}

void Store::removeItem(char* name){
    for(int i = 0; i < getItemsCount(); i++){
        if(strcmp(getItems()[i].getName(), name) == 0){
            swapItems(i, getItemsCount()-1);
            setItemsCount(getItemsCount()-1);
        }
    }
}

void Store::sell(char* name){
    for(int i = 0; i < getItemsCount(); i++){
        if(strcmp(getItems()[i].getName(), name) == 0){
            if(getItems()[i].getCount() > 0){
                getItems()[i].setCount(getItems()[i].getCount()-1);
                removeItem(name);
                return;
            }
        }
    }
    throw "No such item";
}

void Store::add(const Item& it){
    if(getItemsCount() >= getItemsCapacity()){
            Item* newElements = new Item[getItemsCount() + 10];

            setItemsCapacity(getItemsCapacity() + 10);

            for(int i = 0; i < getItemsCount(); i++)
                newElements[i] = getItems()[i];

            delete []getItems();
            setItems(newElements);
        }
        getItems()[getItemsCount()] = it;
        setItemsCount(getItemsCount()+1);
}


//operator<<


Store Store::operator+(const Store& store){
    Store s;
    for(int i = 0; i < getItemsCount(); i++)
        s.add(getItems()[i]);

    for(int i = 0; i < store.getItemsCount(); i++)
        s.add(store.getItems()[i]);
    
    return s;
}

Store::~Store(){
    delete []items;
}