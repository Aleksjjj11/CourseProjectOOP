#include "Container.h"

Item &Container::operator[](std::string key) {
    if (first == nullptr) {
        printf("Container have nothing.");
        exit(0);
    }
    for (int i = 0; i < Count(); i++) {
        if ((*this)[i].GetKey() == key)
            return (*this)[i];
    }

    printf("The key not found.");
    exit(0);
}

Item &Container::operator[](int index) {
    if (index < 0 || index >= Count()) {
        printf("Incorrect index.");
        exit(0);
    }
    int counter = 0;
    Item* item = first;
    while (counter < index) {
        item = item->GetNext();
        counter++;
    }
    return *item;
}

bool Container::Delete(std::string key) {

}

void Container::Add(Item &item) {
    if (this->first == nullptr) {
        this->first = this->last = &item;
        item.SetNext(nullptr);
        item.SetPrev(nullptr);
        return;
    }
    if (Count() == 1) {
        this->last = &item;
        this->first->SetNext(&item);
        item.SetPrev(first);
        item.SetNext(nullptr);
        return;
    }
    this->last->SetNext(&item);
    item.SetPrev(this->last);
    item.SetNext(nullptr);
    this->last = &item;
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

void Container::Clear() {

}

void Container::Remove(std::string key) {
    Item* item = &((*this)[key]);
    //Если удаляется один единственный элемент
    if (Count() == 1) {
        first = last = nullptr;
        delete &item;
        return;
    }
    //Если удаляем первый элемент
    if (item == first) {
        first = first->GetNext();
        first->SetPrev(nullptr);
        delete item;
        return;
    }
    //Если удаляем последний элемент
    if (item == last) {
        last = last->GetPrev();
        last->SetNext(nullptr);
        delete item;
        return;
    }
    //Удаление любого другого
    item->GetPrev()->SetNext(item->GetNext());
    item->GetNext()->SetPrev(item->GetPrev());
    delete &item;
}

void Container::Print() {
    if (first == nullptr) {
        printf("Container have nothing.");
        return;
    }
    Item* item = first;
    while (item != nullptr) {
        std::cout << item->GetKey() << " ";
        item = item->GetNext();
    }
    std::cout << std::endl;
}
