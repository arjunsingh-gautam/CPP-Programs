// How public access modifier works:
#include <iostream>
using namespace std;

class A
{
public:
    int x;

    void show()
    {
        cout << x << endl;
    }
};

int main()
{
    A obj;
    obj.x = 10; // allowed
    obj.show(); // allowed
}