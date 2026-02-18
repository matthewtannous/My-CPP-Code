#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Node::Node(const ElementType &data) : data(data), next(NULL) {}

Stack::Stack() : first(NULL) {}

Stack::Stack(const Stack &other)
{
    if (other.first == NULL)
    {
        first = NULL;
    }
    else
    {
        first = new Node(other.first->data);
        NodePtr thisTemp = first;
        NodePtr otherTemp = other.first->next;

        while (otherTemp != NULL)
        {
            thisTemp->next = new Node(otherTemp->data);
            thisTemp = thisTemp->next;
            otherTemp = otherTemp->next;
        }
    }
}

Stack::~Stack()
{
    NodePtr temp = first;
    while (first != NULL)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

Stack &Stack::operator=(const Stack &other)
{
    if (this != &other)
    {
        NodePtr temp = first;
        while (first != NULL)
        {
            first = first->next;
            delete temp;
            temp = first;
        }

        if (other.first == NULL)
        {
            first = NULL;
        }
        else
        {
            first = new Node(other.first->data);
            NodePtr thisTemp = first;
            NodePtr otherTemp = other.first->next;

            while (otherTemp != NULL)
            {
                thisTemp->next = new Node(otherTemp->data);
                thisTemp = thisTemp->next;
                otherTemp = otherTemp->next;
            }
        }
    }
    return *this;
}

bool Stack::isEmpty() const
{
    return first == NULL;
}

ElementType Stack::top() const
{
    if (first == NULL)
    {
        // return garbage
        ElementType e;
        return e;
    }
    return first->data;
}

void Stack::push(const ElementType &e)
{
    if (first == NULL)
    {
        first = new Node(e);
    }
    else
    {
        NodePtr temp = new Node(e);
        temp->next = first;
        first = temp;
    }
}

bool Stack::pop()
{
    if (first == NULL)
    {
        return false;
    }
    NodePtr temp = first;
    first = first->next;
    delete temp;
    return true;
}

void Stack::display(ostream &out) const
{
    if (first == NULL)
    {
        out << "Stack is empty\n";
    }
    else
    {
        for (NodePtr temp = first; temp != NULL; temp = temp->next)
        {
            out << temp->data << " , ";
        }
        out << endl;
    }
}

ostream &operator<<(ostream &out, const Stack &stack)
{
    stack.display(out);
    return out;
}
