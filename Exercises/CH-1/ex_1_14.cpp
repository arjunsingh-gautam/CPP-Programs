// Reading Unknown Number of Inputs:
#include<iostream>
using namespace std;
int main()
{
    int val=0,sum=0;
    while(cin>>val){ // condition-->T: if valid integer input provided | condition-->F: EOF is encounter using ctrl+Z or invalid input is provided in istream.
        sum+=val;
    }
    cout<<"Sum:"<<sum<<endl;
    return 0;
}