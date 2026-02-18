/*
when taking input with cin >> myString , cin stops when it arrives at a whitespace.
You can't take as input "This string" with cin

To extract a full line (including spaces), use
std::getline(std::cin >> std::ws, myString);

std::ws   is used to remove leading whitespace in the buffer of cin

*/

#include <iostream>
#include <string>

int main() {
    std::cout << "\n";
    
    
    // Input
    std::string name { };
    std::cout << "Enter your name: ";
    // std::cin >> name;
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your favorite color: ";
    std::string color{};
    // std::cin >> color;
    std::getline(std::cin >> std::ws, color);

    std::cout << "Name: " << name << ", color: " << color;
    

    using namespace std::string_literals;
    std::cout << "TEST"s; // Initialize as a std:string instead of a C-style string

    std::cout << "\n\n";
    
}