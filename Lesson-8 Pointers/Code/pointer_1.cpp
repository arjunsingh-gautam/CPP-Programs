// Introduction to pointers
#include <iostream>
int main()
{
    int x = 34;
    int *ptr = &x;
    std::cout << "Address stored in ptr:" << ptr << std::endl;
    std::cout << "Address of x is:" << &x << std::endl;
    std::cout << "Value of x:" << x << std::endl;
    std::cout << "Value stored at memory address pointed by ptr:" << *ptr << std::endl;
}