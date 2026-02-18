#include <iostream>
#include "DoublyCircularLinkedList.h"

using namespace std;

DoublyCLL::DNode::DNode(ElementType data)
    : data(data), next(NULL), prev(NULL) {}

DoublyCLL::DoublyCLL() : first(NULL) {}

DoublyCLL::DoublyCLL(const DoublyCLL &other)
{
    if (other.first == NULL)
    {
        first = NULL;
    }
    else
    {
        first = new DNode(other.first->data);
        DNodePtr thisPtr = first;
        DNodePtr otherPtr = other.first->next;

        while (otherPtr != other.first)
        {
            thisPtr->next = new DNode(otherPtr->data);
            thisPtr->next->prev = thisPtr;
            thisPtr = thisPtr->next;

            otherPtr = otherPtr->next;
        }
        thisPtr->next = first;
        first->prev = thisPtr;
    }
}

DoublyCLL::~DoublyCLL()
{
    if (first != NULL)
    {
        // if one element, delete it
        if (first->next == first) // one element
        {
            delete first;
        }
        else // 2 or more elements
        {
            DNodePtr savedFirst = first;
            DNodePtr temp;

            // first = first->next;
            // delete temp;
            do
            {
                temp = first;
                first = first->next;
                delete temp;
            } while (first != savedFirst);
        }
    }
}

DoublyCLL &DoublyCLL::operator=(const DoublyCLL &other)
{
    if (this != &other)
    {
        // Destructor
        if (first != NULL)
        {
            // if one element, delete it
            if (first->next == first) // one element
            {
                delete first;
            }
            else // 2 or more elements
            {
                DNodePtr savedFirst = first;
                DNodePtr temp;

                do
                {
                    temp = first;
                    first = first->next;
                    delete temp;
                } while (first != savedFirst);
            }
        }

        // Copy-constructor
        if (other.first == NULL)
        {
            first = NULL;
        }
        else
        {
            first = new DNode(other.first->data);
            DNodePtr thisPtr = first;
            DNodePtr otherPtr = other.first->next;

            while (otherPtr != other.first)
            {
                thisPtr->next = new DNode(otherPtr->data);
                thisPtr->next->prev = thisPtr;
                thisPtr = thisPtr->next;

                otherPtr = otherPtr->next;
            }
            thisPtr->next = first;
            first->prev = thisPtr;
        }
    }
    return *this;
}

bool DoublyCLL::isEmpty() const
{
    return first == NULL;
}

int DoublyCLL::size() const
{
    if (first == NULL)
    {
        return 0;
    }

    int count = 0;
    DNodePtr temp = first;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != first);

    return count;
}

void DoublyCLL::insertAtBegin(const ElementType e)
{
    DNodePtr inserted = new DNode(e);

    if (first == NULL)
    {
        first = inserted;
        first->next = first;
        first->prev = first;
    }
    else
    {
        inserted->next = first;       // put inserted before first
        inserted->prev = first->prev; // put prev of inserted equal to original prev

        first->prev = inserted;
        first = inserted; // point first to new node

        first->prev->next = first; // point last node to new first node
    }
}

void DoublyCLL::insertAtEnd(const ElementType e)
{
    DNodePtr inserted = new DNode(e);

    if (first == NULL)
    {
        first = inserted;
        first->next = first;
        first->prev = first;
    }
    else
    {
        // last node is first->prev

        inserted->next = first;
        inserted->prev = first->prev;

        inserted->prev->next = inserted;
        first->prev = inserted;
    }
}

bool DoublyCLL::insertAfterElement(const ElementType &inserted,
                                   const ElementType &after)
{
    DNodePtr temp = first;
    do
    {
        if (temp->data == after)
        {
            DNodePtr newPtr = new DNode(inserted);
            newPtr->next = temp->next;
            newPtr->prev = temp;

            temp->next = newPtr;
            newPtr->next->prev = newPtr;

            return true;
        }
        temp = temp->next;
    } while (temp != first);
    return false;
}

bool DoublyCLL::insertBeforeElement(const ElementType &inserted,
                                    const ElementType &before)
{
    // first is a special case
    if (first->data == before)
    {
        DNodePtr newPtr = new DNode(inserted);

        newPtr->next = first;
        newPtr->prev = first->prev;

        first->prev = newPtr;
        first = newPtr;
        first->prev->next = first;
        return true;
    }

    DNodePtr temp = first->next; // checked first in special case
    do
    {
        if (temp->data == before)
        {
            DNodePtr newPtr = new DNode(inserted);
            // insert before temp
            newPtr->next = temp;
            newPtr->prev = temp->prev;

            newPtr->prev->next = newPtr;
            temp->prev = newPtr;

            return true;
        }
        temp = temp->next;
    } while (temp != first);

    return false;
}

bool DoublyCLL::deleteFromBegin()
{
    if (first == NULL) // empty list
    {
        return false;
    }

    if (first == first->next) // one element in the list
    {
        delete first;
        first = NULL;
        return true;
    }

    DNodePtr temp = first;

    first = first->next;

    first->prev = temp->prev;
    temp->prev->next = first;

    delete temp;
    return true;
}

bool DoublyCLL::deleteFromEnd()
{
    if (first == NULL)
    {
        return false;
    }

    if (first == first->next)
    {
        delete first;
        first = NULL;
        return true;
    }

    DNodePtr temp = first->prev; // last node
    first->prev = temp->prev;

    temp->prev->next = first;
    delete temp;
    return true;
}

bool DoublyCLL::deleteElement(const ElementType &e)
{
    if (first->data == e) // Delete first
    {
        if (first == first->next)
        {
            delete first;
            first = NULL;
        }
        else
        {
            DNodePtr temp = first;

            first = first->next;

            first->prev = temp->prev;
            temp->prev->next = first;

            delete temp;
        }

        return true;
    }

    DNodePtr temp = first;
    do
    {
        if (temp->data == e)
        {
            // delete temp

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;

            return true;
        }
        temp = temp->next;
    } while (temp != first);
    return false;
}


bool DoublyCLL::deleteAfterElement(const ElementType &e)
{
    DNodePtr temp = first;
    do
    {
        
        if (temp->data == e)
        {
            // delete temp->mext
            if (temp->next == first)
            {
                // delete first

            }
        }
        temp = temp->next;
    } while (temp != first);

    return false;
}

void DoublyCLL::displayList(ostream &out) const
{
    if (first == NULL)
    {
        out << "List is empty";
    }
    else
    {
        DNodePtr temp = first;
        do
        {
            out << temp->data << " ";
            temp = temp->next;
        } while (temp != first);

        // out << "data\t\tprev\t\tthis\t\tnext\n";
        // do
        // {
        //     out << temp->data << "\t\t" << temp->prev << "\t" << temp << "\t" << temp->next << endl;
        //     temp = temp->next;
        // } while (temp != first);
    }
    out << endl;
}

void DoublyCLL::displayReverse(ostream &out) const
{
    if (first == NULL)
    {
        out << "List is empty";
    }
    else
    {
        DNodePtr temp = first->prev;
        do
        {
            out << temp->data << " ";
            temp = temp->prev;
        } while (temp != first->prev);
    }
    out << endl;
}

ostream &operator<<(ostream &out, const DoublyCLL &list)
{
    list.displayList(out);
    return out;
}
