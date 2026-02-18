/*
string_view is a read-only string. we do not make copies of them,
    making them more efficient to work with

A std::string_view object can be initialized with a C-style string,
    a std::string, or another std::string_view

A C-style string and std::string will implicitly convert to a std::string_view
BUT std::string_view will not implicitly convert to a C-style string or std::string
*/

#include <iostream>
#include <string_view>

void print(std::string_view s) {
    std::cout << s << "\n";
}

int main() {
    // std::string_view s {"FUWEJ"};
    // std::cout << s << "\n";

    // print("This is a c-style string");
    // std::string s2 {"string object"};
    // print(s2);


    // using namespace std::string_literals;      // access the s suffix
    // using namespace std::string_view_literals; // access the sv suffix

    // std::cout << "foo\n";   // no suffix is a C-style string literal
    // std::cout << "goo\n"s;  // s suffix is a std::string literal
    // std::cout << "moo\n"sv; // sv suffix is a std::string_view literal



    // constexpr std::string_view s0{ "Hello, world!" }; // s0 is a string symbolic constant
    // std::cout << s0 << '\n'; // s0 will be replaced with "Hello, world!" at compile-time


    std::string s = "HELLOOOO\n";

    std::string_view sv {s};

    std::cout << s << sv;
    
    s = "BYEEE\n";
    std::cout << s << sv;

    std::cout << sv;
}