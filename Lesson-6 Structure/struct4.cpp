// Constructor in structure: initialise objects automatically

#include <iostream>

struct Point
{
    int x, y;
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    Point p(1, 4);
    std::cout << "x:" << p.x << std::endl
              << "y:" << p.y << std::endl;
    return 0;
}