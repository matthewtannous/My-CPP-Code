#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int n = 0; // number of elements EQUAL to val

    /*
    For each element:
        if equal to val, replace with last and do not move array index
        else move forward
    */
    for (int i = 0; i < nums.size() - n;)
    {
        if (nums[i] == val)
        { // remove (replace with last value that we know is NOT EQUAL to n)
            nums[i] = nums[nums.size() - 1 - n++];
            // n++;
        }
        else
        {
            i++;
        }
    }

    // std::cout << "\nn: " << nums.size() - n;
    return nums.size() - n;
}

int main()
{
    vector<int> v = {3, 2, 2, 3};
    cout << removeElement(v, 2) << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
}

// OTHER SOLUTION FROM LEETCODE
int removeElement2(vector<int> &nums, int val)
{
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}