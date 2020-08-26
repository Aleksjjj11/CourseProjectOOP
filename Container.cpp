#include "Container.h"

Item &Container::operator[](std::string key) {

}

Item &Container::operator[](int index) {

}

bool Container::Delete(std::string key) {

}

void Container::Add(Item &item) {
    if (this->first == nullptr) {
        this->first = this->last = &item;
    } else {
        this->last->SetNext(&item);
        item.SetPrev(this->last);
        item.SetNext(nullptr);
        this->last = &item;
    }
}

Container::~Container() {

}

Container::Container() {
    this->first = nullptr;
    this->last = nullptr;
}

int Container::Count() {
    if (first == nullptr) return 0;
    if (first == last) return 1;
    Item *loc = first;
    int counter = 0;
    while (loc != nullptr) {
        counter++;
        loc = loc->GetNext();
    }
    return counter;
}
