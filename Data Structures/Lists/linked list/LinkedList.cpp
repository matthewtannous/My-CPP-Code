/*
calling delete on a dynamic object containing other dynamic objects will
recursively delete all dyncamic objects inside of it

tempPtr is "outside" the class. Changing it does not do anything.
you have to change what it is pointing to (using ->)
*/

#include <iostream>
#include <cassert>
#include "LinkedList.h"

using std::nothrow, std::cerr;

// LinkedList::LinkedList()
// {
//     size = 0;
//     first = NULL;
// }

// Constructors

LinkedList::Node::Node(const ElementType &data) : data(data), next(NULL) {}

LinkedList::LinkedList() : size(0), first(NULL) {}

LinkedList::LinkedList(const LinkedList &other)
{
    size = other.size;

    // Traverse other list, and copy each value into this list
    // NOTE: manually copy first element because "first" must be set

    if (other.first == NULL)
    {
        first = NULL;
    }
    else
    {
        first = new (nothrow) Node(other.first->data);
        NodePtr tempPtr = first;

        NodePtr otherTrav = other.first->next;

        while (otherTrav != NULL) // start from second element
        {
            // std::cout << "Entered ";
            tempPtr->next = new (nothrow) Node(otherTrav->data);
            if (tempPtr == NULL)
            {
                exit(-1);
            }

            tempPtr = tempPtr->next;
            otherTrav = otherTrav->next;
        }
    }
}

// Destructor
LinkedList::~LinkedList()
{
    NodePtr temp = first;
    NodePtr other = NULL;
    while (temp != NULL)
    {
        other = temp->next;
        delete temp;
        temp = other;
    }
}

// operator=
LinkedList &LinkedList::operator=(const LinkedList &rightHandSide)
{
    // delete old list in this
    NodePtr temp = first;
    NodePtr other = NULL;
    while (temp != NULL)
    {
        other = temp->next;
        delete temp;
        temp = other;
    }

    size = rightHandSide.size;

    if (rightHandSide.first == NULL)
    {
        first = NULL;
    }
    else
    {
        first = new (nothrow) Node(rightHandSide.first->data);
        NodePtr tempPtr = first;

        NodePtr otherTrav = rightHandSide.first->next;

        while (otherTrav != NULL) // start from second element
        {
            // std::cout << "Entered ";
            tempPtr->next = new (nothrow) Node(otherTrav->data);
            if (tempPtr == NULL)
            {
                exit(-1);
            }

            tempPtr = tempPtr->next;
            otherTrav = otherTrav->next;
        }
    }
    return *this;
}

// List info
int LinkedList::getSize() const
{
    // return size;
    // OR
    int s = 0;
    NodePtr temp = first;
    while (temp != NULL)
    {
        s++;
        temp = temp->next;
    }
    return s;
}

bool LinkedList::isEmpty() const
{
    return size == 0;
    // OR
    // return first == NULL;
}

// Add elements
void LinkedList::insertAtEnd(const ElementType &e)
{
    if (first == NULL)
    {
        first = new Node(e);
        size++;
        return;
    }
    // Traverse to the end of the list
    NodePtr tempPtr = first;
    while (tempPtr->next != NULL) // cannot use tempPtr instead of tempPtr
    {
        tempPtr = tempPtr->next;
    }

    // End of the list --> tempPtr == NULL
    tempPtr->next = new Node(e);
    size++;
}

bool LinkedList::insertAtPos(const ElementType &e, int pos)
{
    // with size
    if (pos < 0 || pos > size)
    {
        std::cerr << "Invalid position for insert\n";
        return false;
    }

    if (pos == 0)
    {
        // if (first == NULL) NOT NEEDED
        // {
        //     first = new Node(e);
        // }
        // else

        NodePtr tempPtr = first;
        // change first
        first = new Node(e);
        first->next = tempPtr;
    }
    else
    {
        NodePtr tempPtr = first;
        for (int i = 0; i < pos - 1; i++)
        {
            tempPtr = tempPtr->next;
        }
        // insert after this value
        NodePtr newPtr = new Node(e);
        newPtr->next = tempPtr->next;
        tempPtr->next = newPtr;
    }
    size++;
    return true;
}

bool LinkedList::insertAfterElement(const ElementType &inserted,
                                    const ElementType &after)
{
    NodePtr tempPtr = first;
    while (tempPtr != NULL && tempPtr->data != after)
    {
        tempPtr = tempPtr->next;
    }
    if (tempPtr == NULL) // not found
    {
        std::cerr << "Element " << after << " does not exist\n";
        return false;
    }
    // we found the element, insert after tempPtr
    NodePtr newPtr = new Node(inserted);
    newPtr->next = tempPtr->next;
    tempPtr->next = newPtr;
    size++;
    return true;
}

/*
// Using 2 loops (bad)
bool LinkedList::insertBeforeElement(const ElementType &inserted,
                                     const ElementType &before)
{
    NodePtr tempPtr = first;
    while (tempPtr != NULL && tempPtr->data != before)
    {
        tempPtr = tempPtr->next;
    }
    if (tempPtr == NULL) // not found
    {
        std::cerr << "Element " << before << " does not exist\n";
        return false;
    }

    if (tempPtr == first)
    {
        // insert at start of list
        NodePtr newPtr = first;
        first = new Node(inserted);
        first->next = newPtr;
    }
    else
    {
        NodePtr otherPtr = first;
        while (otherPtr->next != tempPtr)
        {
            otherPtr = otherPtr->next;
        }
        // otherPtr points to node we have to insert after
        NodePtr newPtr = new Node(inserted);
        newPtr->next = otherPtr->next; // or tempPtr
        otherPtr->next = newPtr;
    }
    size++;
    return true;
}
*/

// Using 1 loop
bool LinkedList::insertBeforeElement(const ElementType &inserted,
                                     const ElementType &before)
{
    if (first == NULL) // empty list
    {
        std::cerr << "Cannot insert. List is empty\n";
        return false;
    }

    if (first->data == before) // insert at beginning of list
    {
        // Insert at beginning
        NodePtr tempPtr = first;
        first = new Node(inserted);
        first->next = tempPtr;
    }
    else
    {
        NodePtr tempPtr = first;
        // the loop should stop when the value tempPtr->next->data == before
        while (tempPtr->next != NULL && tempPtr->next->data != before)
        {
            tempPtr = tempPtr->next;
        }
        if (tempPtr->next == NULL)
        {
            std::cerr << "Cannot insert. Element " << before << " does not exist\n";
            return false;
        }

        // tempPtr points to node we must insert after
        NodePtr newPtr = new (nothrow) Node(inserted);
        if (newPtr == NULL)
        {
            exit(-1);
        }
        newPtr->next = tempPtr->next;
        tempPtr->next = newPtr;
    }
    size++;
    return true;
}

// Remove elements
bool LinkedList::deleteAtPos(int pos)
{
    if (pos < 0 || pos >= size)
    {
        cerr << "Invalid position for delete\n";
        return false;
    }
    if (pos == 0)
    {
        NodePtr tempPtr = first->next;
        delete first;
        first = tempPtr;
    }
    else
    {
        NodePtr tempPtr = first;
        for (int i = 0; i < pos - 1; i++)
        {
            tempPtr = tempPtr->next;
        }
        // delete node after tempPtr
        NodePtr newPtr = tempPtr->next->next;
        delete tempPtr->next;
        tempPtr->next = newPtr;
    }
    size--;
    return true;
}

bool LinkedList::deleteAfterElement(const ElementType &e)
{
    NodePtr tempPtr = first;
    while (tempPtr != NULL && tempPtr->data != e)
    {
        tempPtr = tempPtr->next;
    }
    if (tempPtr == NULL)
    {
        cerr << "Cannot delete " << e << " because it is not in the list\n";
        return false;
    }
    if (tempPtr->next == NULL)
    {
        cerr << "Cannot delete " << e << " because it is the last element in the list\n";
        return false;
    }
    // delete node at tempPtr->next
    NodePtr otherPtr = tempPtr->next->next;
    delete tempPtr->next;
    tempPtr->next = otherPtr;
    size--;
    return true;
}

bool LinkedList::deleteElement(const ElementType &e)
{
    if (first == NULL)
    {
        cerr << "LIST IS EMPTY\n";
        return false;
    }
    // special case: delete first element
    if (first->data == e)
    {
        NodePtr tempPtr = first->next;
        delete first;
        first = tempPtr;
    }
    else
    {
        NodePtr tempPtr = first;
        while (tempPtr->next != NULL && tempPtr->next->data != e)
        {
            tempPtr = tempPtr->next;
        }
        if (tempPtr->next == NULL)
        {
            cerr << "Element " << e << " does not exist\n";
            return false;
        }

        // delete node at tempPtr->next
        NodePtr otherPtr = tempPtr->next->next;
        delete tempPtr->next;
        tempPtr->next = otherPtr;
    }
    size--;
    return true;
}

bool LinkedList::deleteBeforeElement(const ElementType &e)
{
    // we have to be 2 positions before e.

    if (first == NULL || first->next == NULL) // Empty list
    {
        cerr << "List has one or zero elements\n";
        return false;
    }

    if (first->data == e) // nothing before element
    {
        cerr << "Element " << e << " is at the beginning. There is nothing before it\n";
        return false;
    }

    if (first->next->data == e) // delete first element
    {
        NodePtr otherPtr = first->next;
        delete first;
        first = otherPtr;
    }
    else
    {
        NodePtr tempPtr = first;
        while (tempPtr->next->next != NULL && tempPtr->next->next->data != e)
        {
            tempPtr = tempPtr->next;
        }
        if (tempPtr->next->next == NULL)
        {
            cerr << "Element " << e << " does not exist\n";
            return false;
        }

        // delete tempPtr->next
        NodePtr otherPtr = tempPtr->next->next;
        delete tempPtr->next;
        tempPtr->next = otherPtr;
    }
    size--;
    return true;
}
//
//
//

// display list
void LinkedList::display(std::ostream &out) const
{
    // out << "List size: " << size << std::endl;
    if (first == NULL)
    {
        out << "List is empty";
    }
    else
    {
        NodePtr tempPtr = first;
        while (tempPtr != NULL)
        {
            out << tempPtr->data << ", ";
            tempPtr = tempPtr->next;
        }
    }
    out << std::endl;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &list)
{
    list.display(out);
    return out;
}

// extra (book exercise 6_4_9)
LinkedList LinkedList::mergeSortedLists(const LinkedList &other)
{
    LinkedList result; // sorted LinkedList

    // pointers to 2 original lists
    NodePtr thisPtr = first;
    NodePtr otherPtr = other.first;

    // One of lists is empty, copy non-empty into result
    if (first == NULL && other.first != NULL)
    {
        // pointer to result list
        NodePtr resultPtr = result.first;
        // Copy other into result
        result.first = new Node(otherPtr->data);
        otherPtr = otherPtr->next;

        while (otherPtr != NULL)
        {
            resultPtr->next = new Node(otherPtr->data);
            resultPtr = resultPtr->next;
            otherPtr = otherPtr->next;
        }
    }
    else if (first != NULL && other.first == NULL)
    {
        // pointer to result list
        NodePtr resultPtr = result.first;
        // Copy this into result
        result.first = new Node(thisPtr->data);
        thisPtr = thisPtr->next;

        while (thisPtr != NULL)
        {
            resultPtr->next = new Node(thisPtr->data);
            resultPtr = resultPtr->next;
            thisPtr = thisPtr->next;
        }
    }

    // Both lists are not empty
    else
    {
        if (thisPtr->data < otherPtr->data)
        {
            result.first = new Node(thisPtr->data);
            thisPtr = thisPtr->next;
        }
        else
        {
            result.first = new Node(otherPtr->data);
            otherPtr = otherPtr->next;
        }
        // pointer to result list
        NodePtr resultPtr = result.first;

        // Until the end of one of the 2 lists is reached
        while (thisPtr != NULL && otherPtr != NULL)
        {
            if (thisPtr->data < otherPtr->data)
            {
                resultPtr->next = new Node(thisPtr->data);
                thisPtr = thisPtr->next;
            }
            else
            {
                resultPtr->next = new Node(otherPtr->data);
                otherPtr = otherPtr->next;
            }
            resultPtr = resultPtr->next;
        }

        // One list is empty (or both are empty)
        while (thisPtr != NULL)
        {
            resultPtr->next = new Node(thisPtr->data);
            thisPtr = thisPtr->next;
            resultPtr = resultPtr->next;
        }
        while (otherPtr != NULL)
        {
            resultPtr->next = new Node(otherPtr->data);
            otherPtr = otherPtr->next;
            resultPtr = resultPtr->next;
        }
    }

    return result;
}

void LinkedList::deleteNthNode(int n) // starting from 1
{
    assert(n > 0 && first != NULL);

    if (n == 1)
    {
        NodePtr temp = first;
        first = first->next;
        delete temp;
    }
    else
    {
        NodePtr temp = first;
        int count = 2; // start from after first

        while (temp->next != NULL && count < n)
        {
            temp = temp->next;
            count++;
        }
        // case 1: count != n (or count < n): temp->next became NULL before count reached n, list is too short
        if (count < n)
        {
            cerr << "List is too short\n";
            exit(1);
        }

        // case 2: count == n: delete element pointed to by temp->next
        NodePtr otherPtr = temp->next;
        temp->next = otherPtr->next;
        delete otherPtr;
    }
}

void LinkedList::reverse()
{

    // have 2 pointers run through the list.
    NodePtr current = first;
    NodePtr prev = NULL;
    NodePtr next;

    while (current != NULL)
    {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}
