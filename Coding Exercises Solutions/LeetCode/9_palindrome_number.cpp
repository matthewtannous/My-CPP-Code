#include <iostream>
#include <vector>

using namespace std;

// Inefficient solution - convert to string
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    string s = to_string(x);

    for (int l = 0, r = s.size() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return false;
    return true;
}

// Inefficient solution - build reverse number and compare with original , or
// create vector with digits
bool isPalindrome2(int x)
{
    if (x < 0)
        return false;

    // // Build the reverse number and check if equal
    // long reverse = 0, copy = x;
    // while (copy != 0)
    // {
    //     reverse = (10 * reverse) + (copy % 10);
    //     copy /= 10;
    // }

    vector<int> v;
    while (x != 0)
    {
        v.push_back(x % 10);
        x /= 10;
    }

    for (int l = 0, r = v.size() - 1; l < r; l++, r--)
        if (v[l] != v[r])
            return false;

    return true;
}

// Best solution - only reverse half the number
bool isPalindrome3(int x)
{
    if (x == 0)
        return true;
    if (x < 0 || x % 10 == 0)
        return false;

    // Build the reverse of half the number and check
    int reverse = 0;
    while (x > reverse)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return x == reverse || x == reverse / 10;
}
