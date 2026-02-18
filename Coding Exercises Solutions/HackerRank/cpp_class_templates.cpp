#include <cassert>
#include <iostream>
using namespace std;

// From ChatGPT
// Static initialization before main() runs
// This function makes cin and cout faster
static const auto fast_io = []()
{
    ios::sync_with_stdio(false); // disable synchronization
    cin.tie(nullptr);            // untie cin from cout
    return 0;
}();

/*Write the class AddElements here*/
template <typename T> class AddElements
{
  private:
    T element;

  public:
    AddElements(T ele) : element(ele) {}
    T add(T other)
    {
        element += other;
        return element;
    }
};
template <> class AddElements<string>
{
  private:
    string element;

  public:
    AddElements(string ele) : element(ele) {}
    //   string add(string other) {
    //     return element + other;
    //   }
    string concatenate(string other)
    {
        // element += other;
        return element + other;
    }
};