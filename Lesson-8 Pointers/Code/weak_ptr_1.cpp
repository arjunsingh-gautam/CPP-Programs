// Weak pointer is a shared pointer which does not increase reference count
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
    std::weak_ptr<UDT> p2;
    {
        std::shared_ptr<UDT> p1 = std::make_shared<UDT>();
        {
            p2 = p1;
            std::cout << "Reference Count:" << p1.use_count() << std::endl;
        }
        std::cout << "Reference Count:" << p1.use_count() << std::endl;
    }
    std::cout << "Destructor Called before this line" << std::endl;
}