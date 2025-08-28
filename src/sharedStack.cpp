#include "sharedStack.hpp"

void SharedStack::push(const std::string& word) 
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        data.push(word);
    }
    cv.notify_one();
}

std::string SharedStack::pop() 
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !data.empty(); });
    std::string word = std::move(data.front());
    data.pop();
    return word; 
}

