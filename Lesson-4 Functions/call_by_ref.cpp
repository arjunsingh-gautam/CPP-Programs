// Here we study function call by reference
#include <iostream>
using namespace std;

void modifyValue(int &a) { // here a becomes the alias for x 
    a = 20;  // Modifying the original variable directly
}

int main() {
    int x = 10;
    modifyValue(x);  // Passing 'x' by reference
    cout << "x = " << x << endl;  // Outputs: x = 20 (changed)
    return 0;
}
