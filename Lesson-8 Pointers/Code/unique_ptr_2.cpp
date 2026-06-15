// Understanding unique pointers using a user defined class
#include <iostream>
#include <memory>

// User Defined class
class UDT
{
public:
    // Constructor
    UDT()
    {
        std::cout << "Object Constructed" << std::endl;
    }
    // Destructor
    ~UDT()
    {
        std::cout << "Object Destroyed" << std::endl;
    }
};
int main()
{
    // auto p1 = std::make_unique<UDT>(); # Method-1

    // Creating an array of objects
    // std::unique_ptr<UDT[]> p1 = std::make_unique<UDT[]>(5);

    // Initialising unique pointer with old syntax
    std::unique_ptr<UDT> p1 = std::unique_ptr<UDT>(new UDT);
    return 0;
}