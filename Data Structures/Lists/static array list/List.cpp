#include <iostream> // std namespace
#include <cassert>  // global namespace (not std)
#include "List.h"

// Constructors
// List::List() {
//     size = 0;
// }
List::List() : size(0) {};

List::List(const List &other)
{
    size = other.size;
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}

// List info

// DOES NOT WORK with inline because definition of inline function needs to be in every file that uses it
// int List::getSize() const { return size; }
// bool List::isEmpty() const { return size == 0; }
// bool List::isFull() const { return size == CAPACITY; }

// change list data
/*  insertAtEnd using void
void List::insertAtEnd(const ElementType &e)
{
    assert(!isFull()); // check if there is enough space
    array[size++] = e;

}
*/

bool List::insertAtEnd(const ElementType &e)
{
    if (isFull())
    {
        return false;
    }
    array[size++] = e;
    return true;
}

bool List::insertAtPos(const ElementType &e, int pos)
{
    assert(!isFull());
    // if (isFull())
    // {
    //     std::cerr << "FULL";
    //     exit(1);
    // }
    if (pos < 0 || pos > size)
    {
        std::cerr << "Invalid position for insertion.\n";
        return false;
    }
    // valid position
    for (int i = size; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    array[pos] = e;
    size++;
    return true;
}

bool List::deleteAtEnd()
{
    if (isEmpty())
    {
        return false;
    }
    --size;
    return true;
}

bool List::deleteAtPos(int pos)
{
    assert(!isEmpty());
    if (pos < 0 || pos >= size)
    {
        std::cerr << "Invalid Position for deletion.\n";
        return false;
    }
    --size;
    for (int i = pos; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    return true;
}

bool List::modify(int pos, const ElementType &e)
{
    assert(!isEmpty());
    if (pos < 0 || pos >= size)
    {
        std::cerr << "Invalid Position for modification.\n";
        return false;
    }
    array[pos] = e;
    return true;
}

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
    if (isEmpty())
    {
        out << "List is empty.";
    }
    else
    {
        out << "List size: " << size << ", Elements: ";
        for (int i = 0; i < size; i++)
        {
            out << array[i];
            if (i < size - 1)
            {
                out << ", ";
            }
        }
    }
    out << std::endl;
}

std::ostream &operator<<(std::ostream &out, const List &list)
{
    list.display(out);
    return out;
}

// extra (from previous midterm)
bool List::isSorted()
{
    if (size == 0)
        return false;
    if (size == 1) // one element --> always sorted
        return true;

    for (int i = 0; i < size; i++)
    {
        if (array[i + 1] < array[i])
            return false;
    }
    return true;
}
