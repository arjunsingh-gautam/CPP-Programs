/* Exercise 1.20: http://www.informit.com/title/032174113 contains a copy of
Sales_item.h in the Chapter 1 code directory. Copy that file to your
working directory. Use it to write a program that reads a set of book sales
transactions, writing each transaction to the standard output. */

#include<iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book;
    int i=1;
    cout<<"Enter Transactions:"<<endl;
    while(cin>>book){
        cout<<"Transaction-"<<i<<" is:"<<book<<endl;
        i++;
    }
    cout<<"All transaction printed..."<<endl;
    return 0;
}