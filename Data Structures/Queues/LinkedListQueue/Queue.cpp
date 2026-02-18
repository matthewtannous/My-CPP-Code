/**
 * In LL Queue, front points to the start of the list and back points to the end.
 *
 * We delete from front, so front must be able to move to the next element,
 *  which means it cannot be at the end.
 *
 * We insert at back, so it is easy to insert at the end of a LL.
 *
 * front is the same as myFirst in a LL.
 */

#include <iostream>
#include "Queue.h"
#include <cassert>

Queue::Node::Node(const ElementType &data)
    : data(data), next(NULL) {}

Queue::Queue() : front(NULL), back(NULL) {}

Queue::Queue(const Queue &other)
{
    if (other.back == NULL) // back == NULL --> front == NULL   empty
    {
        front = NULL;
        back = NULL;
    }

    // Copy everything starting from other.front

    // Copy first node
    front = new Node(other.front->data);

    // back must point to the end of the list
    back = front;

    NodePtr otherTemp = other.front->next;
    while (otherTemp != NULL)
    {
        back->next = new Node(otherTemp->data);
        back = back->next;
        otherTemp = otherTemp->next;
    }
    // When loop exits, back points the end of the list.
}

Queue::~Queue()
{
    // Deleting a LL
    NodePtr temp = front;
    while (front != NULL)
    {
        front = front->next;
        delete temp;
        temp = front;
    }
}

Queue &Queue::operator=(const Queue &other)
{
    if (this != &other)
    {
        // Delete old queue
        NodePtr temp = front;
        while (front != NULL)
        {
            front = front->next;
            delete temp;
            temp = front;
        }

        // Copy other queue into this
        if (other.back == NULL) // back == NULL --> front == NULL   empty
        {
            front = NULL;
            back = NULL;
        }

        // Copy everything starting from other.front

        // Copy first node
        front = new Node(other.front->data);

        // back must point to the end of the list
        back = front;

        NodePtr otherTemp = other.front->next;
        while (otherTemp != NULL)
        {
            back->next = new Node(otherTemp->data);
            back = back->next;
            otherTemp = otherTemp->next;
        }
    }
    return *this;
}

bool Queue::isEmpty() const
{
    return front == NULL; // or back == NULL
}

ElementType Queue::getFront() const
{
    assert(front != NULL);
    return front->data;
}

void Queue::enqueue(const ElementType &e)
{
    // Special case: list is empty
    if (front == NULL)
    {
        // both point to the same node
        back = new Node(e);
        front = back;
    }
    else
    {
        back->next = new Node(e);
        back = back->next;
    }
}

bool Queue::dequeue()
{
    // first case: list is empty
    if (front == NULL)
    {
        return false;
    }

    // Second case: only one element in the list.
    // Delete and set front and back to NULL
    if (front == back) // one element
    {
        delete front;
        front = NULL;
        back = NULL;
    }
    // Third case: many elements in the list.
    else
    {
        // delete front and set front to next node
        NodePtr temp = front;
        front = front->next;
        delete temp;
    }
    return true;
}

void Queue::display(std::ostream &out) const
{
    if (front == NULL)
    {
        out << "Queue is empty\n";
    }
    else
    {
        NodePtr temp = front;
        while (temp != NULL)
        {
            out << temp->data;
            if (temp->next != NULL)
            {
                out << " , ";
            }
            temp = temp->next;
        }
        out << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Queue &q)
{
    q.display(out);
    return out;
}
