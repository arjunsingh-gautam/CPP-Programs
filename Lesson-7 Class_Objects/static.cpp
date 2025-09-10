// In this program we learn about static member variables and functions
#include <iostream>
using namespace std;

class Complex
{
    float real, imaginary;
    static int objectCount; // Static data member

public:
    // Constructor
    Complex(float r, float i)
    {
        real = r;
        imaginary = i;
        objectCount++; // Increment count when object is created
    }

    void display()
    {
        cout << real << " + " << imaginary << "i\n";
    }

    // Static member function
    static int getObjectCount()
    {
        return objectCount;
    }
    /*Notes
    - Can only access static member variables or other static member functions
    - Can be called without creating the object
    - Used to perform actions on static member variables
    - Not perform object specific action
    */
};

// Define static member outside the class
int Complex::objectCount = 0;

int main()
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    // Call static function via class name (recommended)
    cout << "Total Complex numbers: " << Complex::getObjectCount() << endl;

    // You *can* call via object, but it's not good style
    cout << "Total (via object): " << c1.getObjectCount() << endl;
}
