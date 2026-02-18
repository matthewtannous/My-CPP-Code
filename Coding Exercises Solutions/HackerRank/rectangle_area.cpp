#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
  protected:
    int width, height;

  public:
    void display() { std::cout << width << " " << height << std::endl; }
};

class RectangleArea : public Rectangle
{
  public:
    void read_input() { std::cin >> width >> height; }

    void display()
    {
        // Rectangle::display(); // Remove this line because main will call the
        // base class (do not need to print width and height here)
        std::cout << width * height;
    }
};