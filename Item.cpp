#include "Item.h"
Item::Item() {
    this->key = "";
    this->prev = nullptr;
    this->next = nullptr;
}

Item::Item(std::string k, Item &prv, Item& nxt) {
    this->key = k;
    this->prev = &prv;
    this->next = &nxt;
}
