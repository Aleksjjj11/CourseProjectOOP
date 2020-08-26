#include <string>
#ifndef COURSEPROJECTOOP_ITEM_H
#define COURSEPROJECTOOP_ITEM_H

class Item {
private:
    std::string key;
    Item *prev;
    Item *next;
public:
    std::string GetKey() {return key;}
    Item();
    Item(std::string k, Item &pr, Item& nxt);
};

#endif //COURSEPROJECTOOP_ITEM_H
