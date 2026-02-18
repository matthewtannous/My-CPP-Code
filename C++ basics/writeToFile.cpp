/*
    MUST #include <fstream> to use.

    ifstream: file input stream (read from a file)
    ofstream: file output stream (write to a file)
    fstream: file stream (both input and output)

cin.ignore(): clears input stream (deletes \n so that getline() does not see \n at beginning and immediatly continue)
              if stream is already empty, it will delete the first character that is entered afterwards. (eg "hello" will become "ello")
              TIP: use cin.ignore() right after cin statements rather than using it before getline() statements.
*/

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int main()
{

    string fileName; // string to store file name.
    cout << "Enter the name of the output file: ";
    // cin >> fileName; // not good because name can contain spaces
    getline(cin, fileName); // gets everything until ENTER (\n)

    ofstream fileOutput(fileName.data()); // link to the file
    assert(fileOutput.is_open());         // check file is good to work with

    string userInput;
    cout << "Enter a message to put in the file: ";

    getline(cin, userInput);         // using normal cin >> stops at space
    fileOutput << userInput << endl; // write userInput to fileOutput

    const int COUNT = 10;
    for (int i = 0; i < COUNT; i++)
    {
        fileOutput << "AAAAAA" << i;
        if (i != COUNT - 1)
        {
            fileOutput << " and ";
        }
    }

    fileOutput.close(); // good practice
}
