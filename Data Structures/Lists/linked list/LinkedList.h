#ifndef LINKEDLIST_H
#define LINDEDLIST_H

#include <iostream>

typedef int ElementType;

class LinkedList
{
private:
    class Node
    {
    public:
        // Node(const ElementType &data)
        // {
        //     this->data = data;
        //     next = NULL; // next is NOT a node, it is a pointer to a node
        // }
        // // ~Node() NOOO. Do not delete the next node. let the default constructor destroy the static data fields. LinkedList class will handle the nodes
        // // {
        // //     delete next;
        // // }
        Node(const ElementType &data);
        ElementType data;
        Node *next;
    };
    typedef Node *NodePtr;

public:
    // Constructors
    LinkedList();
    LinkedList(const LinkedList &other);
    ~LinkedList();
    LinkedList &operator=(const LinkedList &rightHandSide);

    // List info
    int getSize() const;
    bool isEmpty() const;

    // Add elements
    void insertAtEnd(const ElementType &e);
    bool insertAtPos(const ElementType &e, int pos);

    bool insertAfterElement(const ElementType &inserted, const ElementType &after);
    bool insertBeforeElement(const ElementType &inserted, const ElementType &before);

    // Remove elements
    bool deleteAtPos(int pos);

    bool deleteAfterElement(const ElementType &e);
    bool deleteElement(const ElementType &e);
    bool deleteBeforeElement(const ElementType &e);

    // // Modify elements in place
    // bool modify(int pos, const ElementType &e);
    // // bool modify(const ElementType &oldVal, const ElementType &newVal);

    // Other
    // int search(const ElementType &e) const; // too easy
    void display(std::ostream &out) const;

    // extra (book exercise 6_4_9)
    LinkedList mergeSortedLists(const LinkedList &other);
    // extra (book exercise 6_4_8)
    void deleteNthNode(int n);


    // extra (self)
    void reverse();

private:
    NodePtr first;
    int size;
};

std::ostream &operator<<(std::ostream &out, const LinkedList &list);

#endif
