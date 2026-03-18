// here we learn about name spaces
#include <iostream>
using namespace std; // here 'using' keyword is used to bring namespace std into scope
// using namespace library2; // These generates ambiguity since printMessage function inside both namespace with same name
//  First namespace
namespace library1
{
    void printMessage()
    {
        cout << "Message from library 1" << endl;
    }
}

// Second namespace
namespace library2
{
    void printMessage()
    {
        cout << "Message from library 2" << endl;
    }
}

int main()
{
    // Access functions from different namespaces
    library1::printMessage();
    library2::printMessage();

    return 0;
}

// Uses of namespace:
//  1. To solve naming conflicts
//  2. To group identifiers together this can be function declarations,variable declarations,etc.
//  3. To access identifier we can use :: (scope resolution operator) or 'using' keyword

/*
- Namespace variables are global variables whose names are grouped under a namespace prefix.
- They live in .data/.bss/.rodata, just like global variables.
- They are resolved by the compiler using A::x, but at runtime they are plain global memory. */