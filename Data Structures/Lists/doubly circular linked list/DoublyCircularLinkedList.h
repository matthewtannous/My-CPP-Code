#ifndef DoublyCircularLinkedList_H
#define DoublyCircularLinkedList_H

#include <iostream>

using namespace std;

typedef int ElementType;

class DoublyCLL
{
private:
    class DNode
    {
    public:
        DNode(ElementType data);
        ElementType data;
        DNode *next;
        DNode *prev;
    };
    typedef DNode *DNodePtr;

    DNodePtr first;

public:
    // constructors, destructor and assignement
    DoublyCLL();
    DoublyCLL(const DoublyCLL &);
    ~DoublyCLL();
    DoublyCLL &operator=(const DoublyCLL &);

    // list data
    bool isEmpty() const;
    int size() const;

    // insert
    void insertAtBegin(const ElementType);
    void insertAtEnd(const ElementType);

    bool insertAfterElement(const ElementType &inserted, const ElementType &after);
    bool insertBeforeElement(const ElementType &inserted, const ElementType &after);

    // delete
    bool deleteFromBegin();
    bool deleteFromEnd();

    bool deleteElement(const ElementType &e);
    bool deleteAfterElement(const ElementType &e);
    bool deleteBeforeElement(const ElementType &e);

    // display
    void displayList(ostream &) const;
    void displayReverse(ostream &) const;
};

ostream &operator<<(ostream &, const DoublyCLL &);

#endif
