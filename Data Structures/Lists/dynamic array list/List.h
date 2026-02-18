#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int ElementType;

class List
{
public:
    // Constructors
    // List(); // Default
    List(int startCapacity = 32);
    List(const List &other); // copy-constructor

    // Destructor
    ~List();

    // List info
    int getSize() const;
    bool isEmpty() const;

    // change list data
    // Add elements
    void insertAtEnd(const ElementType &e);
    bool insertAtPos(const ElementType &e, int pos);

    // Remove elements
    bool deleteAtEnd();
    bool deleteAtPos(int pos);

    // Modify elements in place
    bool modify(int pos, const ElementType &e);
    // bool modify(const ElementType &oldVal, const ElementType &newVal);

    // Other
    int search(const ElementType &e) const;
    void display(std::ostream &) const;

    // Override operators
    /**
     * operator= puts the values of the right into the left and returns the left
     */
    List &operator=(List &right); // return this

public: // SHOULD BE PRIVATE
    // Utility methods
    // inline bool isFull() { return size == capacity; }
    void expandArray();              // if array is full
    void setList(int startCapacity); // Initialize list

    // Data fields
    int size;     // number of elements in the array
    int capacity; // array size
    ElementType *array;
};

std::ostream &operator<<(std::ostream &out, const List &list);

#endif // LIST_H
