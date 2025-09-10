    /* Exercise 1.4: Our program used the addition operator, +, to add two
    numbers. Write a program that uses the multiplication operator, *, to print
    the product instead. */
    #include<iostream>
    using namespace std;
    int main()
    {
        int num1,num2;
        cout<<"Enter two numbers:"<<endl;
        cin>>num1>>num2;
        cout<<"Product of "<<num1<<" and "<<num2<<" is "<<num1*num2;
        return 0;
    }