// Seeing where copy constructor get called and create unecessary copies and how to handle it
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

    Person(const Person &other)
    {
        // Deep Copy
        age = new int(*other.age); // New Heap Memory Created
        std::cout << "Copy Constructor Executed" << std::endl;
    }

    ~Person()
    {
        delete age;
        std::cout << "Destructor Executed" << std::endl;
    }
};

void PrintData(Person p)
{ // Pass by value function-> Leads to call of a copy constructor
    std::cout << "Instance state:" << *p.age << std::endl;
}

// To Prevent this copy we should pass by reference
void modifyPrintData(Person &p)
{
    std::cout << "Instance state:" << *p.age << std::endl;
}

int main()
{
    Person p1;
    Person p2 = p1; // Compiler Generated copy constructor called;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
    *p1.age = 20;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
    // Here copy constructor is called
    PrintData(p1);
    PrintData(p2);

    // Here copy constructor is not called
    modifyPrintData(p1);
    modifyPrintData(p2);
}