/* Q5. Write a C++ program to calculate an average of 3 numbers. */
#include<iostream>
using namespace std;
int main()
{
    int num1,num2,num3;
    cout<<"Enter the numbers:";
    cin>>num1>>num2>>num3;
    cout<<"The average of three numbers "<<num1<<" "<<num2<<" "<<num3 <<" is:"<<(num1+num2+num3)/3;
    return 0;
}