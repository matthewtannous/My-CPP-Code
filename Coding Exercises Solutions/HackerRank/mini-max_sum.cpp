#include <bits/stdc++.h>
using namespace std;

void miniMaxSum(vector<int> arr)
{
    // Find sum of all values and minimum and maximum value
    // minSum = sum - max     maxSum = sum - min

    int min = arr[0], max = arr[0];
    long sum = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
    }
    cout << sum - max << " " << sum - min;
}