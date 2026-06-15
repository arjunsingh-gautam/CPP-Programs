#include "calculator.hpp"
#include <iostream>
int main()
{
    Calculator calc;
    std::cout << "Addition:" << calc.add(10, 20) << std::endl;
    std::cout << "Multiplication:" << calc.multiply(10, 20) << std::endl;
}