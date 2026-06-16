// In this we will learn about compiler generated copy constructor and how it works
#include <iostream>

// User Defined Type
class Person
{
public:
    int age;
    Person()
    {
        std::cout << "Constructor called" << std::endl;
        age = 18;
    }
    ~Person()
    {
        std::cout << "Destructor called" << std::endl;
    }
};

int main()
{
    Person p1;
    Person p2 = p1; // Compiler Generated copy constructor called;
    std::cout << "State of instance p1:" << p1.age << "\t" << "Address of state of instance p1:" << &p1.age << std::endl;
    std::cout << "State of instance p2:" << p2.age << "\t" << "Address of state of instance p2:" << &p2.age << std::endl;
}

// Notes:
/*
- Here the address of both intance members is different though shallow copy is done by default copy constructor since only value is copied not the address of the value/resourceh
- In such default copy constructor works well
*/