// structure in C++

#include <iostream>
using namespace std;

struct Student
{
private:
    int id;
    string name;

    // Constructor
public:
    Student()
    {
        cout << "Enter student id:";
        cin >> id;
        cout << endl;
        cout << "Enter student name:";
        cin >> name;
    }

    void get()
    {
        cout << "Name of Student:" << name << endl;
        cout << "Id of Student:" << id << endl;
    }
};

int main()
{
    Student s1;
    s1.get();
    return 0;
}