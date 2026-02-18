#include <iostream>
#include "Queue.h"
#include <cassert>

Queue::Queue() : front(0), back(-1) {}

bool Queue::isEmpty() const
{
    return back == -1;
}

bool Queue::isFull() const
{
    return ((back + 1) % CAPACITY == front) && (back != -1);
}

ElementType Queue::getFront() const
{
    assert(back != -1);
    return array[front];
}

bool Queue::enqueue(const ElementType &e)
{
    if (((back + 1) % CAPACITY == front) && (back != -1)) // full
    {
        std::cerr << "Queue is full\n";
        return false;
    }

    back = (back + 1) % CAPACITY;
    array[back] = e;
    return true;
}

bool Queue::dequeue()
{
    // Case 1: empty
    if (back == -1)
    {
        std::cerr << "Queue is empty\n";
        return false;
    }

    // Case 2: One element in queue
    if (front == back)
    {
        front = 0;
        back = -1;
    }
    else
    {
        front = (front + 1) % CAPACITY;
    }
    return true;
}

void Queue::display(std::ostream &out) const
{
    if (back == -1)
    {
        out << "Queue is empty\n";
    }
    else
    {
        // Queue is everything from front to back (inclusive)
        for (int i = front; i != back; i = (i + 1) % CAPACITY)
        {
            out << array[i] << " , ";
        }

        out << array[back] << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Queue &q)
{
    q.display(out);
    return out;
}
