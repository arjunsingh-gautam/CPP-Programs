// Dynamic Memory allocated to objects
#include <iostream>

class Student
{
    int x;

public:
    Student()
    {
        x = 10;
        std::cout << "Constructor Executed" << std::endl;
    }

    ~Student()
    {
        std::cout << "Destructor Executed" << std::endl;
    }
};

int main()
{
    Student *s = new Student;
    delete s;
}