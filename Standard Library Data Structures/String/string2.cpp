/*
  In C++, strings are mutable objects
  char arrays (char *strPtr = "test" is a pointer to an array of characters (C-style string))
*/

#include <iostream>

// #include <string>

using namespace std;

int main()
{
     string test = "323";
     test.append("HELLO"); // modifies test (strings are mutable)
     test[1] = 's';        // index must be between 0 and size-1. Or else runtime error

     cout << test + "Wjcisdonciodesj\n"
          << test
          << endl
          << endl;

     const char *d = "Hello mister... !"; // must be const (pointer to an array of chars -> no methods/ operators)

     // d[1] = 'e'; not allowed

     string s = d;
     cout << d << endl // char array
          << s << endl // string made from char array
          << s.insert(2, "##") << endl
          << s << endl
          << endl;

     cout << "char array: " << d << "\nstring made from array: " << s << endl
          << endl;

     cout << "Information about the string\t" << s << endl
          << "Size: " << s.size() << " " << s.length() << endl // size() and length() are the SAME (for strings)
          << "Is it empty? " << (s.empty() ? "Yes" : "No") << endl
          << "Last character: " << s.back() << endl
          << endl;

     s.clear();
     cout << "Now...Information about the string\t" << s << endl
          << "Size: " << s.size() << " " << s.length() << endl // size() and length() are the SAME (for strings)
          << "Is it empty? " << (s.empty() ? "Yes" : "No");

}
