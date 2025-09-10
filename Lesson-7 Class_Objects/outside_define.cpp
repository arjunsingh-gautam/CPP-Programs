// In this Program we will demonstrate how can we define member function outside class
// In this code we will learn about constructors in C++

#include <iostream>
using namespace std;
class complex
{
    // Data Members:
    float real_, imaginary;
    // Constructor + Setter
public:
    complex(float a, float b) // same name as class // call automatically when object of class is created // used to set values of object data members // no return type
    {
        real_ = a;
        imaginary = b;
        cout << "Constructor is called when object is created" << endl;
    }

    // getter
    float real()
    {
        return real_;
    }
    float imag()
    {
        return imaginary;
    }
    void print(); // Declare inside function
};
void complex::print() // Definition of Member function outside the class
// Here we :: (membership operator) to tell print() belongs to complex class
{
    cout << "Complex Number is:" << real_ << '+' << imaginary << "i" << endl;
}
int main()
{
    complex num(2, 4);
    cout << "Real part is:" << num.real() << endl;
    cout << "Imaginary part is:" << num.imag() << endl;
    num.print();
}