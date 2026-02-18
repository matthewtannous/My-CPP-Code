#include <iostream>

namespace n1
{
    int s = 123;
    std::string msg = "First namespace";
    void greet()
    {
        std::cout << "WOW hello from namespace1\n";
    }
}

using std::cout, std::endl; // Best practice, only use what you need instead of using all the namespace, to avoid collisions
using namespace n1;

int main()
{
    std::string s = "D";
    cout << s << endl // prints D
         << n1::s;

    
}
