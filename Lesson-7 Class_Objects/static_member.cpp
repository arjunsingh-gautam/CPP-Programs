// In this program we will learn about static member variable

#include <iostream>
using namespace std;
class Counter
{

private:
    int inst_a; // Life same as object life
    // static member variable
    // Life till end of program
    // common to all class objects
    // also called class variable
    static int count; // in class initialisation of non const static member variable is not allowed

public:
    Counter()
    {
        count++;
        cout << count << endl;
        cout << "Constructor called" << endl;
    }
    ~Counter()
    {
        cout << "Destructor called" << endl;
    }
};
int Counter::count = 0; // out class static member variable definition it is compulsary then only static member variable will get memory space
// It is shared by all the objects of the class
int main()
{

    Counter a, b;
}