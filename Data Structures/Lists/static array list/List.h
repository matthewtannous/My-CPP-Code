#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int ElementType; // so we can easily change data type list contains
const int CAPACITY = 32; // can be any number

class List
{
public:
    List();
    List(const List &); // copy constructor

    // List info
    // int getSize() const;
    // bool isEmpty() const;
    // bool isFull() const;

    inline int getSize() const { return size; }
    inline bool isEmpty() const { return size == 0; }
    inline bool isFull() const { return size == CAPACITY; }

    // change list data
    bool insertAtEnd(const ElementType &e);
    bool insertAtPos(const ElementType &e, int pos);
    bool deleteAtEnd();
    bool deleteAtPos(int pos);
    bool modify(int pos, const ElementType &e);
    // bool modify(const ElementType& oldVal, const ElementType& newVal);

    int search(const ElementType &e) const;
    void display(std::ostream&) const;

    // extra (from previous midterm)
    bool isSorted();

private:
    ElementType array[CAPACITY];
    int size;
};

std::ostream &operator<<(std::ostream &, const List &);

#endif
