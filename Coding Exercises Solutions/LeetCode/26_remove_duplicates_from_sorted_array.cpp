#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int unique = 0, trav = 0;
    while (trav < nums.size())
    {
        nums[unique] = nums[trav];

        while (trav < nums.size() && nums[trav] == nums[unique])
            trav++;

        unique++;
    }

    return unique;
}
