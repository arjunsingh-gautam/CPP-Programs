#include<iostream>
using namespace std;
int add(int a,int b=0,int c=5); //
int main()
{
    cout<<"Value of add(10,20,30):"<<add(10,20,30)<<endl;
    cout<<"Value of add(10,20):"<<add(10,20)<<endl;
    cout<<"Value of add(10):"<<add(10)<<endl;

}
int add(int a,int b,int c){
    return a+b+c;
}