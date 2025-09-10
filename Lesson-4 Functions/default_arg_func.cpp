#include <iostream>
using namespace std;

// Function with default arguments
int add(int a, int b = 0, int c = 0); // default arguments are only provided in function declaration


int main() {
    // Calling the function in various ways:
    
    // Call with all three arguments
    cout << "add(10, 20, 30) = " << add(10, 20, 30) << endl;

    // Call with two arguments, default value for 'c' is used
    cout << "add(10, 20) = " << add(10, 20) << endl;

    // Call with one argument, default values for 'b' and 'c' are used
    cout << "add(10) = " << add(10) << endl;

    return 0;
}

int add(int a, int b,int c) { // defaults arguments are not provided in function definition it will raise error while compiling
    return a + b + c;
}

//int add(int a = 0, int b, int c = 0); // ❌ Not allowed
/* 
In C++, all default arguments must be trailing (i.e., to the right) in the function parameter list. You cannot have a non-default argument after a default argument.
 */

// In C++ and C only positional arguments are allowed
// So you have to pass the arguments in the way they are defined