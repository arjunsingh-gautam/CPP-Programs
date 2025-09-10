/* Exercise 1.12: What does the following for loop do? What is the final value
of sum?
int sum = 0;
for (int i = -100; i <= 100; ++i)
sum += i; */

// print sum from -100 to 100 
// ans: 0

# include<iostream>
using namespace std;
int main()
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    cout<<"Sum:"<<sum<<endl;
    return 0;
}