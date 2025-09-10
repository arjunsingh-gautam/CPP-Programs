/* Exercise 1.5: We wrote the output in one large statement. Rewrite the
program to use a separate statement to print each operand. */
#include<iostream>
    using namespace std;
    int main()
    {
        int num1,num2;
        cout<<"Enter two numbers:"<<endl;
        cin>>num1>>num2;
        cout<<"Product of ";
        cout<<num1;
        cout<<" and ";
        cout<<num2;
        cout<<" is ";
        cout<<num1*num2;
        return 0;
    }