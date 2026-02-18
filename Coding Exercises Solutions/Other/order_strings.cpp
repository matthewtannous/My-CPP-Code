/*
Problem:
You are given a string of words separated by a whitespace.
In each word there is a distinct digit.
Remove the number from the words, and return a string containing the words in
order the words according to their numbers.

Example:
ho2w h1ello you4 a3re   ---> hello how are you

*/

#include <bits/stdc++.h>

using namespace std;

string orderWords(const string &str)
{
    map<int, string> words;
    int count;
    string currentWord = "";

    for (char c : str)
    {
        if (c == ' ') // start a new word
        {
            words[count] = currentWord + ' ';
            currentWord.clear();
        }
        else if (c >= '0' && c <= '9')
        {
            count = c - '0';
        }
        else
        {
            currentWord.push_back(c);
        }
    }

    // add last word
    words[count] = currentWord + ' ';
    currentWord.clear();

    // reuse currentWord for result
    for (auto i : words)
    {
        currentWord.append(i.second);
    }

    return currentWord;
}

int main()
{
    string test = "ho2w h1ello you4 a3re";

    cout << orderWords(test) << "\n";
}