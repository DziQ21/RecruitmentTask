
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
  
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }
    unsigned int cpu_count = std::thread::hardware_concurrency();

    std::cout << "CPU count: " << cpu_count << std::endl;
    std::string file{argv[1]};

    return 0;
}