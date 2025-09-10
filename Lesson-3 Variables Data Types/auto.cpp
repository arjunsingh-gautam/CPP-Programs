// In this program we will learn about auto keyword
#include<iostream>
#include<typeinfo>
int main()
{
    auto real_num=0.0; 
    // Here we have not defined the type of real_num variable explicitly
    // The auto keyword determines the type of variable by evaluating the RHS expression
    std::cout<<"Type of variable real_num is:"<<typeid(real_num).name()<<std::endl; 
    // Output:Type of variable real_num is:d ,here d means double
}