#include <iostream>
#include <regex>

using namespace std;

int minimumNumber(int n, string password);

int main()
{
    string password = "AUzs-nV";
    int n = (int)password.length();

    // if (regex_search(password, regex("[0-9]")))
    // {
    //     cout << "MATCH" << endl;
    // }

    // string s = "softwareTesting";
    // if (regex_match(s, regex("(soft)(.*)")))
    // {
    //     cout << "string:literal => matched\n";
    // }

    cout << minimumNumber(n, password) << endl
         << endl;
}

int minimumNumber(int n, string password)
{
    // Return the minimum number of characters to make the password strong
    int count = 0;
    // bool digit = false, lower = false, upper = false, special = false;
    if (!regex_search(password, regex("[0-9]")))
    {
        cout << "No digit.";
        count++;
    }
    if (!regex_search(password, regex("[a-z]")))
    {
        cout << "No lower.";
        count++;
    }
    if (!regex_search(password, regex("[A-Z]")))
    {
        cout << "No upper.";
        count++;
    }
    if (!regex_search(password, regex("[!-+\\-]")))
    {
        cout << "No special.";
        count++;
    }

    if (count + n >= 6)
        return count;

    return 6 - n;
}
