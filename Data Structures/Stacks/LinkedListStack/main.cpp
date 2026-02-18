// PREVIOUS pdf

#include <iostream>
#include "Stack.h"

using namespace std;
int getSize(Stack &stack);
int getSize2(Stack &stack);
bool isBalanced(string &str);

int main()
{
    // Stack s;
    // s.push(31);

    // s.push(431);

    // cout << getSize(s) << endl;

    // cout << s;

    // cout << getSize2(s) << endl;
    // cout << s;

    cout << boolalpha;

    string s = "(({{[()]}}(({{{[]}}})))[]";
    cout << isBalanced(s);
}

bool isBalanced(string &str)
{
    // if string length is odd, return false immediately
    // if (str.length() % 2 == 1)
    // {
    //     return false;
    // }

    // push opening characters
    // if closing character, compare with top of stack

    Stack stack;
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '[':
        case '{':
        case '(':
            stack.push(str[i]);
            break;
        case ']':
            if (stack.top() == '[')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
            break;
        case ')':
            if (stack.top() == '(')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
        }
    }

    return stack.isEmpty();
}

int getSize(Stack &stack)
{
    int count = 0;
    // With copy-constructor
    Stack copy(stack);
    while (!copy.isEmpty())
    {
        count++;
        copy.pop();
    }

    return count;
}

int getSize2(Stack &stack)
{
    // Without copy-constructor
    int count = 0;
    Stack copy;
    while (!stack.isEmpty())
    {
        count++;
        copy.push(stack.top());
        stack.pop();
    }

    while (!copy.isEmpty())
    {
        stack.push(copy.top());
        copy.pop();
    }

    return count;
}
