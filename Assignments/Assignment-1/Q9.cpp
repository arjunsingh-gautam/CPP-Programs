/* 9. Write a C++ program to find the maximum of two numbers. */
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int num1,num2;
    cout<<"Enter two numbers:";
    cin>>num1>>num2;
    int max=0;
    if (num1>num2){
        max=num1;
        printf("The maximum of %d and %d is %d",num1,num2,max);
    }
    else{
        max=num2;
        printf("The maximum of %d and %d is %d",num1,num2,max);
    }
}