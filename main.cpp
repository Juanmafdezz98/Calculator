#include <iostream>
#include "calculator.h"

int main() {

    Calculator mainCalc;
    int operation = 1, num1, num2, result;

    std::cout << "Now, you will be asked to select an operation of the following list." << std::endl;
    std::cout << "Please, input the index (number) of the operation to apply:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Then, you will type two numbers to apply the choosen operation." << std::endl;
    std::cout << "Clarification: in the divison, the first number will be the dividend and the second number will be the divisor." << std::endl;


    while (operation !=0)
    {
        std::cout << "Please, select your operation: ";
        std::cin >> operation;

        switch (operation)
        {
            case static_cast<int>(Operations::ADDITION): 
                std::cout << "You selected Addition." << std::endl;
                mainCalc.askNumbers();
                result = mainCalc.add(num1, num2);
                break;
            case static_cast<int>(Operations::SUBSTRACTION): 
                std::cout << "You selected Subtraction." << std::endl;
                mainCalc.askNumbers();
                result = mainCalc.subtract(num1, num2);
                break;
            case static_cast<int>(Operations::MULTIPLICATION): 
                std::cout << "You selected Multiplication." << std::endl;
                mainCalc.askNumbers();
                result = mainCalc.multiply(num1, num2);
                break;
            case static_cast<int>(Operations::DIVISION): 
                std::cout << "You selected Division." << std::endl;
                mainCalc.askNumbers();
                result = mainCalc.divide(num1, num2);
                break;
            case static_cast<int>(Operations::EXIT): 
                std::cout << "Exiting the program." << std::endl;
                //TODO: guaradar el estado de la calculadora
                break;
            default:
                std::cout << "Undefined operation. Please, select a valid operation." << std::endl;
                break;
        }
    }

    return 0;
}