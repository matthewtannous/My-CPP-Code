#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
  private:
    int age, standard;
    string first_name, last_name;

  public:
    void set_age(int age) { this->age = age; }
    int get_age() { return age; }

    void set_standard(int standard) { this->standard = standard; }
    int get_standard() { return standard; }

    void set_first_name(string first_name) { this->first_name = first_name; }
    string get_first_name() { return first_name; }

    void set_last_name(string last_name) { this->last_name = last_name; }
    string get_last_name() { return last_name; }

    string to_string()
    {
        stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        return ss.str();
    }
};