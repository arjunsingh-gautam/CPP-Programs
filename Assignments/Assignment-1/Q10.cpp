/* 10. Write a C++ program to add all the numbers of an array of size 10. */
#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int sum=0;
    for(int i=0;i<10;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    cout<<"The array is:";
    for(int i=0;i<10;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        sum+=arr[i];
    }
    cout<<"The sum of elements of array is:"<<sum<<endl;
}
