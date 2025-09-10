// In this program we will see how though signature of two functions is different but ambiguity is caused during call site
#include<iostream>
using namespace std;
void add(float,float);
void add(int,float);
int main()
{
    add(4,4);   // not raising ambiguity
    add(4.0f,4); // not raising ambiguity
    //add(4.0,4) // raising ambiguity
} 
void add(float a,float b)
{
    cout<<"Hello I am talking from add(float,float)"<<endl;
}
void add(int a,float b)
{
    cout<<"Hello I am talking from add(int,float)"<<endl;
}

// Compiler Raise error
//error: call of overloaded 'add(int, int)' is ambiguous
// Ambiguity because both candidates of function overload can be implemented here