//In this code we will study about reference variable
#include<iostream>
using namespace std;
int main()
{
    int x = 10;
    int *pointter_x=&x;// pointer to x
    int &ref=x;// reference to x / act as another name for x
    ref=20;// this means x=20 // this means reference variable and x have same memory location
    cout<<"Value of x:"<<x<<endl;
    cout<<"Value of ref:"<<ref<<endl;

   // for pointer to do any change to x we to derefence it first using "*" dereference operator
   *pointter_x=30; // -> ref=x=30
    cout<<"Value of x:"<<x<<endl;
    cout<<"Value of ref:"<<ref<<endl; 
    
}