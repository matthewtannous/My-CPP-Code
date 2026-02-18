#include <iostream>
#include "Queue.h"
#include <cassert>

Queue::Queue(int capacity) : front(0), back(-1), myCapacity(capacity)
{
    array = new ElementType[myCapacity];
}

Queue::Queue(const Queue &other) : front(other.front), back(other.back),
                                   myCapacity(other.myCapacity)

{
    array = new ElementType[myCapacity];
    if (back != -1)
    {
        for (int i = front; i != back; i = (i + 1) % myCapacity)
        {
            array[i] = other.array[i];
        }
        array[back] = other.array[back];
    }
}

Queue::~Queue()
{
    delete[] array;
}

Queue &Queue::operator=(const Queue &other)
{
    if (this != &other)
    {
        delete[] array;

        front = other.front;
        back = other.back;
        myCapacity = other.myCapacity;

        array = new ElementType[myCapacity];
        if (back != -1)
        {
            for (int i = front; i != back; i = (i + 1) % myCapacity)
            {
                array[i] = other.array[i];
            }
            array[back] = other.array[back];
        }
    }
    return *this;
}

bool Queue::isEmpty() const
{
    return back == -1;
}

// bool Queue::isFull() const
// {
//     return ((back + 1) % myCapacity == front) && (back != -1);
// }

ElementType Queue::getFront() const
{
    assert(back != -1);
    return array[front];
}

bool Queue::enqueue(const ElementType &e)
{
    if (((back + 1) % myCapacity == front) && (back != -1)) // full
    {
        // expand array
        ElementType *newArray = new ElementType[myCapacity * 2];
        for (int i = 0; i < myCapacity; i++)
        {
            newArray[i] = array[(front + i) % myCapacity];
        }
        back = myCapacity - 1; // number of elements is myCapacity, we insert AT myCapacity, therefore back = myCapacity - 1  (insert after back)
        front = 0;
        delete[] array;
        array = newArray;
        myCapacity *= 2;
    }

    back = (back + 1) % myCapacity;
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
        front = (front + 1) % myCapacity;
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
        for (int i = front; i != back; i = (i + 1) % myCapacity)
        {
            out << array[i] << " , ";
        }
        out << array[back] << std::endl;

        // or get size,    for (int i = 0; i < size; i = (i + 1) % myCapacity)
    }
}

std::ostream &operator<<(std::ostream &out, const Queue &q)
{
    q.display(out);
    return out;
}
