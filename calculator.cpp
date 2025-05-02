#include "calculator.h"

Calculator::Calculator() {
    std::vector<NumberInfo> storage;
    Functionalities functionalities;
}
Calculator::~Calculator() {}

int Calculator::add()
{   
    std::pair<int,int> numbers = askNumbers();
    saveNumber(numbers.first+numbers.second);
    saveOperation("+",numbers.first,numbers.second,numbers.first+numbers.second);
    return numbers.first+numbers.second;
}
int Calculator::subtract()
{
    std::pair<int,int> numbers = askNumbers();
    saveNumber(numbers.first-numbers.second);
    saveOperation("-",numbers.first,numbers.second,numbers.first-numbers.second);
    return numbers.first-numbers.second;
}
int Calculator::multiply()
{
    std::pair<int,int> numbers = askNumbers();
    saveNumber(numbers.first*numbers.second);
    saveOperation("*",numbers.first,numbers.second,numbers.first*numbers.second);
    return numbers.first*numbers.second;
}
float Calculator::divide()
{
    std::pair<int,int> numbers = askNumbers();
    if (numbers.second == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        saveNumber(0);
        return 0;
    }
    saveNumber(static_cast<float>(numbers.first)/numbers.second);
    saveOperation("/",numbers.first,numbers.second,numbers.first/numbers.second);
    return static_cast<float>(numbers.first)/numbers.second;
}
std::pair<int,int> Calculator::askNumbers()
{
    int num1, num2;

    std::cout << "Please, type the first number: ";
    std::cin >> num1;
    Calculator::saveNumber(num1);

    std::cout << "Please, type the second number:";
    std::cin >> num2;
    Calculator::saveNumber(num2);

    return {num1, num2};
}

void Calculator::saveNumber(float num)
{   
    NumberInfo numberInfo;

    numberInfo.value = num;
    numberInfo.even = isEven(num);
    numberInfo.index = static_cast<int>(storage.size());
    numberInfo.operation = "";
    storage.push_back(numberInfo);
}

void Calculator::saveOperation(std::string symbol, int num1, int num2, float res)
{
    std::string operation = std::to_string(num1) + " " + symbol + " " + std::to_string(num2) + " = " + std::to_string(res);
    storage.back().operation = operation;
}

bool Calculator::isEven(int a)
{
    return a % 2 == 0;
}

void Calculator::printStorage()
{
    std::cout << "History:" << std::endl;
    for (const auto& entry : storage) {
        std::cout << "Index: " << entry.index << ", Value: " << entry.value << ", Classification: " << (entry.even ? "Even " : "Odd ") <<  entry.operation << std::endl;
    }
}

void Calculator::saveMatrix()
{
    functionalities.saveMatrixToTxt(storage);
}

void Calculator::loadMatrix()
{
    std::vector<NumberInfo> prevHistory = functionalities.loadMatrixFromTxt();
    storage.insert(storage.end(),prevHistory.begin(),prevHistory.end());
}