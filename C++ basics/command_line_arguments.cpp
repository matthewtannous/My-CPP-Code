#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "\n\n" << argc << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "1: " << argv[i] << "\n";
    }

    std::cout << "\n\n";
}