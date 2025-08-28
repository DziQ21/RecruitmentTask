#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>

class SharedStack {
private:
    std::queue<std::string> data;
    std::mutex mtx;
    std::condition_variable cv;
public:
    void push(const std::string& word);
    std::string pop();
};