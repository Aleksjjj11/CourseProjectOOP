#include "Container.h"

using namespace std;

int main() {
    Container cont;
    cont.Add(*(new Item("b")));
    cont.Print();
    cont.Add(*(new Item("c")));
    cont.Print();
    cont.Add(*(new Item("d")));
    cont.Print();
    cont.Remove("b");
    cont.Print();
    cont.Clear();
    cont.Print();
    cont.Add(*(new Item("c")));
    cont.Add(*(new Item("d")));
    cont.Print();
    //cout << cont["b"].GetKey();
    return 0;
}
