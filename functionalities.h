#include "numberStructure.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <string>

#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

class Functionalities {
public:

    Functionalities() = default;
    ~Functionalities() = default;

    void saveMatrixToTxt(std::vector<NumberInfo>& storage);
    std::vector<NumberInfo> loadMatrixFromTxt();

private:
};

#endif