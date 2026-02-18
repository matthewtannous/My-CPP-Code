#include <bits/stdc++.h>

class BadLengthException : public std::exception
{
  private:
    int n;

  public:
    BadLengthException(int n) : n(n) {}
    int what()
    {
        // string s = "Too short: " + to_string(n);
        // return "Too short: " + to_string(n).c_str();
        return n;
    }
};
