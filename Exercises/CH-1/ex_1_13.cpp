// For Loop implementation of Ex 1.11:
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
} */


// For Loop Implementation of exercise 1.10

/* #include<iostream>
using namespace std;
int main()
{
    for(int i =10;i>-1;i--){
        cout<<i<<",";
    }
} */

// For Loop Implementation of ex 1.9:

# include<iostream>
using namespace std;
int main()
{
    int sum=0;
    for(int i=0;i<51;++i){
        sum+=(50+i);
    }
    cout<<"Sum of numbers from 50 to 100 is:"<<sum<<endl;
    return 0;
}