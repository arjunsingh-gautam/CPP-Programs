// How to define function pointer using method-1
#include <iostream>

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
    int (*fnptr)(int, int);
    int option;
    std::cout << "Enter 1 for add and 2 for multiply:";
    std::cin >> option;
    if (option == 1)
    {
        fnptr = add;
    }
    else if (option == 2)
    {
        fnptr = multiply;
    }
    int x, y;
    std::cout << "Enter value of x and y:";
    std::cin >> x >> y;
    std::cout << "Operation:" << fnptr(x, y) << std::endl;
}