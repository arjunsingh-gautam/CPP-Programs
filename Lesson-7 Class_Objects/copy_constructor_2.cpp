// Copy Constructor Shallow copy pitfalls
#include <iostream>

class Person
{
public:
    int *age;
    Person()
    {
        age = new int(10);
        std::cout << "Constructor Executed" << std::endl;
    }
    ~Person()
    {
        delete age;
        std::cout << "Destructor Executed" << std::endl;
    }
};

int main()
{
    Person p1;
    Person p2 = p1; // Compiler Generated copy constructor called;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
    *p1.age = 20;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
}

// Notes:
/*
- Here when compiler generate copy constructor is used it lead to shallow copy of address
- This result in share of same memory address by both objects for it's intance members
- This generate pitfalls related ownership,double delete etc.
- To handle this we need to create our own copy constructor which does deep copy
 */