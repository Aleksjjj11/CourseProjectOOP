#include <iostream>
#include "Container.h"

using namespace std;

int main() {
    Container cont;
    cont.Add(*(new Item("b")));
    cout << cont.GetFirst().GetKey() << cont.GetLast().GetKey() << endl;
    cout << cont.Count() << endl;
    cont.Add(*(new Item("c")));
    cout << cont.GetFirst().GetKey() << cont.GetLast().GetKey() << endl;
    cout << cont.Count() << endl;
    cont.Add(*(new Item("d")));
    cout << cont.GetFirst().GetKey() << cont.GetLast().GetKey() << endl;
    cout << cont.Count() << endl;
    cout << cont[2].GetKey() << endl;
    cout << cont["c"].GetKey() << endl;
    return 0;
}
