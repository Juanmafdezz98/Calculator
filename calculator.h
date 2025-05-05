#include "functionalities.h"
#include "commondeclarations.h"

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <sstream>
#include <iomanip> 

#ifndef CALCULATOR_H
#define CALCULATOR_H

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
    void filterFunc();


private:
    std::vector<NumberInfo> storage;
    Functionalities functionalities;

    int num1, num2, result;
};

#endif
