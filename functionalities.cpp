#include "functionalities.h"

void Functionalities::saveMatrixToTxt(const std::vector<NumberInfo>& storage)
{
    std::ofstream outFile("history.txt");

    if (!outFile)
    {
        std::cerr << "Error opening file history.txt for writing.\n";
        return;
    }
    
    for (const auto& entry : storage) {
        outFile << entry.index << " " << entry.value << " " << (entry.even ? "1 " : "0 ") << entry.operation << "\n";
    }

    outFile.close();
}

std::vector<NumberInfo> Functionalities::loadMatrixFromTxt()
{
    std::vector<NumberInfo> history;
    std::ifstream inFile("history.txt");

    if (!inFile)
    {
        std::cerr << "The file couldn't be loaded." << std::endl;
        return history;
    }

    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream row(line);
        int index;
        float value;
        bool even;
        std::string operation;

        row >> index >> value >> even;
        std::getline(row, operation);

        NumberInfo entry;
        entry.index = index;
        entry.value = value;
        entry.even = even;
        entry.operation = operation;

        history.push_back(entry);
    }

    return history;
}

void Functionalities::filterFunc(const std::vector<NumberInfo>& storage, const int filterType)
{
    std::vector<int> numbersFiltered;
    
    switch (filterType)
    {
    case static_cast<int>(FilterOptions::EVEN):
        getEvenOddData(storage);
        printEvenNumbers();
        break;
    case static_cast<int>(FilterOptions::ODD):
        getEvenOddData(storage);
        printOddNumbers();
        break;
    case static_cast<int>(FilterOptions::ADDITION):
        findOperationType(" + ", storage);
        break;
    case static_cast<int>(FilterOptions::SUBSTRACTION):
        findOperationType(" - ", storage);
        break;
    case static_cast<int>(FilterOptions::MULTIPLICATION):
        findOperationType(" * ", storage);
        break;
    case static_cast<int>(FilterOptions::DIVISION):
        findOperationType(" / ", storage);
        break;    
    default:
        break;
    }
}

void Functionalities::getEvenOddData(const std::vector<NumberInfo>& storage)
{
    _even.clear();
    _odd.clear();

    for (const auto& entry : storage)
    {
        if (entry.even) {
            _even.push_back(entry.value);
        } else {
            _odd.push_back(entry.value);
        }
    }
}

void Functionalities::printEvenNumbers()
{
    std::cout << "Even numbers: ";
    for (const auto& num : _even) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void Functionalities::printOddNumbers()
{
    std::cout << "Odd numbers: ";
    for (const auto& num : _odd) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void Functionalities::findOperationType(const std::string& operation, const std::vector<NumberInfo>& storage)
{
    int cont = 0;

    std::cout << "Operations with the selected type: " << operation << std::endl;
    for (const auto& entry : storage)
    {
        if (entry.operation.find(operation) != std::string::npos) {
            std::cout << entry.operation << std::endl;
            cont++;
        }
    }
    if (cont == 0) {
        std::cout << "No operations of this type were found." << std::endl;
    }
}