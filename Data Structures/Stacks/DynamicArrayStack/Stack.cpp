#include <iostream>
#include <cassert>
#include "Stack.h"

Stack::Stack(int capacity)
{
    assert(capacity > 0);
    this->capacity = capacity;
    myTop = -1;
    myArray = new (std::nothrow) ElementType[capacity];
    if (myArray == NULL)
    {
        exit(1);
    }
}

Stack::Stack(const Stack &other)
{
    capacity = other.capacity;
    myTop = other.myTop;
    myArray = new ElementType[capacity];
    for (int i = 0; i <= myTop; i++)
    {
        myArray[i] = other.myArray[i];
    }
}

Stack::~Stack()
{
    delete[] myArray;
}

bool Stack::isEmpty() const
{
    return myTop == -1;
}

ElementType Stack::top() const
{
    assert(myTop > -1);
    return myArray[myTop];
}

void Stack::push(const ElementType &e)
{
    // Check if array is full
    if (myTop == capacity - 1)
    {
        // Allocate bigger array
        ElementType *newArray = new ElementType[capacity * 2];
        for (int i = 0; i < capacity; i++)
        {
            newArray[i] = myArray[i];
        }
        capacity *= 2;
        delete[] myArray;
        myArray = newArray;
    }

    // Push element
    myArray[++myTop] = e;
}

bool Stack::pop()
{
    if (myTop == -1)
    {
        std::cerr << "Stack is empty\n";
        return false;
    }
    myTop--;
    return true;
}

const Stack &Stack::operator=(const Stack &other)
{
    if (this != &other) // self-assignement
    {
        if (capacity != other.capacity) // other.myTop + 1 is the size
        {
            // Not enough space
            delete[] myArray;

            capacity = other.capacity;
            myArray = new ElementType[capacity];
        }
        myTop = other.myTop;

        for (int i = 0; i <= myTop; i++)
        {
            myArray[i] = other.myArray[i];
        }
    }
    return *this;
}

void Stack::display(std::ostream &out) const
{
    out << "Capacity: " << capacity;
    if (myTop == -1)
    {
        out << " - Stack is empty\n";
        return;
    }

    out << " - myTop: " << myTop << " - Elements:\n";
    for (int i = myTop; i >= 0; i--)
    {
        out << myArray[i];
        if (i != 0)
        {
            out << ", ";
        }
    }
    out << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Stack stack)
{
    stack.display(out);
    return out;
}
