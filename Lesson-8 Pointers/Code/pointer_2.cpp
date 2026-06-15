// Higher order pointers in CPP
#include <iostream>
int main()
{
    int x = 983;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
    int ***ptr3 = &ptr2;

    std::cout << "Address of x is:" << ptr1 << std::endl;
    std::cout << "Address of ptr1 is:" << ptr2 << std::endl;
    std::cout << "Address of ptr2 is:" << ptr3 << std::endl;
    std::cout << "Value stored in x:" << ***ptr3 << std::endl;
}