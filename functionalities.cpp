#include "functionalities.h"

void Functionalities::saveMatrixToTxt(std::vector<NumberInfo>& storage)
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
        std::cerr << "The file could,t be loaded."<< std::endl;
        return history;
    }

    int index;
    float value;
    bool even;
    std::string operation;

    while (inFile >> index >> value >> even >> operation) {
        NumberInfo entry;
        entry.index = index;
        entry.value = value;
        entry.even = even;
        entry.operation = operation;
        history.push_back(entry);
    }

    return history;

}
