// In this we will use unique_ptr which is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
#include <iostream>
#include <memory>
int main()
{
    {
        auto p1 = std::make_unique<int>(10);
        std::cout << "Value of Pointer:" << *p1;
    }
}