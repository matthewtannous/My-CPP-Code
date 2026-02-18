#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s)
{
    stack<char> myStack;
    for (char c : s)
    {
        switch (c)
        {
        case '[':
        case '{':
        case '(':
            myStack.push(c);
            break;
        case ']':
            if (myStack.empty() || myStack.top() != '[')
                return "NO";
            myStack.pop();
            break;
        case '}':
            if (myStack.empty() || myStack.top() != '{')
                return "NO";
            myStack.pop();
            break;
        case ')':
            if (myStack.empty() || myStack.top() != '(')
                return "NO";
            myStack.pop();
            break;
        default:
            return "NO";
        }
    }

    return myStack.empty() ? "YES" : "NO";
}
