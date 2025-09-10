//Program to calculate square of a number
#include<iostream>// C++ header files does not have .h extension
using namespace std; // 'using' is a keyword used here to use std namespace named entities without using :: -> scope resolution operator to access them
int main()
{
    int num;
    cout<<"Enter a number:"; // here 'cout' is a predefined object and << is insertion operator when used with cout
    cin>>num;// here 'cin' is a predefined object and >> is extraction operator when used with cin
    cout<<"Square of "<<num<<" is "<<num*num;
    cout<<endl; // here 'endl' is a manipulator which act like a \n character
    return 0;

}