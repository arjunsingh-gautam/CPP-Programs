// Even if create a copy constructor there is a still a case of shallow copy where we copy when object already exist
// To Prevent this we need to write our own copy assignment operator which also handles this by deep copying

// How to handle shallow copy pitfalls by creating our own copy constructor which does deep copy
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

    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            delete age;
            age = new int(*other.age);
            std::cout << "Copy assignment operator Executed" << std::endl;
        }
        return *this;
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
    Person p2;
    p2 = p1; // Copy Assignment Operator called;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
    *p1.age = 20;
    std::cout << "State of instance p1:" << *(p1.age) << "\t" << "Address of state of instance p1:" << p1.age << std::endl;
    std::cout << "State of instance p2:" << *(p2.age) << "\t" << "Address of state of instance p2:" << p2.age << std::endl;
}