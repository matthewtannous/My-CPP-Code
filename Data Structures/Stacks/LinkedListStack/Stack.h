#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef char ElementType;

class Stack
{
private:
    class Node
    {
    public:
        Node(const ElementType &data);
        ElementType data;
        Node *next;
    };
    typedef Node *NodePtr;

public:
    Stack();
    Stack(const Stack &other);
    ~Stack();

    Stack &operator=(const Stack &other);

    bool isEmpty() const;
    ElementType top() const;

    void push(const ElementType &e);
    bool pop();

    void display(std::ostream &) const;

private:
    NodePtr first;
};

std::ostream &operator<<(std::ostream &out, const Stack &stack);

#endif
