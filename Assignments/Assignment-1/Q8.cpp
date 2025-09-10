/* 8. Write a C++ program to swap values of two int variables without using third variable */
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"Enter the values of a and b:";
    cin>>a>>b;
    cout<<"Before Swap"<<endl<<"Value of a:"<<a<<" and value of b:"<<b<<endl;
    c=a;
    a=b;
    b=c;
    cout<<"After Swap"<<endl<<"Value of a:"<<a<<" and value of b:"<<b<<endl;
}