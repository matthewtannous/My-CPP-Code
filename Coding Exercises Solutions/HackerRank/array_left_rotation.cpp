#include <bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    // first d elements will be removed, so we must save them in an array
    int values[d];
    for (int i = 0; i < d; i++)
        values[i] = arr[i];

    // Rotate array
    for (int i = 0; i < arr.size() - d; i++)
        arr[i] = arr[i + d];

    // Replace last elements of arr with saved values
    for (int i = 0; i < d; i++)
        arr[arr.size() - d + i] = values[i];

    return arr;
}