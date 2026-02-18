#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        switch (c)
        {
        case '[':
        case '{':
        case '(':
            st.push(c);
            break;

        case ']':
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
            break;

        case '}':
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                return false;
            break;

        case ')':
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
            break;
        }
    }
    return st.empty();
}