#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
    cout << boolalpha;
    Tree t;

    t.insert(50);
    t.insert(20);
    t.insert(70);

    t.insert(10);

    t.insert(25);
    t.insert(60);
    t.insert(80);
    t.insert(300);

    t.insert(1);
    t.insert(213);

    cout << t;

    ElementType e = 0;
    cout << t.level(e) << " " << t.levelIterative(e) << endl;

    cout << "Height: " << t.height() << endl;
    cout << "Leaves: " << t.leafCount() << endl;

    cout << "\n\nIn order recursively: " << t;
    cout << "In order iteratively: ";
    t.inOrderIterative(cout);

    cout << "Level by Level:\n";
    t.levelByLevel(cout);

    cout << "\n\n\n"
         << t;

    cout << t.removeRecursive(50) << endl
         << t;
}
