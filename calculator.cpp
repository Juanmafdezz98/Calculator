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
    saveOperation("/",numbers.first,numbers.second,static_cast<float>(numbers.first)/numbers.second);
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
    numberInfo.operation = " ";
    storage.push_back(numberInfo);
}

void Calculator::saveOperation(std::string symbol, int num1, int num2, float res)
{
    std::ostringstream aux;
    aux << num1 << " " << symbol << " " << num2 << " = ";

    if (res == static_cast<int>(res)) aux << static_cast<int>(res);
    else aux << res;
    
    storage.back().operation = aux.str();
}

bool Calculator::isEven(int num)
{
    return num % 2 == 0;
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

void Calculator::filterFunc()
{
    int filterOption;

    std::cout << "Please, select now what filter you desire to apply: " << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Filter even numbers" << std::endl;
    std::cout << "2. Filter odd numbers" << std::endl;
    std::cout << "3. Filter results from a specific operation type" << std::endl;
    std::cout << "Please, type which filter you want to apply: ";
    std::cin >> filterOption;

    if (filterOption < 0 || filterOption > 3)
    {
        std::cerr << "Invalid filter option." << std::endl;
        return;
    }
    if (filterOption == 0)
    {
        std::cout << "Exiting the filter functionality." << std::endl;
        return;
    }
    if (filterOption == 1 || filterOption == 2)
    {
        functionalities.filterFunc(storage, filterOption);
        return;
    }
    if (filterOption == 3) {
        int operationType;
        std::cout << "Please, type the operation type you want to filter: " << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Addition" << std::endl;
        std::cout << "2. Subtraction" << std::endl;
        std::cout << "3. Multiplication" << std::endl;
        std::cout << "4. Division" << std::endl;
        std::cout << "Please, type which filter you want to apply: ";
        std::cin >> operationType;

        if (operationType < 0 || operationType > 4)
        {
            std::cerr << "Invalid operation type." << std::endl;
            return;
        }
        if (operationType == 0)
        {
            std::cout << "Exiting the filter functionality." << std::endl;
            return;
        }

        functionalities.filterFunc(storage, operationType+2);
        return;
    }

}