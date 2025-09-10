#include<iostream>
using namespace std;
inline int add(int ,int);
int main()
{
    cout<<"Value of 3+4 is:"<<add(3,4)<<endl;
}
int add(int a,int b){
    return a+b;
}