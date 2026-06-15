// in this we learn about Dynamic Memory Allocation
#include <iostream>
int main()
{
    int *ptr = new int;
    *ptr = 10;
    std::cout << "Address of Dynamically Allocated Memory:" << ptr << std::endl;
    std::cout << "Value stored at DMA block:" << *ptr << std::endl;
    return 0;
}