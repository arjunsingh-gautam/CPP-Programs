// C++ struct can have member functions

#include <iostream>

using namespace std;

struct Rectangle
{
    int width, height;
    int area()
    {
        return width * height;
    }
};

int main()
{
    Rectangle r1;
    r1.width = 10;
    r1.height = 20;
    printf("Area of rectangle:%d", r1.area());
    return 0;
}