// Here we study function call by value
#include <iostream>
using namespace std;

void modifyValue(int a) { // here a variable gets the copy of value stored in x
    a += 20;  // Modifying the copy, not the original
    cout<<"We are inside function scope"<<endl<<"Value of a:"<<a<<endl;
}

int main() {
    int x = 10;
    modifyValue(x);
    cout << "x = " << x << endl<<"No change in value of x";  // Outputs: x = 10 (unchanged)
    return 0;
}
