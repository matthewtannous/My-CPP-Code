#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{
    string fileName = "write.txt";
    cout << "We are using the file \"write.txt\"\n";
    ifstream file;
    file.open(fileName.data());
    assert(file.is_open());

    cout << "File contents:" << endl;
    string value;
    // while (!file.eof())
    // {
    //     // file >> value; // ignores whitespace
    //     getline(file, value);
    //     cout << value << endl;
    // }

    // getline(file, value); // same as  getline(file, value, '\n');
    getline(file, value, '\0'); // reads all the file 
    cout << value;
}
