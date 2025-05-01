#include <iostream>
#include <vector>
#include <array>

#ifndef CALCULATOR_H
#define CALCULATOR_H

enum class Operations {
    ADDITION = 1,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXIT = 0,
    UNDEFINED = -1
};

class OperationNumbers {
    int value;
    bool even;
    int index;
};

class NumberResult : OperationNumbers {
    std::array<OperationNumbers, 2> result;
};

class Calculator {
public:

    Calculator();
    ~Calculator();

    void askNumbers();
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);

private:
    std::vector<OperationNumbers> operationNum;
    std::vector<NumberResult> resultNum;

    int num1, num2, result;
};

#endif
