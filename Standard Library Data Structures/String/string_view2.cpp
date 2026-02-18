#include <iostream>
#include <string_view>

std::string getName() {
    std::string s {"HELLO\n"};
    return s;
}

int main() {


    std::string_view name {getName() };

    std::cout << name;

    std::string_view sv{};
    {
        std::string s {"BYE\n"};
        sv = s;
    }


    std::cout << sv << "\n";


    ////////////
    std::string_view str {"Hello there"};
    using std::cout;

    cout << str << "\n";
    str.remove_prefix(3);
    cout << str << "\n";
    str.remove_prefix(3);
    cout << str << "\n";
    str.remove_suffix(3);
    cout << str << "\n";

    str = "Hello there"; // Can only reset by reassigning
    cout << str << "\n";



    cout << "\n\n";

}