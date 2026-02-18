/*
    There are three types of values that can be thrown as an exception:

        Built-in Types: primitive (int, char, ...) and non-primitive (string, )

        Standard Exceptions (subclasses of std::exception)
            most common standart exceptions are  std::logic_error and it's subclasses:
                invalid_argument, domain_error, length_error, out_of_range

        Custom Exceptions (created as subclass of a standard exception)

    abort() takes a boolean expression. If true, nothing happens.
    If false, the program ABORTS COMPLETELY. No exception is thrown.
*/


#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout, std::string;

void throwing_primitives();
void throwing_standard_exceptions();
void throwing_custom_exceptions();


int main()
{
    std::cout << "\n\n";
    // throwing_primitives(); // test throwing built-in types
    try 
    {
        throwing_standard_exceptions(); // test throwing standard exceptions
    }
    catch (std::length_error &e)
    {
        std::cout << "Length error " << e.what();
    }
    catch (std::logic_error &e)
    {
        std::cout << "Logic error " << e.what();
    }

    std::cout << "\n\nPart 3\n\n";

    throwing_custom_exceptions();
    std::cout << "\n\n";

}

// PART 1: throwing built-in types (DOES NOT NEED to #include any libraries)
void throwing_primitives()
{
    
    int a;

    std::cout << "Enter number: ";
    std::cin >> a;

    std::cout << std::endl;

    try
    {
        if (a < 0)
        {
            throw 2; // or throw(2)
        }
        else if (a == 10)
        {
            throw "10 ENTERED!"; // Caught by const char* (C-style string) catch-block
        }
        else if (a == 0)
        {
            throw std::string("0 ENTERED!"); // Caught by std::string catch-block
        }
    }
    catch (int errorCode)
    {
        std::cout << "ERROR CODE: " << errorCode << std::endl;
    }
    catch (std::string errorMessage)
    {
        std::cout << "Exception caught with std::string catch-block: " << errorMessage << std::endl;
    }
    catch (const char *errorMessage) // MUST be const char* errorMessage so that it matches an array of chars
    {
        std::cout << "Exception caught with const char* catch-block: " << errorMessage << std::endl;
    }
    catch (...) // ... catches all exceptions
    {
        std::cout << "Default ERROR";
    }

    std::cout << "Done, a = " << a << "\n\n";
}


// PART 2: throwing standard exceptions
void throwing_standard_exceptions()
{

    std::vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // cout << cars.at(2) << endl; // runs normally

    try
    {
        cout << cars.at(4); // throws an error
    }
    catch (std::out_of_range &e) // (Gives a warning or error) error: catching polymorphic type 'class std::out_of_range' by value [-Werror=catch-value=]
    {
        cout << e.what();
    }

    cout << "\n\n";

    throw (std::domain_error("AAAAAAAAAAAAA"));
}

// PART 3: creating and throwing custom exceptions

class MySimpleException : public std::exception
{
public:
    const char * what() const noexcept override {
        return "This is my simple custom exception";
    }
};

class MyAdvancedException : public std::exception
{
    private:
        int value;
    public:
        MyAdvancedException(int val) : value(val) {}
        const char * what() const noexcept override
        {
            return "This is my advanced custom exception";
        }

        int getValue() const
        {
            return value;
        }


};

void throwing_custom_exceptions()
{
    try
    {
        throw MySimpleException();
    } 
    catch (MySimpleException &e)
    {
        cout << e.what();
    }

    cout << "\n";

    try
    {
        throw MyAdvancedException(5);
    }
    catch (MyAdvancedException &e)
    {
        cout << e.what() << "    Value: " << e.getValue();
    }
}