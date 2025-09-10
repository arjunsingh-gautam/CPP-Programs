/* 4. Write a C++ program to calculate the volume of a cuboid. */
#include<iostream>
using namespace std;
int main()
{
    int l,b,h;
    cout<<"Enter the dimensions of cuboid:";
    cin>>l>>b>>h;
    cout<<"The volume of cuboid is:"<<l*b*h;
    return 0;
}