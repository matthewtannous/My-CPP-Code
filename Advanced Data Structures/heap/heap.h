/*
Max heap implemention

NOTE: using template ==> one file for declaration and implementation
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;

template <typename ElementType> class Heap
{
public:
    Heap(int capacity = 10);
    Heap(const Heap &h);

    Heap &operator=(const Heap &other);
    ~Heap();

    bool isEmpty() const;
    ElementType getLargest() const;

    void insert(ElementType e);
    void remove();

    void print(ostream &out) const; // For testing
    void printTree(ostream &out) const;

private:
    ElementType *arr;
    int size, capacity;

    void printOneLevel(int numRows, int level, int beginIndex,
                       int endIndex) const;
};

// Implementations

// Constructor
template <typename ElementType>
Heap<ElementType>::Heap(int capacity) : capacity(capacity), size(0)
{
    arr = new ElementType[capacity];
}

// Copy-constructor
template <typename ElementType>
Heap<ElementType>::Heap(const Heap &h) : capacity(h.capacity), size(h.size)
{
    arr = new ElementType[capacity];
    for (int i = 0; i < size; i++)
        arr[i] = h.arr[i];
}

// Copy-constructor
template <typename ElementType>
Heap<ElementType> &Heap<ElementType>::operator=(const Heap<ElementType> &other)
{
    if (this != &other)
    {
        delete[] arr;
        // if (other.capacity > capacity)
        // {
        //     // expand array
        //     ElementType *temp = new ElementType[other.capacity];
        //     delete[] arr;
        //     arr = temp;
        // }

        capacity = other.capacity;
        size = other.size;
        arr = new ElementType[capacity];

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }
    return *this;
}

// Destructor
template <typename ElementType> Heap<ElementType>::~Heap() { delete[] arr; }

template <typename ElementType> bool Heap<ElementType>::isEmpty() const
{
    return size == 0;
}

template <typename ElementType>
ElementType Heap<ElementType>::getLargest() const
{
    return arr[0];
}

template <typename ElementType> void Heap<ElementType>::insert(ElementType e)
{
    // insert at size
    if (size == capacity) // expand array
    {
        capacity *= 2;
        ElementType *temp = new ElementType[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

    arr[size] = e;
    ElementType temp;

    int parent;

    for (int child = size++; child > 0; child = parent)
    {
        parent = (child - 1) / 2;

        if (arr[child] > arr[parent])
        {
            temp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = temp;
        }
        else
            break;
    }
}

// Remove largest
template <typename ElementType> void Heap<ElementType>::remove()
{
    if (size == 0)
    {
        cerr << "EMPTY\n";
        return;
    }

    // Remove largest
    arr[0] = arr[--size];

    // Place arr[0] in correct position
    // children are at (parent * 2 + 1) and (parent * 2 + 2)

    ElementType temp;
    // start from left child of root
    for (int parent = 0, child = 1; child < size;)
    {
        // find largest of 2 children
        if (child + 1 < size && arr[child] < arr[child + 1])
        {
            child++;
        }
        // swap parent with largest of 2 children
        if (arr[child] > arr[parent])
        {
            temp = arr[child];
            arr[child] = arr[parent];
            arr[parent] = temp;
        }
        else
        {
            return;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}

// Print
template <typename ElementType>
void Heap<ElementType>::print(ostream &out) const
{
    out << endl << "Array of heap: ";
    for (int i = 0; i < size; i++)
    {
        out << arr[i] << " ";
    }
    out << endl;
}

// Print as a Tree
template <typename ElementType>
void Heap<ElementType>::printTree(ostream &out) const
{
    if (size == 0)
    {
        out << "EMPTY\n";
        return;
    }

    int beginIndex = 0, // index of first node on some level
        endIndex = 0,   // index of last node on this level
        rowLength,      // length of current row
        numLevels = int(ceil(log(float(size)) / log(2.0))); // Number of levels
    if (numLevels == 0)
    {
        out << arr[0];
        return;
    }
    for (int level = 0; level < numLevels; level++)
    {
        printOneLevel(numLevels, level, beginIndex, endIndex);
        rowLength = endIndex - beginIndex + 1;
        beginIndex = endIndex + 1;
        endIndex = min(endIndex + 2 * rowLength, size - 1);
    }
}
template <typename ElementType>
void Heap<ElementType>::printOneLevel(int numRows, int level, int beginIndex,
                                      int endIndex) const
{
    int skip = int(pow(2.0, numRows - level) - 1); // space between items in row

    for (int i = beginIndex; i <= endIndex; i++)
    {
        cout << setw(skip) << " ";
        cout << setw(2) << arr[i];
        cout << setw(skip) << " ";
    }
    cout << "\n\n";
}

template <typename ElementType>
ostream &operator<<(ostream &out, const Heap<ElementType> &heap)
{
    heap.print(out);
    out << "Tree:" << endl;

    heap.printTree(out);
    return out;
}