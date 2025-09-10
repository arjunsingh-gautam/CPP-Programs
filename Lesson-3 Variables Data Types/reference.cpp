// In this program we will learn about references in C++
#include<iostream>
int main()
{
    int x =5;
    int& r=x;
    // r is an alias (dusra naam) to  x 
    // r an x have same address
    // reference needs to be initialised at time of declaration
    // Once a reference is intialised to a variable it binds with it and cannot be reinitialised
    std::cout<<"Value of x is:"<<x<<std::endl;
    std::cout<<"Value of r is:"<<r<<std::endl;
    std::cout<<"Address of x is:"<<&x<<std::endl;
    std::cout<<"Address of r is:"<<&r<<std::endl;
    r=100;
    std::cout<<"Value of x is:"<<x<<std::endl;
    std::cout<<"Value of r is:"<<r<<std::endl;
    return 0;

}

/*
Output:
Value of x is:5
Value of r is:5
Address of x is:0xb051ff874 // Address of both x and r is same because r is just an alias to x 
Address of r is:0xb051ff874 // You can see it as a memory location having two names 
Value of x is:100
Value of r is:100
*/