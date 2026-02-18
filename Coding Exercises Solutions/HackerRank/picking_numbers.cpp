#include <iostream>
#include <vector>

using namespace std;

int pickingNumbers(vector<int> a)
{
    int arr[101] = {0};
    for (int n : a)
        arr[n]++;

    int max = -1;
    for (int i = 0; i < 101; i++)
    {
        if (arr[i] + arr[i + 1] > max)
            max = arr[i] + arr[i + 1];
    }
    return max;
}