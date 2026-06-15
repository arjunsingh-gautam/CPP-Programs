// This code demonstrates call by object and return of object in C++
#include <iostream>
using namespace std;
class Complex
{
private:
    float real;
    float imag;

public:
    Complex(float a, float b)
    {
        real = a;
        imag = b;
    }

    Complex add(Complex c1) // call by object and return of obj
    {
        Complex temp(0, 0);
        temp.real = real + c1.real;
        temp.imag = imag + c1.imag;
        return temp;
    }
    void get_value()
    {
        cout << "Complex number is:" << real << "+" << imag << "j" << endl;
    }
};
int main()
{
    Complex c1(4, 5), c2(5, 2), c3(0, 0);
    c3 = c1.add(c2);
    c3.get_value();
    return 0;
}