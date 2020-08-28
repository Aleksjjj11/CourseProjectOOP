#include "Container.h"

using namespace std;

int main() {
    Container cont;
    cont.Add(*(new Item("I")));
    cont.Add(*(new Item("B")));
    cont.Print();
    Container cont2;
    cont2.Add(*(new Item("V")));
    cont2.Add(*(new Item("G")));
    cont2.Add(*(new Item("I")));
    cont2.Add(*(new Item("D")));
    cont2.Print();
    cont2 = cont;
    cont2.Print();
    return 0;
}
