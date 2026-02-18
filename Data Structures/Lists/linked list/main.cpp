#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    /*
        // LinkedList list = new LinkedList(); dynamic
        LinkedList list; // static

        for (int i = 0; i < 20; i++)
            list.insertAtEnd(i);

        cout << list;

        list.insertAtPos(22, 0);
        list.insertAtPos(20, 0);

        cout << list;

        list.insertAtPos(100, 3);
        list.insertAtPos(50, 12);
        cout << list << endl << endl;

        list.insertAfterElement(88, 8);
        list.insertAfterElement(-2, 20);
        list.insertAfterElement(-199, 9);
        list.insertAfterElement(2121, 123);
        cout << list;

        list.insertBeforeElement(99, 12);
        list.insertBeforeElement(30, 5);
        list.insertBeforeElement(100, 0);

        list.insertBeforeElement(1020, 14);

        // cout << list << endl;

        list.deleteAtPos(2);
        list.deleteAtPos(4);
        cout << list << endl;

        list.deleteAfterElement(12);
        list.deleteAtPos(4);
        list.deleteAfterElement(2);
        list.deleteAfterElement(14);
        list.deleteAtPos(0);
        cout << list << "\n\n\n";

        list.deleteElement(12);
        list.deleteElement(1);
        list.deleteElement(14);
        cout << list << endl;



        list.deleteBeforeElement(190);

        cout << list << endl;
    */

    /*
        LinkedList ls;
        ls.insertAtEnd(1);
        ls.insertAtEnd(2);
        ls.insertAtEnd(3);
        ls.insertAtEnd(4);
        ls.insertAtEnd(5);

        cout << ls;

        LinkedList other(ls);

        other.insertAfterElement(12, 3);
        cout << "other\t" << other;
        cout << "ls\t" << ls;

        ls = other;

        cout << "\nother\t" << other;
        cout << "ls\t" << ls;
    */

    LinkedList list1;
    for (int i = 0; i < 10; i++)
    {
        list1.insertAtEnd(i * 3);
    }
    cout << "List 1:\t" << list1;

    LinkedList list2;
    for (int i = 0; i < 15; i++)
    {
        list2.insertAtEnd(i * 2);
    }
    cout << "List 2:\t" << list2;

    LinkedList sorted = list1.mergeSortedLists(list2);

    cout << "Sorted:\t\t" << sorted;

    sorted.reverse();
    cout << "Reversed:\t" << sorted;
}
