#include <iostream>
#include "calculator.h"

Calculator::Calculator() {}
Calculator::~Calculator() {}

int Calculator::add(int a, int b) {
    return a + b;
}
int Calculator::subtract(int a, int b) {
    return a - b;
}
int Calculator::multiply(int a, int b) {
    return a * b;
}
int Calculator::divide(int a, int b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0;
    }
    return a / b;
}
void Calculator::askNumbers() {
    std::cout << "Please, type the first number: ";
    std::cin >> num1;
    std::cout << "Please, type the second number:";
    std::cin >> num2;
}