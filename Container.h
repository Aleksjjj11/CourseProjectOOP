#ifndef COURSEPROJECTOOP_CONTAINER_H
#define COURSEPROJECTOOP_CONTAINER_H

#include <iostream>
#include "Item.h"

class Container {
private:
    Item *first;
    Item *last;
    void Swap(Item* item1, Item* item2);
public:
    void Add(Item &item); //добавление элемента и его ключа
    bool Delete(std::string key); //Удаление элемента по ключу
    virtual Item &operator [](std::string key); //доступ к эдементу по ключу
    virtual Item &operator [](int index); //доступ к элементу по индексу
    Item* GetFirst() {return first;};
    Item* GetLast() {return last;};
    ~Container(); //TODO должен освободить память от всех элементов списка
    Container();
    int Count();
    void Clear();
    void Remove(std::string key);
    void Print();
    void SortUp();
    void SortDown();
};

#endif //COURSEPROJECTOOP_CONTAINER_H