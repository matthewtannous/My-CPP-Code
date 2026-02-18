#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

typedef int ElementType;

class Queue
{
public:
    Queue(int capacity = 5);

    Queue(const Queue &other);
    ~Queue();
    Queue &operator=(const Queue &other);

    bool isEmpty() const;
    // bool isFull() const;

    ElementType getFront() const; // cannot be named the same as a data field

    bool enqueue(const ElementType &e);
    bool dequeue();

    void display(std::ostream &) const;

private:
    ElementType *array;
    int front,
        back,
        myCapacity;
};

std::ostream &operator<<(std::ostream &, const Queue &);

#endif
