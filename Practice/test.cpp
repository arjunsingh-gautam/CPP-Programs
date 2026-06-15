/* #include <iostream>
int main()
{
    // Primitive Data Types
    /*
    - Number: int,float,double
    - Character:char
    - Null value
    - Boolean Type:bool
    - We can change the size of data-type:signed,unsigned,short,long,long long,

    int x = 5;
    float y = 5.4;
    double z = 5.5;
    int64_t l = 5483838;
    std::cout << sizeof(x) << std::endl
              << sizeof(y) << std::endl
              << sizeof(z) << std::endl
              << sizeof(l) << std::endl;

    bool m = true;
    bool n = false;
    std::cout << m << std::endl
              << n << std::endl;

    char ch = 'A';
    std::cout << ch << std::endl;
    return 0;
}
*/

// const

/* #include <iostream>
int main()
{
    const int x = 64; // const keyword tells the compiler that the integer state is immutable after initialisation
    std::cout << x << std::endl;
    // x = 78; // here x is mutable state we can change the value assigned to this variable during the program in both runtime and compile time
    std::cout << x << std::endl;
    // Method 1: Using const_cast to remove const qualifier
    const int *ptr = &x;             // ptr points to const int
    *(const_cast<int *>(ptr)) = 383; // Remove const qualifier and modify
    std::cout << "After modification: " << x << std::endl;

    // Method 2: Non-const pointer (if you had one)
    int y = 100;
    int *ptr2 = &y; // Points to non-const int with const pointer
    *ptr2 = 300;
    std::cout << "y after modification: " << y << std::endl;
    return 0;
} */

// Block Scope
// Scoping Rules in C++
// Block Scope

/* #include <iostream>
int x = 43; // global definition
int main()
{
    std::cout << "Global Value:" << x << std::endl;
    int x = 56; // local definition
    std::cout << "Local Value:" << x << std::endl;
    {
        int x = 73; // local definition
        std::cout << "Local Value:" << x << std::endl;
    }
    std::cout << "Local Value:" << x << std::endl;
} */

// Array Datastructure in C++
// We can C-style arrays datatype array_name[size];
// Arrays have contiguous memory
// Arrays have O(1) indexing
// STL array
// STL array,raw array,numeric and iterator libraries

/* #include <iostream>
#include <array>
#include <numeric>
#include <iterator>
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5];
    std::array<int, 10> arr3;
    std::iota(std::begin(arr3), std::end(arr3), 5);
    std::cout << "Size of array:" << sizeof(arr2) / sizeof(arr2[0]) << std::endl;

    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
    {
        arr2[i] = 10 * i;
    }

    // Value inside arr2
    for (int i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++)
    {
        std::cout << arr3[i] << " , ";
    }
    std::cout << std::endl;
    // continguity of arrays
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
    {
        std::cout << "modifyress of index-" << i << " is:" << &arr2[i] << std::endl;
    }
} */

// Loops in C++:For,For-range loop,While,Do-While
/* #include <iostream>
int main()
{
    int arr[] = {1, 2, 3, 5};
    for (int i = 0; i < 3; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    for (auto element : arr)
    {
        std::cout << element << std::endl;
    }

    int countdown = 5;

    while (countdown > 0)
    {
        std::cout << countdown << std::endl;
        countdown--;
    }

    do
    {
        std::cout << countdown << std::endl;
        countdown--;

    } while (countdown > 1);
} */

// continue and break keyword:
/* #include <iostream>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
        {
            continue;
        }
        else
        {
            std::cout << arr[i] << std::endl;
        }
    }

    for (int element : arr)
    {

        std::cout << element << std::endl;
        if (element == 6)
        {
            std::cout << "6 is in Array therefore breaking the loop" << std::endl;
            break;
        }
    }
}
 */

// Recursive Function

/* #include <iostream>
int fact(int);
int main()
{
    int num;
    std::cout << "Enter a number:";
    std::cin >> num;
    std::cout << "Factorial of " << num << " is:" << fact(num) << std::endl;
}

int fact(int num)
{
    if ((num == 0) || (num == 1))
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
} */

// modifyress of Operator &
/* #include <iostream>
int main()
{
    int x = 76;
    float z = 98.338;
    std::cout << "modifyress of x is:" << &x << std::endl;
    std::cout << "modifyress of y is:" << &z << std::endl;
} */

// Pass by value:
/* #include <iostream>
int modifyByValue(int);
int modifyByReference(int &ref);
int modifyByPointer(int *);
int main()
{
    int x = 7;
    int &ref = x;
    std::cout << "Value of x: " << modifyByValue(x) << " x: " << x << std::endl;
    std::cout << "Value of x: " << modifyByReference(ref) << " x: " << x << std::endl;
    std::cout << "Value of x: " << modifyByPointer(&x) << " x: " << x << std::endl;
}

int modifyByValue(int val)
{
    return val += 20;
}

int modifyByPointer(int *ptr)
{
    return *ptr += 20;
}

int modifyByReference(int &ref)
{
    return ref += 20;
} */

// Classes in C++
/* #include <iostream>
#include <string>
class Animal
{
    // instance variable
    std::string name, species;

public:
    // Constructor
    Animal()
    {
        std::cout << "Constructor:" << std::endl;
        std::cout << "Enter the name of Animal:" << std::endl;
        std::getline(std::cin, name);
        std::cout << "Enter the species of Animal:" << std::endl;
        std::getline(std::cin, species);
    }
    // Instance Method
    void greet()
    {
        std::cout << "Hello from " << name << " I am a " << species << std::endl;
    }
};

int main()
{
    Animal a1;
    a1.greet();
    return 0;
} */

// instance data members and methods,class data member and function
/* #include <iostream>

class Student
{

    // Instance Variables:
    std::string name, department;
    int rollno;
    // Static Variable class data member:
    static inline const std::string university = "SIT"; // We can initialise const static variable inside class
    // Constructor
public:
    Student(std::string name, int rollno, std::string department)
    {
        std::cout << "Constructor called" << std::endl;
        this->name = name;
        this->rollno = rollno;
        this->department = department;
    }

    void greet()
    {
        std::cout << "Hello I am " << name << " of Department " << department << std::endl;
    }

    void static get_university()
    {
        std::cout << "Univeristy of student is:" << university << std::endl;
    }
};

int main()
{
    Student s1("Arjun Gautam", 220, "E&TC");
    Student s2("Ashish Balsure", 332, "CSE");
    s1.greet();
    s2.greet();
    Student::get_university();
    return 0;
} */

// call by object and return of object:

/* #include <iostream>

class Complex
{
    float real, imaginary;

public:
    Complex(float real, float imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    Complex add(Complex c1) // return type an object and call by object
    {
        Complex temp(0, 0);
        temp.real = this->real + c1.real;
        temp.imaginary = this->imaginary + c1.imaginary;
        return temp;
    }

    void get_num()
    {
        std::cout << real << '+' << imaginary << "j" << std::endl;
    }
};

int main()
{
    Complex c1(2, 3), c2(4, 5), c3(0, 0);
    c3 = c1.add(c2);
    c3.get_num();
    return 0;
} */

// Constructors in C++
/* - Normal constructor
- Parameterised constructor
- Constructor Overloading
 */

// Pass by value
/* #include <iostream>
void setValue(int arg)
{
    std::cout << "Argument value initially:" << arg << std::endl;
    arg = 9999;
    std::cout << "Argument value now:" << arg << std::endl;
}
int main()
{
    int x = 42;
    std::cout << "x's value:" << x << " x's address:" << &x << std::endl;
    setValue(x);
    std::cout << "x's value:" << x << " x's address:" << &x << std::endl;
} */

// Pass by reference
#include <iostream>
void setValue(int &arg)
{
    std::cout << "Argument value initially:" << arg << std::endl
              << "Argument address:" << &arg << std::endl;
    arg = 9999;
    std::cout << "Argument value initially:" << arg << std::endl
              << "Argument address:" << &arg << std::endl;
}
int main()
{
    int x = 42;
    int &ref = x;
    std::cout << "x's value:" << x << " x's address:" << &x << std::endl;
    setValue(ref);
    std::cout << "x's value:" << x << " x's address:" << &x << std::endl;
}