#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> res;
    int n;
    char c;
    stringstream ss(str);
    while (ss >> n >> c)
    {
        res.push_back(n);
    }
    res.push_back(n);
    return res;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}