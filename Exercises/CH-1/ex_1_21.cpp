/* Exercise 1.21: Write a program that reads two Sales_item objects that
have the same ISBN and produces their sum. */

#include<iostream>
#include"Sales_item.h"
using namespace std;
int main()
{
    Sales_item book1,book2;
    cout<<"Enter transactions:"<<endl;
    cin>>book1>>book2;
    cout<<"Cummulative transaction:"<<book1+book2<<endl;
    return 0;
}