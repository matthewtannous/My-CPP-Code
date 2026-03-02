/*
Binary Merge Sort (not natural)
split is not completely correct

NOTE: Binary Merge Sort only works when there are 2^n elements
(file contains 2, 4, 8, 16... elements)

Data in file1.txt  to test:
5 1 8 3 6 2 4 7


PSEUDOCODE for Natural Merge Sort:

Split algorithm:
1. Open F for input, F1 and F2 for output
2. While the end of F has not been reached:
3.    Read value from F and write it in F1
4.    While the next value to be read in F is less than the last copied value
            and the eof for F has not been reached:
5.        Read value from F and write it in F1

6.    Read value from F and write it in F2
7.    While the next value to be read in F is less than the last copied value
            and the eof for F has not been reached:
8.        Read value from F and write it in F2

Merge algorithm:
1. Open F for output, F1 and F2 for input
2. While neither the end of F1 nor the end of F2 has been reached:
3.    Read one element e1 from F1 and one element e2 from F2
4.    If e1 is less than e2:
5.        Copy e1 into F
6.        Read a new element e1 from f1
7.    Else:
8.        Copy e2 into F
9.        Read a new element e2 from f2
// After this, one (or both) of the file are empty (at the end)
// Copy the rest
(10. Copy the remaining values of the non-empty file into F (Same method))
10. While the end of F1 has not been reached:
11.   Read the next value of F1 and write it in F

12. While the end of F2 has not been reached:
13.   Read the next value of F2 and write it in F
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
