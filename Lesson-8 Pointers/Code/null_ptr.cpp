// Pitfalls of pointer: Null pointer
#include <iostream>
int main()
{
    int *ptr = nullptr;
    *ptr = 33; // this will lead to segmentation fault
    return 0;
}