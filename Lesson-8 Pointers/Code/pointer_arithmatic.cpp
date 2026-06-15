// Pointer arithmatic
#include <iostream>
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // ptr points to the base address
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Address of block-" << i + 1 << ":" << ptr + i << std::endl;
        std::cout << "Value stored in block-" << i + 1 << ":" << *(ptr + i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Memory block between arr[1],arr[4]:" << (ptr + 4) - (ptr + 1) << std::endl;
}