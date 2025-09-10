// In this program we will demostrate function polymorphism 
#include<iostream>
using namespace std;
#define PI 3.14
float area(int r); 
int area(int ,int);
void area();
int main()
{
    int r,l,b;
    cout<<"Enter radius of circle:"<<endl;
    cin>>r;
    cout<<"Enter length and breadth of rectanble"<<endl;
    cin>>l>>b;
    area();
    cout<<"Area of circle of radius "<<r<<" is:"<<area(r)<<endl;
    cout<<"Area of rectangle of length "<<l<<" and breadth "<<b<<" is:"<<area(l,b)<<endl;
    
    return 0;
}
float area(int r)
{
    return PI*r*r;
}
int area(int l,int b)
{
    return l*b;
}
void area()
{
    int s;
    cout<<"Enter side of square:"<<endl;
    cin>>s;
    cout<<"Area of square of side "<<s<<" is:"<<s*s<<endl;
}


// Here two functions have same name but when called the call is resolved by no. of arguments passed and type of arguments passed
// Though names are same both function have unique signature due to differen argument definition
// Function overload resolution depend on 
//- no. of argument passed 
//- type of argument passed
// - order in which argument passed