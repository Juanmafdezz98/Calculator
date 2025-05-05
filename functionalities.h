#include "commondeclarations.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

class Functionalities {
public:

    Functionalities() = default;
    ~Functionalities() = default;

    void saveMatrixToTxt(const std::vector<NumberInfo>& storage);
    std::vector<NumberInfo> loadMatrixFromTxt();
    void filterFunc(const std::vector<NumberInfo>& storage, const int filterType);
    void getEvenOddData(const std::vector<NumberInfo>& storage);

    void printEvenNumbers();
    void printOddNumbers();
    void findOperationType(const std::string& operation, const std::vector<NumberInfo>& storage);

private:
    std::vector<int> _even;
    std::vector<int> _odd;
};

#endif