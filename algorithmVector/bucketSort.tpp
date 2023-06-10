#include <vector>
#include <cstdint>
#include "bucketSort.hpp"
#include <cmath>

// Bucket Sort with slower Merge Sort
template<typename Comparable>
std::vector<Comparable> BucketSort(std::vector<Comparable> &arr, bool reverse) {
    uint64_t bucketSize = floor(sqrt(arr.size()));
    if (arr.empty()) {
        return arr;
    }

    // Find minimum and maximum values
    Comparable minVal = arr[0], maxVal = arr[0];
    for (Comparable &element : arr) {
        if (element < minVal) minVal = element;
        else if (element > maxVal) maxVal = element;
    }

    // Compute number of buckets and bucket range
    const uint64_t bucketCount = (maxVal - minVal) / bucketSize + 1;
    const uint64_t bucketRange = (maxVal - minVal) / bucketCount + 1;

    // Initialize buckets
    std::vector<std::vector<Comparable>> buckets(bucketCount);

    // Distribute input array elements into buckets
    for (Comparable &element : arr) {
        uint64_t bucketIndex = (element - minVal) / bucketRange;
        buckets[bucketIndex].push_back(element);
    }

    // Sort individual buckets using insertion sort or merge sort
    int threshold = 0;
    if (arr.size() <= 1000) threshold = 10;
    else threshold = static_cast<int>(std::sqrt(arr.size()));

    for (std::vector<Comparable> &bucket : buckets) {
        if (bucket.size() < threshold) InsertionSort(bucket, reverse);
        else MergeSort(bucket, reverse);
        
    }
    // Concatenate sorted buckets
    size_t index = 0;
    if (!reverse) {
        for (std::vector<Comparable> &bucket : buckets) {
            for (Comparable  &element : bucket) arr[index++] = element;

        }
    }
    else {
        for (long long idx = buckets.size() - 1; idx >= 0; idx--) {
            for (Comparable &element : buckets[idx]) arr[index++] = element;
        }
    }
    return arr;
}

// Bucket Sort with faster Merge Sort
template<typename Comparable>
std::vector<Comparable> BucketSort_(std::vector<Comparable> &arr, bool reverse) {
    uint64_t bucketSize = floor(sqrt(arr.size()));
    if (arr.empty()) {
        return arr;
    }

    // Find minimum and maximum values
    Comparable minVal = arr[0], maxVal = arr[0];
    for (Comparable &element : arr) {
        if (element < minVal) minVal = element;
        else if (element > maxVal) maxVal = element;
    }

    // Compute number of buckets and bucket range
    const uint64_t bucketCount = (maxVal - minVal) / bucketSize + 1;
    const uint64_t bucketRange = (maxVal - minVal) / bucketCount + 1;

    // Initialize buckets
    std::vector<std::vector<Comparable>> buckets(bucketCount);

    // Distribute input array elements into buckets
    for (Comparable &element : arr) {
//        if (-1e20 < element < 1e-20) buckets[0].push_back(element);
//        else {
        uint64_t bucketIndex = (element - minVal) / bucketRange;
        buckets[bucketIndex].push_back(element);
    }

    // Sort individual buckets using insertion sort or merge sort
    int threshold = 0;
    if (arr.size() <= 1000) threshold = 10;
    else threshold = static_cast<int>(std::sqrt(arr.size()));

    for (std::vector<Comparable> &bucket : buckets) {
        if (bucket.size() < threshold) InsertionSort(bucket, reverse);
        else MergeSort__(bucket, reverse);
        
    }
    // Concatenate sorted buckets
    size_t index = 0;
    if (!reverse) {
        for (std::vector<Comparable> &bucket : buckets) {
            for (Comparable  &element : bucket) arr[index++] = element;

        }
    }
    else {
        for (long long idx = buckets.size() - 1; idx >= 0; idx--) {
            for (Comparable &element : buckets[idx]) arr[index++] = element;
        }
    }
    return arr;
}