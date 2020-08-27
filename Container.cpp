#include <cstring>
#include "Container.h"

Item &Container::operator[](std::string key) {
    if (first == nullptr) {
        printf("Container have nothing.\n");
        exit(0);
    }
    for (int i = 0; i < Count(); i++) {
        if ((*this)[i].GetKey() == key)
            return (*this)[i];
    }

    printf("The key not found.\n");
    exit(0);
}

Item &Container::operator[](int index) {
    if (index < 0 || index >= Count()) {
        printf("Incorrect index. %i\n", index);
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
    while (Count() > 0)
        Remove(first->GetKey());
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
        printf("Container have nothing.\n");
        return;
    }
    Item* item = first;
    while (item != nullptr) {
        std::cout << item->GetKey() << " ";
        item = item->GetNext();
    }
    std::cout << std::endl;
}

void Container::SortUp() {
    for (int i = 0; i < Count(); i++) {
        for (int j = 0; j < Count() - 1; j++) {
            Item* item1 = &(*this)[j];
            Item* item2 = &(*this)[j+1];
            if (item1->GetKey() > item2->GetKey()) {
                Swap(item1, item2);

                if (j == 0)
                    this->first = item2;
                if (j == Count() - 1)
                    this->last = item1;
            }
        }
    }
}

void Container::SortDown() {

}

void Container::Swap(Item *item1, Item *item2) {
    Item* med = item2->GetNext();
    item2->SetNext(item1);
    item1->SetNext(med);
    if (med != nullptr)
        med->SetPrev(item1);

    med = item1->GetPrev();
    item1->SetPrev(item2);
    item2->SetPrev(med);
    if (med != nullptr)
        med->SetNext(item2);

    /*if (item1->GetNext() != nullptr)
        item1->GetNext()->SetPrev(item1);
    if (item2->GetPrev() != nullptr)
        item2->GetPrev()->SetNext(item2);*/
}
