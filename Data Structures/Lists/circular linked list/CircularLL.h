#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include <iostream>

typedef int ElementType;

class CircularLL
{
private:
    class Node
    {
    public:
        // Node(ElementType data); // or Node(const ElementType &e)
        Node(ElementType data, Node *next = NULL);
        ElementType data;
        Node *next;
    };
    typedef Node *NodePtr;

public:
    // Constructors + Destructor
    CircularLL();
    CircularLL(const CircularLL &other);
    ~CircularLL();
    CircularLL &operator=(const CircularLL &other);

    // Check list
    bool isEmpty() const;
    int size() const;

    // Insert elements
    void insertAtBeginnning(const ElementType &e);
    void insertAtEnd(const ElementType &e);
    bool insertAtPos(int position, const ElementType &e);
    // can add insert after/before element

    // delete elements
    bool deleteAtBeginning();
    bool deleteAtEnd();
    bool deleteAtPos();

    // display list
    void display(std::ostream &out) const;

private:
    NodePtr first;
};

std::ostream &operator<<(std::ostream &out, const CircularLL &list);

#endif
