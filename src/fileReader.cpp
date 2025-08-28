#include "fileReader.hpp"
#include <iostream>

void FileReader::readFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return;
    }

    std::string word;
    while (file >> word) 
    {
        sharedStack.push(word);
    }

    file.close();
}