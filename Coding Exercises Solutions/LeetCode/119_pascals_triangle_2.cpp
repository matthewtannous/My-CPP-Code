#include <vector>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> result(rowIndex + 1, 1); // vector of 1s

    for (int i = 1; i < rowIndex; i++)
    {
    }
    return result;
}