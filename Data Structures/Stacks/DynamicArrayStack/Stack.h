#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef double ElementType;

class Stack
{
public:
    Stack(int size = 8);
    Stack(const Stack &other);
    ~Stack();

    bool isEmpty() const;
    ElementType top() const;

    void push(const ElementType &e);
    bool pop();

    void display(std::ostream &out) const;

    const Stack &operator=(const Stack &other);

public:
    int capacity;
    int myTop;
    ElementType *myArray;
};

std::ostream &operator<<(std::ostream &out, const Stack stack);

#endif
