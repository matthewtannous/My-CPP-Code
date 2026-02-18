#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> n;
    int q;
    vector<int>::iterator low;

    for (int i = 0; i < n; i++)
    {
        cin >> q;
        low = lower_bound(v.begin(), v.end(), q);

        // cout << *low;
        if (v[low - v.begin()] == q)
            cout << "Yes " << (low - v.begin() + 1);
        else
            cout << "No " << (low - v.begin() + 1);

        cout << "\n";
    }
    return 0;
}
