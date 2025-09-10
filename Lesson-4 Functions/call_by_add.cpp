// Here we study function call by address
#include <iostream>
#include<stdio.h>
using namespace std;

void modifyValue(int *a) {// here address of a is passed during function call which get stored in pointer variable a
    *a = 20;  // Modifying the value at the address pointed to by 'a'
}

int main() {
    int x = 10;
    printf("Befor Modifying value\n");
    cout << "x = " << x << endl ;// No change x=10
    modifyValue(&x);  // Passing the address of 'x'
    printf("After Modifying value\n");
    cout << "x = " << x << endl;  // Outputs: x = 20 (changed)
    return 0;
}
