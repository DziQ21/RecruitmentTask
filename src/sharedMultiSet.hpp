#include <set>
#include <vector>
#include <mutex>
#include <string>


class SharedMultiSet {
    struct Bucket {
        std::set<std::string> s;
        std::mutex mtx;
    };

    std::vector<Bucket> buckets;

    size_t bucketIndex(const std::string& value) const;

public:
    explicit SharedMultiSet(size_t n) : buckets(n) {}
    void insert(std::string&& value);
    void insert(const std::string& value);
};