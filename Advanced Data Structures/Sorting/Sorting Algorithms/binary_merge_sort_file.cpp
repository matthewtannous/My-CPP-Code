/*
Binary Merge Sort (not natural)
Split is not completely correct

NOTE: Binary Merge Sort only works when there are 2^n elements
(file contains 2, 4, 8, 16... elements)

Data in file1.txt  to test:
5 1 8 3 6 2 4 7
*/

#include <fstream>
#include <iostream>

using namespace std;

typedef int ElementType;

const string dataFile = "file1.txt";
const string outputFile1 = "file2.txt";
const string outputFile2 = "file3.txt";

void split()
{
    // read from f1
    ifstream f1;
    f1.open(dataFile);
    // Put values in f2 and f3
    ofstream f2(outputFile1.data());
    ofstream f3(outputFile2.data());

    ElementType value;
    int i = 0;
    while (f1 >> value)
    {
        if (i++ % 2 == 0)
            f2 << value << " ";
        else
            f3 << value << " ";
    }

    f1.close();
    f2.close();
    f3.close();
}

// Same for every variation of split (Binary, Natural)
void merge()
{
    // Put values in f1
    ofstream f1(dataFile);
    // Read from f2 and f3
    ifstream f2, f3;
    f2.open(outputFile1);
    f3.open(outputFile2);

    ElementType data2, data3;

    f2 >> data2;
    f3 >> data3;

    while (!f2.eof() && !f3.eof())
    {
        if (data2 < data3)
        {
            f1 << data2 << " ";
            f2 >> data2;
        }
        else
        {
            f1 << data3 << " ";
            f3 >> data3;
        }
    }

    while (!f2.eof())
    {
        f1 << data2 << " ";
        f2 >> data2;
    }

    while (!f3.eof())
    {
        f1 << data3 << " ";
        f3 >> data3;
    }

    f1.close();
    f2.close();
    f3.close();
}

void mergeSort()
{
    for (int i = 0; i < 6; i++) // should be log of size
    {
        split();
        merge();
    }
}
void run() { mergeSort(); }

int main()
{
    cout << "\n";
    run();
    cout << "\n\n";
}
