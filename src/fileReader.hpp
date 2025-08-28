#include <string>
#include <fstream>
#include "sharedStack.hpp"

class FileReader {
public:
    FileReader(SharedStack& sharedStack) : sharedStack(sharedStack) {};
    ~FileReader() = default;

    void readFile(const std::string &filePath);
    

private:
    SharedStack &sharedStack;
    std::ifstream file;
};