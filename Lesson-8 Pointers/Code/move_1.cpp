// Understanding move semantics in C++
#include <iostream>
int main()
{
    std::string oldString = "Arjun";
    std::string newString;

    std::cout << "Value before moving" << std::endl;
    std::cout << "oldString:" << oldString << std::endl;
    std::cout << "newString:" << newString << std::endl;
    newString = std::move(oldString);
    std::cout << "Value after moving" << std::endl;
    std::cout << "oldString:" << oldString << std::endl;
    std::cout << "newString:" << newString << std::endl;
}