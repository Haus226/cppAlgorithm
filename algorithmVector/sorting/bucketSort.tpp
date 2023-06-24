#include <vector>
#include <cstdint>
#include "bucketSort.hpp"
#include <cmath>
#include <iostream>

// Bucket Sort with slower Merge Sort
template<typename Comparable>
std::vector<Comparable> BucketSort(std::vector<Comparable> &arr, bool reverse) {
    // uint64_t bucketSize = floor(sqrt(arr.size()));
    if (arr.empty()) {
        return arr;
    }

    // Find minimum and maximum values
    Comparable minVal = arr[0], maxVal = arr[0];
    for (Comparable &element : arr) {
        if (element < minVal) minVal = element;
        else if (element > maxVal) maxVal = element;
    }

    const uint64_t bucketCount = floor(sqrt(arr.size()));
    const uint64_t bucketSize = (maxVal - minVal + bucketCount) / bucketCount;

    // Initialize buckets
    std::vector<std::vector<Comparable>> buckets(bucketCount);

    // Distribute input array elements into buckets
    for (Comparable &element : arr) {
        // (element - minVal) calculates the relative position of the element within the range.
        // divide the relative position by the bucket range to determine the index of the corresponding bucket.
        uint64_t bucketIndex = (element - minVal) / bucketSize;
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

    // for (auto b : buckets) std::cout << b.size() << std::endl;
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
    // uint64_t bucketSize = floor(sqrt(arr.size()));
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
    const uint64_t bucketCount = floor(sqrt(arr.size()));
    const uint64_t bucketSize = (maxVal - minVal + bucketCount) / bucketCount;

    // Initialize buckets
    std::vector<std::vector<Comparable>> buckets(bucketCount);

    // Distribute input array elements into buckets
    for (Comparable &element : arr) {
//        if (-1e20 < element < 1e-20) buckets[0].push_back(element);
//        else {
        uint64_t bucketIndex = (element - minVal) / bucketSize;
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