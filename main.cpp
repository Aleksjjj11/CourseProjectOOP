#include "Container.h"

using namespace std;

int main() {
    Container cont;
    cont.Add(*(new Item("ab")));
    cont.Print();
    cont.Add(*(new Item("ac")));
    cont.Print();
    cont.Add(*(new Item("aa")));
    cont.Print();
    cout << cont.Count() << endl;
    cont.SortUp();
    cont.Print();
    //cout << cont["b"].GetKey();
    return 0;
}
