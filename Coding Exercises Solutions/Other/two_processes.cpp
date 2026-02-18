/*
You are given

data vector contains 'size' for each process


You must find the smallest total time required for all processes in the vector
to finish


Example:

processorTime1 = 2
processorTime2 = 4

data = {1, 2, 3, 4, 5, 555}

test 1:
    processor 1 does tasks 1, 2 and 3 => total p1 time = 2 * (1 + 2 + 3) = 12
    processor 2 does tasks 4 and 5    => total p2 time = 4 * (4 + 5) = 36

test 2:
    processor 1 does tasks 4 and 5    => total p1 time = 2 * (4 + 5) = 18
    processor 2 does tasks 1, 2 and 3 => total p2 time = 4 * (1 + 2 + 3) = 24

test 3:
    processor 1 does tasks 1, 4 and 5 => total p1 time = 2 * (1 + 4 + 5) = 20
    processor 2 does tasks 2 and 3    => total p2 time = 4 * (2 + 3) = 20

20 is the answer


Basically, you must make the 2 total times as close to each other as possible
The times might not be equal, in this case return the largest
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int smallestSum(vector<int> data, int processorTime1, int processorTime2)
{
    sort(data.begin(), data.end());
    // my solution
    int total1 = 0, total2 = 0;

    for (int i = data.size() - 1; i >= 0; i--)
    {
        if (total1 > total2)
            total2 += data[i] * processorTime2;
        else
            total1 += data[i] * processorTime1;
    }

    return max(total1, total2);
}

void test()
{
    vector<int> data{1, 2, 3, 4, 5};
    int p1 = 2, p2 = 4;

    cout << smallestSum(data, p1, p2) << "";
}

int main()
{
    cout << "\n";
    test();
    cout << "\n\n";
}
