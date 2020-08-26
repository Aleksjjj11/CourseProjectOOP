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
    Item(std::string k);
    void SetNext(Item *item) {next = item;}
    void SetPrev(Item *item) {prev = item;}
    Item* GetNext() {return next;}
    Item* GetPrev() {return prev;}
};

#endif //COURSEPROJECTOOP_ITEM_H
