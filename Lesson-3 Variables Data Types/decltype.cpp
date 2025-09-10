// In this program we will learn about decltype() function and it's use
#include<iostream>
#include<typeinfo>
int main()
{
    int x =0;
    decltype(x) y;
    // decltype(expr): evaluate type of  the expression passed to it and returns the type
    std::cout<<"Type of variable y is:"<<typeid(y).name()<<std::endl;
    // Output:Type of variable y is:i ,i means integer
    return 0;
}