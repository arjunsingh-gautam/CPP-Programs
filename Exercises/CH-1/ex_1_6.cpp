/* Exercise 1.6: Explain whether the following program fragment is legal.
std::cout << "The sum of " << v1;
<< " and " << v2;
<< " is " << v1 + v2 << std::endl;
C++ Primer, Fifth Edition
If the program is legal, what does it do? If the program is not legal, why
not? How would you fix it? */

// The code is illegal

// my approach:
/* #include<iostream>
    using namespace std;
    int main()
    {
        int v1,v2;
        cout<<"Enter two numbers:"<<endl;
        cin>>v1>>v2;
        cout << "The sum of " << v1;
        cout<< " and " ;
        cout<< v2;
        cout<< " is ";
        cout << v1 + v2;
        cout<< endl;
        return 0;
    } */


// Best way to fix the issue:
#include<iostream>
using namespace std;

int main() {
    int v1, v2;
    cout << "Enter two numbers: ";
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and" << v2
         << " is " << v1 + v2 << endl;
    return 0;
}
