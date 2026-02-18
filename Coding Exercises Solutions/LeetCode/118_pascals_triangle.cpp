#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> result(numRows);
    for (int i = 0; i < numRows; i++)
    {
        vector<int> temp(i + 1);
        for (int j = 0; j <= i; j++)
        {
            // on borders, 1
            if (j == 0 || j == i)
                temp[j] = 1;
            // in middle, sum of upper row's i and i-1
            else
            {
                temp[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        result[i] = temp;
    }

    return result;
}