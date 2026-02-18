#include <iostream>
#include "CircularLL.h"

using namespace std;

CircularLL::Node::Node(ElementType data, Node *next) : data(data), next(next) {}

CircularLL::CircularLL() : first(NULL) {}

CircularLL::CircularLL(const CircularLL &other)
{
    if (other.first == NULL)
    {
        first == NULL;
    }
    else
    {
        // copy first element
        first = new Node(other.first->data);

        // create 2 pointers to traverse both lists
        NodePtr thisTrav = first;
        NodePtr otherTrav = other.first->next;

        while (otherTrav != other.first)
        {
            thisTrav->next = new Node(otherTrav->data);
            thisTrav = thisTrav->next;
            otherTrav = otherTrav->next;
        }
        // make last node point to first
        thisTrav->next = first;
    }
}

CircularLL::~CircularLL()
{
    if (first != NULL) // not empty
    {
        NodePtr temp;
        NodePtr savedFirst = first;
        while (first->next != savedFirst)
        {
            temp = first;
            first = first->next;

            delete temp;
        }
        // if first->next == first, it means the first is also the last node ==> one node left
        delete first;
    }
}

CircularLL &CircularLL::operator=(const CircularLL &other)
{
    if (this != &other) // not the same list
    {
        // delete this (use destructor)
        NodePtr temp = first;
        while (first->next != first)
        {
            first = first->next;
            delete temp;
        }
        // if first->next == first, it means the first is also the last node ==> one node left
        delete first;

        // copy other list into this
        if (other.first == NULL)
        {
            first == NULL;
        }
        else
        {
            // copy first element
            first = new Node(other.first->data);

            // create 2 pointers to traverse both lists
            NodePtr thisTrav = first;
            NodePtr otherTrav = other.first->next;

            while (otherTrav != other.first)
            {
                thisTrav->next = new Node(otherTrav->data);
                thisTrav = thisTrav->next;
                otherTrav = otherTrav->next;
            }
            // make last node point to first
            thisTrav->next = first;
        }
    }
    return *this;
}

bool CircularLL::isEmpty() const
{
    return first == NULL;
}

int CircularLL::size() const
{
    if (first == NULL)
        return 0;

    int size = 1;
    for (NodePtr temp = first->next; temp != first; temp = temp->next)
    {
        size++;
    }
    return size;
}

void CircularLL::insertAtBeginnning(const ElementType &e)
{
    if (first == NULL)
    {
        first = new Node(e); // first is NULL while assigning to it
        first->next = first;
    }
    else
    {
        // add to end and then change it to first

        NodePtr temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }

        // temp now points to last node

        NodePtr other = new Node(e);
        other->next = first;
        first = other;
        temp->next = first; // last node now points to first node
    }
}

void CircularLL::insertAtEnd(const ElementType &e)
{
    if (first == NULL)
    {
        first = new Node(e);
        first->next = first;
    }
    else
    {
        NodePtr temp = first;
        while (temp->next != first)
        {
            temp = temp->next;
        }
        temp->next = new Node(e);
        temp->next->next = first;
        // without modified constructor
        // temp->next = new Node(e);
        // temp->next->next = first;
    }
}

bool CircularLL::insertAtPos(int position, const ElementType &e)
{
    if (position < 0)
    {
        cerr << "ERROR: invalid position\n";
        return false;
    }
    if (position == 0) // insert at start of CLL
    {

        if (first == NULL) // insert at start of empty CLL
        {
            first = new Node(e);
            first->next = first;
        }
        else // insert at start of non-empty CLL
        {
            NodePtr temp = first;
            while (temp->next != first)
            {
                temp = temp->next;
            }

            NodePtr other = new Node(e);
            other->next = first;
            first = other;
            temp->next = other;
        }
    }
    else // insert in the middle (or end) of CLL
    {
        if (first == NULL) // impossible to insert in middle of empty CLL
        {
            return false;
        }
        else // insert in middle of non-empty CLL
        {
            // insert at n means to insert after n-1, so we stop at n-1 (or start counting from 1)
            int count = 1;
            NodePtr temp = first;
            while (count < position && temp->next != first)
            {
                count++;
                temp = temp->next;
            }

            if (count < position) // list was traversed, position too big
            {

                cerr << "ERROR: Invalid position (too big)\n";
                return false;
            }
            else if (count == position && temp->next == first) // insert at end
            {
                temp->next = new Node(e);
                temp->next->next = first;
            }
            else // valid position
            {
                // insert at temp->next
                NodePtr newPtr = new Node(e);
                newPtr->next = temp->next;
                temp->next = newPtr;
            }
        }
    }
    return true;
}

bool CircularLL::deleteAtBeginning()
{
    if (first == NULL)
    {
        cerr << "ERROR: list is empty\n";
        return false;
    }

    NodePtr temp = first;
    // change last node first because we won't be able to know last node if we delete current first node
    while (temp->next != first)
    {
        temp = temp->next;
    }
    NodePtr other = first;
    first = first->next;
    delete other;

    temp->next = first;

    return true;
}

bool CircularLL::deleteAtEnd()
{
    if (first == NULL)
    {
        cerr << "ERROR: list is empty\n";
        return false;
    }
    else if (first->next == first)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodePtr temp = first;
        while (temp->next->next != first)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = first;
    }
    return true;
}

void CircularLL::display(ostream &out) const
{
    if (first == NULL)
    {
        out << "List is empty\n";
    }
    else
    {
        NodePtr temp = first;
        out << "List size: " << size() << "\n";
        do
        {
            out << temp->data << " ";
            temp = temp->next;
        } while (temp != first);
        out << endl;
    }
}

ostream &operator<<(std::ostream &out, const CircularLL &list)
{
    list.display(out);
    return out;
}
