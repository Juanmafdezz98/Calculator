#include "functionalities.h"
#include "numberStructure.h"

#include <iostream>
#include <vector>
#include <array>
#include <utility>

#ifndef CALCULATOR_H
#define CALCULATOR_H

enum class Operations {
    ADDITION = 1,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION,
    SAVE,
    LOAD,
    PRINT,
    EXIT = 0,
    UNDEFINED = -1
};

class Calculator {
public:

    Calculator(); 
    ~Calculator();

    std::pair<int, int> askNumbers();
    int add();
    int subtract();
    int multiply();
    float divide();

    bool isEven(int num);

    void saveNumber(float num);
    void saveOperation(std::string symbol, int num1, int num2, float result);
    
    void printStorage();
    void saveMatrix();
    void loadMatrix();


private:
    std::vector<NumberInfo> storage;
    Functionalities functionalities;

    int num1, num2, result;
};

#endif
