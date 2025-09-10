//In this we discuss about inline function
#include<iostream>
using namespace std;
inline int add(int,int);// inline function request to compiler when function declared
int main()
{
    int num1,num2,s;
    cout<<"Enter two numbers:";
    cin>>num1;
    cin>>num2;
    s=add(num1,num2);// here compiler will copy a optimised code if he accepts the inline request ->Eg s=a+b
    cout<<"Sum of "<<num1<<" and "<<num2<<" is "<<s<<endl;
    return 0;

}
int add(int a,int b){
    return a+b;
}