// Defining Function Pointer using functional library
#include <iostream>
#include <functional>
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    std::function<int(int, int)> ptr;
    int option;
    std::cout << "Enter 1 for add and 2 for multiply:";
    std::cin >> option;
    if (option == 1)
    {
        ptr = add;
    }
    else if (option == 2)
    {
        ptr = multiply;
    }
    int x, y;
    std::cout << "Enter value of x and y:";
    std::cin >> x >> y;
    std::cout << "Operation:" << ptr(x, y) << std::endl;
}