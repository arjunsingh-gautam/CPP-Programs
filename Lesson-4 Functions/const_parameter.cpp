// In this we will understand why const variable should be passed to make code more memory efficient where don't want to modify the passed parameter

#include <iostream>
void constParameter(const int &arg)
{
    std::cout << "Value:" << arg << std::endl;
    // arg = 54; // Error arg is const therefore only readable not writable
}
int main()
{
    const int x = 43;
    constParameter(x);
}