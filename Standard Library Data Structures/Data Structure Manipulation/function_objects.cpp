/*
A function object (functor) is a object which acts like a function.
It is a class which defines operator()

The advantage is that it can hold state
*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout, std::string;

void test1();
void test2();

int main()
{
    cout << std::boolalpha << "\n";

    test1();

    cout << "\n\n";
}

void test1()
{
    // Example 1
    class MyFunctor
    {
        public:
            int operator()(int x) { return x * 2; }
    };

    MyFunctor doubler;
    cout << doubler(5) << "\n\n";


    // Example 2
    class Matcher
    {
        int target;
        public:
            Matcher(int t) : target(t) {}
            bool operator()(int x) { return x == target; }
    };

    Matcher equalTo5(5);
    cout << equalTo5(5) << "\n\n";


    // Example 3
    class Add_X
    {
        public:
            Add_X(int val) : x(val) {}
            int operator()(int y) { return x + y; }
        private:
            int x;
    };

    Add_X add40(40);
    cout << add40(21) << "\n\n";

    Add_X aaaa(-100);
    cout << aaaa(12) << "\n\n";

    // Using functors in std::transform
    std::vector<int> v1{0,1,2,3,4,5,6,7,8};
    std::vector<int> v2(v1.size());

    // can also use previously created functor like add40
    std::transform(v1.begin(), v1.end(), v2.begin(), Add_X(43)); 

    cout << "\nv1: ";
    for (int i : v1)
        cout << i << " ";

    cout << "\nv2: ";
    for (int i : v2)
        cout << i << " ";
}


void test2()
{

}