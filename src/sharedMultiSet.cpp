#include "sharedMultiSet.hpp"

void SharedMultiSet::insert(const std::string& value) 
{
    size_t idx = bucketIndex(value);
    std::lock_guard<std::mutex> lock(buckets[idx].mtx);
    buckets[idx].s.insert(value);
}

size_t SharedMultiSet::bucketIndex(const std::string& value) const
{
    size_t numBuckets = buckets.size();
    size_t n = 1;
    size_t pow = 26;
    while (pow < numBuckets) {
        ++n;
        pow *= 26;
    }

    size_t hash = 0;
    for (size_t i = 0; i < value.size() && i < n; ++i) {
        char c = value[i];
        hash = hash * 26 + (c - 'a'); 
    }

    return hash % numBuckets;
}

void SharedMultiSet::insert(std::string&& value)
{
    size_t idx = bucketIndex(value);
    std::lock_guard<std::mutex> lock(buckets[idx].mtx);
    buckets[idx].s.insert(std::move(value));
}