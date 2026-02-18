#include <bits/stdc++.h>

using namespace std;

class Box
{
  private:
    int l, b, h;

  public:
    Box() : l(0), b(0), h(0) {}
    Box(int length, int breadth, int height) :
                        l(length), b(breadth), h(height) {}
    Box(Box &box) : l(box.l), b(box.b), h(box.h) {}

    int getLength() { return l; }
    int getBreadth() { return b; }
    int getHeight() { return h; }
    long long CalculateVolume() { return (long long)l * b * h; }

    bool operator<(Box &box)
    {
        if (h == box.h && b == box.b && l == box.l)
            return true;
        if (l < box.l)
            return true;
        if (b < box.b && l == box.l)
            return true;
        if (h < box.h && b == box.b && l == box.l)
            return true;
        return false;
    }
};

ostream &operator<<(ostream &out, Box &B)
{
    cout << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}
