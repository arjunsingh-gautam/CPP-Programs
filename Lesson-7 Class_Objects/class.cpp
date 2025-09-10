// In this code we will learn about class and object in C++
// Task:Define a class to represent a complex number. Store real and imaginary part.Also define methods to set values of real and imaginary part of a complex number. Define one more method to display complex number

#include <iostream>
using namespace std;

// Class definition
class Complex
{
    float real, imaginary;

    // member methods:
public:
    void complex(float a, float b)
    {
        real = a;
        imaginary = b;
    }
    void display_complex()
    {
        cout << "Complex number is:" << real << '+' << imaginary << 'i' << endl;
    }
};

int main()

{
    Complex num;
    num.complex(2, 4);
    num.display_complex();
}