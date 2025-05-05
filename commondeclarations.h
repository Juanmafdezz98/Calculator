#include <iostream>
#include <vector>

#ifndef NUMBERSTRUCTURE_H
#define NUMBERSTRUCTURE_H

struct NumberInfo {
    int index;
    float value;
    bool even;
    std::string operation;
};

enum class FilterOptions {
    EVEN = 1,
    ODD,
    ADDITION,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION
};

enum class Operations {
    ADDITION = 1,
    SUBSTRACTION,
    MULTIPLICATION,
    DIVISION,
    SAVE,
    LOAD,
    PRINT,
    FILTER,
    EXIT = 0,
    UNDEFINED = -1
};

#endif