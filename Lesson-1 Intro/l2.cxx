/* In this we learn about how to use I/O objects in C++ using <iostream> Library */

# include<iostream> // Preprocessor Directive to include header <iostream> to use iostream library
int main()
{
    std::cout<<"Enter two numbers:"<<std::endl; // executes and expression
    // expression yields a result and is composed of one or more operands and operator
    // here it uses << : output operator
    // << chaining: cout_object<<RHS operand--> << insert RHS operand in output buffer and return cout_object
    int v1=0,v2=0;
    std::cin>>v1>>v2;
    /*
        - cin: istream object used to read input from input(buffer/device)
        - >> : input operator works exactly like << 
    */
    std::cout<<"The sum of "<<v1<<" and "<<v2<<" is "<<v1+v2<<std::endl;
    return 0;
}