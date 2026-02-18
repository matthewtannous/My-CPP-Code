#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

typedef int ElementType;

class Queue
{
private:
    class Node
    {
    public:
        Node(const ElementType &e);
        ElementType data;
        Node *next;
    };
    typedef Node *NodePtr;

public:
    Queue();
    Queue(const Queue &other);
    ~Queue();

    Queue &operator=(const Queue &other);

    bool isEmpty() const;
    ElementType getFront() const; // cannot be named the same as a data field

    void enqueue(const ElementType &e);
    bool dequeue();

    void display(std::ostream &) const;

private:
    NodePtr front,
        back;
};

std::ostream &operator<<(std::ostream &, const Queue &);

#endif
