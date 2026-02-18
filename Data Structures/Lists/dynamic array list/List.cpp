/*
An operator whose result is a new value (such as +, -, etc) must return
the new value by value, and an operator whose result is an existing value,
but modified (such as <<, >>, +=, -=, etc), should return a reference to the
modified value.

operator=  returns the left operand with modified values, so it's overloaded
            methdod should return by reference


Default values for functions should be specified in the header file
 */

#include <cassert>
#include <iostream>
#include "List.h"

#include <new> // for nothrow (was already available before including - iostream?)

using std::nothrow;

// Constructors
// List::List() // if we do not want to use optional parameters
// {
//     setList(32);
// }

// List::List(int maxSize) : size(0), capacity(maxSize)
// {
//     array = new (nothrow) ElementType[maxSize];
//     assert(array != NULL);
// }

List::List(int startCapacity)
{
    setList(startCapacity);
}

List::List(const List &other)
{
    // copy static members
    size = other.size;
    // capacity = other.capacity;

    // do not allocate too much memory if most the copied array is empty
    if (static_cast<double>(size) / other.capacity < 0.4)
    {
        capacity = other.capacity / 2;
    }
    else
    {
        capacity = other.capacity;
    }

    // copy dynamic array
    array = new (nothrow) ElementType[capacity];
    assert(array != NULL);

    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}

// Destructor
List::~List()
{
    delete[] array;
}

// Utility methods
void List::expandArray()
{
    capacity *= 2;
    // Create new array with data
    ElementType *newArray = new (nothrow) ElementType[capacity];
    if (newArray == NULL)
    {
        std::cerr << "NO MEMORY";
        exit(2);
    }
    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    // Delete old array
    delete[] array;

    // assign array data field to new array
    array = newArray;
}

void List::setList(int startCapacity)
{
    capacity = startCapacity;
    size = 0;
    array = new (std::nothrow) ElementType[capacity]; // no need to initialize elements
    if (array == NULL)                                // or use assert(array != NULL);
    {
        std::cerr << "NO MEMORY";
        exit(2);
    }
}

// List info
int List::getSize() const
{
    return size;
}
bool List::isEmpty() const
{
    return size == 0;
}

// Add elements
void List::insertAtEnd(const ElementType &e)
{
    // Check if array is full
    if (size == capacity)
        expandArray();

    array[size++] = e;
}

bool List::insertAtPos(const ElementType &e, int pos)
{
    // Check if array is full
    if (size == capacity)
        expandArray();

    // Check pos is valid
    if (pos < 0 || pos > size)
    {
        std::cerr << "ERROR: Invalid position for inserting\n";
        return false;
    }
    for (int i = size; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    array[pos] = e;
    size++;
    return true;
}

// Remove elements
bool List::deleteAtEnd()
{
    if (size == 0)
    {
        std::cerr << "ERROR: List is empty\n";
        return false;
    }
    size--;
    return true;
}

bool List::deleteAtPos(int pos)
{
    if (size == 0)
    {
        std::cerr << "ERROR: List is empty\n";
        return false;
    }
    if (pos < 0 || pos >= size)
    {
        std::cerr << "ERROR: Invalid position\n";
        return false;
    }

    for (int i = pos; i < size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    size--;
    return true;
}

// Modify elements in place
bool List::modify(int pos, const ElementType &e)
{
    assert(size > 0);

    if (pos < 0 || pos >= size)
    {
        std::cerr << "ERROR: Invalid position\n";
        return false;
    }
    array[pos] = e;
    return true;
}
/****** with int as ElementType, same parameters
bool List::modify(const ElementType &oldVal, const ElementType &newVal)
{
    // Can use search method
    for (int i = 0; i < size; i++)
    {
        if (array[i] == oldVal)
        {
            array[i] = newVal;
            return true;
        }
    }
    std::cerr << "ERROR: Could not find element " << oldVal << " in the list\n";
    return false;
}
******************************************************************************/
// Other
int List::search(const ElementType &e) const
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == e)
        {
            return i;
        }
    }
    return -1;
}

void List::display(std::ostream &out) const
{
    if (size == 0)
    {
        out << "List is empty\n";
    }
    else
    {
        out << "Size: " << size << ", Capacity: " << capacity << std::endl;
        for (int i = 0; i < size; i++)
        {
            out << array[i];
            if (i < size - 1)
            {
                out << ", ";
            }
        }
        out << std::endl;
    }
}

// Operators
std::ostream &operator<<(std::ostream &out, const List &list)
{
    list.display(out);
    return out;
}

List &List::operator=(List &right)
{
    // Check that it is not self-assignement
    if (this != &right)
    {
        // size = right.size;
        // // do not allocate too much memory if most the copied array is empty
        // if (static_cast<double>(size) / right.capacity < 0.4)
        // {
        //     capacity = right.capacity / 2;
        // }
        // else
        // {
        //     capacity = right.capacity;
        // }

        // // copy dynamic array
        // array = new ElementType[capacity];
        // for (int i = 0; i < size; i++)
        // {
        //     array[i] = right.array[i];
        // }

        if (capacity != right.capacity)
        {
            delete[] array;
            capacity = right.capacity;
            array = new (nothrow) ElementType[capacity];

            if (array == NULL)
            {
                std::cerr << "ERROR";
                exit(1);
            }
        }
        size = right.size;
        for (int i = 0; i < size; i++)
        {
            array[i] = right.array[i];
        }
    }
    // else left and right are the same
    return *this;
}
