#include <iostream>
#include <vector>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3)
{

    // The first element is the top cylinder of the stack ==> h1[0] is the top
    // Get initial total heights of all vectors
    int s1 = 0, s2 = 0, s3 = 0, index1 = 0, index2 = 0, index3 = 0;

    for (int i : h1)
        s1 += i;

    for (int i : h2)
        s2 += i;

    for (int i : h3)
        s3 += i;

    // std::cout << "Initial heights: " << s1 << " " << s2 << " " << s3 << "\n";

    // keep removing the top element from highest array until all heights are
    // equal
    while (s1 != s2 || s1 != s3)
    {
        // Get max and remove top element (s[0])
        if (s1 > s2 || s1 > s3)
        {
            s1 -= h1[index1++];
            // std::cout << "Removed " << h1[index1] << " from h1";
            // index1++;
            // std::cout << "\nh1 height: " << s1 << "\n";
        }

        if (s2 > s1 || s2 > s3)
        {
            s2 -= h2[index2++];
            // std::cout << "Removed " << h2[index2] << " from h2";
            // index2++;
            // std::cout << "\nh2 height: " << s2 << "\n";
        }

        if (s3 > s1 || s3 > s2)
        {
            s3 -= h3[index3++];
            // std::cout << "Removed " << h3[index3] << " from h3";
            // index3++;
            // std::cout << "\nh3 height: " << s3 << "\n";
        }

        // Not needed as all sizes will eventually become zero
        if (index1 == h1.size() || index2 == h2.size() || index3 == h3.size())
        {
            return 0;
        }
    }

    return s1; // s1 == s2 == s3
}

int main()
{
    vector<int> v1 = {3, 2, 1, 1, 1};
    vector<int> v2 = {4, 3, 2};
    vector<int> v3 = {1, 1, 4, 1};

    int result = equalStacks(v1, v2, v3);

    cout << endl << "Result: " << result << endl;
}
