/* Exercise 1.9: Write a program that uses a while to sum the numbers from
50 to 100. */

# include<iostream>
using namespace std;
int main()
{
    int i=0,sum=0;
    while(i<51){
        sum+=(50+i);
        i++;
    }
    cout<<"Sum of numbers from 50 to 100 is:"<<sum<<endl;
    return 0;
}