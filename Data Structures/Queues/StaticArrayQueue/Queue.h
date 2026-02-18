#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

typedef int ElementType;
const int CAPACITY = 5;

class Queue
{
public:
    Queue();

    bool isEmpty() const;
    bool isFull() const;

    ElementType getFront() const; // cannot be named the same as a data field

    bool enqueue(const ElementType &e);
    bool dequeue();

    void display(std::ostream &) const;

private:
    ElementType array[CAPACITY];
    int front,
        back;
};

std::ostream &operator<<(std::ostream &, const Queue &);

#endif
