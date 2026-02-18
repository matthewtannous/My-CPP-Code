#include <iostream>
#include <vector>

using namespace std;

int birthdayCakeCandles(vector<int> candles)
{
    int number = 0, maxHeight = candles[0];
    for (int n : candles)
    {
        if (n == maxHeight)
            number++;
        else if (n > maxHeight)
        {
            number = 1;
            maxHeight = n;
        }
    }
    return number;
}