#include <iostream>
#include "calculator.h"

int main() {

    Calculator mainCalc;
    int operation = 1, num1, num2;
    float result;

    std::cout << "Now, you will be asked to select an operation of the following list." << std::endl;
    std::cout << "Please, input the index (number) of the operation to apply:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Save History" << std::endl;
    std::cout << "6. Load previous History" << std::endl;
    std::cout << "7. Print the History" << std::endl;
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
                result = mainCalc.add();
                std::cout << "The result of the addition is: " << result << std::endl;
                break;
            case static_cast<int>(Operations::SUBSTRACTION): 
                std::cout << "You selected Subtraction." << std::endl;
                result = mainCalc.subtract();
                std::cout << "The result of the subtraction is: " << result << std::endl;
                break;
            case static_cast<int>(Operations::MULTIPLICATION): 
                std::cout << "You selected Multiplication." << std::endl;
                result = mainCalc.multiply();
                std::cout << "The result of the multiplication is: " << result << std::endl;
                break;
            case static_cast<int>(Operations::DIVISION): 
                std::cout << "You selected Division." << std::endl;
                result = mainCalc.divide();
                std::cout << "The result of the divison is: " << result << std::endl;
                break;
            case static_cast<int>(Operations::SAVE): 
                mainCalc.saveMatrix();
                std::cout << "The history so far has been sucessfully saved in history.txt file." << std::endl;
                break;
            case static_cast<int>(Operations::LOAD): 
                mainCalc.loadMatrix();
                std::cout << "The previous history has been loaded into current data" << std::endl;
                break;
            case static_cast<int>(Operations::PRINT): 
                mainCalc.printStorage();
                break;
            case static_cast<int>(Operations::EXIT): 
                std::cout << "Exiting the program." << std::endl;
                mainCalc.printStorage();
                mainCalc.saveMatrix();
                break;
            default:
                std::cout << "Undefined operation. Please, select a valid operation." << std::endl;
                break;
        }
    }

    return 0;
}