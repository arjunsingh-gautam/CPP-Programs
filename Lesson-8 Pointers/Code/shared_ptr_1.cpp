// In this we will understand how to use shared pointer
#include <iostream>
#include <memory>
int main()
{
    auto p1 = std::make_shared<int>(10);
    auto p2 = p1;
    std::cout << "Value of p1:" << *p1 << " Address stored in p1:" << p1 << std::endl;
    std::cout << "Value of p2:" << *p2 << " Address stored in p2:" << p2 << std::endl;
    std::cout << "Reference count:" << p1.use_count() << std::endl;
}