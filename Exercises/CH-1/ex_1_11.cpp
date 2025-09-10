/* Exercise 1.11: Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers. */
#include<iostream>
using namespace std;
int main()
{
    int num1=0,num2=0;
    cout<<"Enter two numbers:";
    cin>>num1>>num2;
    if(num1>num2){
        int i=num2+1;
        cout<<"Numbers between "<<num2<<" and "<<num1<<" are:";
        while(i<num1){
            cout<<i<<",";
            i++;
        }
    }
    else{
        int i=num1+1;
        cout<<"Numbers between "<<num1<<" and "<<num2<<" are:";
        while(i<num2){
            cout<<i<<",";
            i++;
        }

    }

}

// Optimised solution:
/* #include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Ensure num1 is the smaller value
    if (num1 > num2) 
        swap(num1, num2);  

    cout << "Numbers between " << num1 << " and " << num2 << " are: ";

    // Print numbers between num1 and num2 (exclusive)
    for (int i = num1 + 1; i < num2; ++i) {
        cout << i;
        if (i < num2 - 1) cout << ", ";  // Avoid trailing comma
    }

    cout << endl;
    return 0;
}
 */