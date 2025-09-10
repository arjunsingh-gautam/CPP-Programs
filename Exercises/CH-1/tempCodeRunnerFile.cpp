#include<iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    Sales_item book;
    Sales_item sum;
    int i=1;
    cout<<"Enter Transactions:"<<endl;
    while(cin>>book){
        cout<<"Transaction-"<<i<<" is:"<<book<<endl;
        sum+=book;
        i++;
    }
    cout<<"Cummulative Transaction:"<<sum<<endl;
    return 0;
}
