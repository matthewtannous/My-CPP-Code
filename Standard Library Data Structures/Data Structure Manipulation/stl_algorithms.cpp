/*
Functions for manipulating data structures
Most of them use iterators
*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::string;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v)
{
    cout << "\n";
    for (T i : v)
        out << i << " ";
    cout << "\n";
    return out;
}


void test1();
void test2();

int main()
{
    cout << std::boolalpha << "\n";

    test1();

    cout << "\n\n";
}

void test1()
{
    // Sorting - sort() takes 2 iterators and returns void

    std::vector<string> vec{"MAT", "mat", "hello", "bye"};
    cout << vec;

    // Sort in increasing order
    std::sort(vec.begin(), vec.end());
    cout << vec;

    // Sort in decreasing order
    std::sort(vec.rbegin(), vec.rend());
    cout << vec;

    // Sort part of a structure
    std::vector<int> nums {1,2,31,1,-132,3,1, 3,1234123,-987};
    cout << nums;

    std::sort(nums.begin(), nums.begin() + 5);
    cout << nums;


    // Searching - find() takes 2 iterators (start and end) and a value
    std::vector<int>::iterator iter = std::find(nums.begin(),
                        nums.end(), 1);
    
    if (iter == nums.end())
        cout << "Not found";
    else
        cout << "Found";

    // Find smallest - min_element takes 2 iterators (start and end)
    auto iter2 = std::min_element(nums.begin(), nums.end());
    cout << "\n\nSmallest: " << *iter2 << "\n";

    // Find largest - min_element takes 2 iterators( start and end)
    auto iter3 = std::max_element(nums.begin(), nums.end());
    cout << "\n\nLargest: " << *iter3 << "\n\n";


    // Copying - copy() takes 3 iterators: start of original, end of original, start of new
    std::vector<int> copied(nums.size());

    cout << nums << copied;
    std::copy(nums.begin(), nums.end(), copied.begin());
    cout << copied;

    // Filling - fill() takes 2 iterators (start and end) and a value to fill with
    std::fill(copied.begin(), copied.end() - 2, 42);
    cout << copied;
}


void test2()
{

}