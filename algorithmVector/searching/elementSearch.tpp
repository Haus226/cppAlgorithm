
#include <vector>
#include <algorithm>
#include "elementSearch.hpp"
#include <cstdint>

// No constraint for the array
template<typename Comparable>
long long LinearSearch(const std::vector<Comparable> &arr, const Comparable &data) {
    for (size_t idx = 0; idx < arr.size(); idx++) {
        if (arr[idx] == data) return idx;
    }
    return -1;
}

// The array must be sorted
template<typename Comparable>
long long BinarySearch(const std::vector<Comparable> &arr, const Comparable &data, size_t start, size_t end) {
    if (!end) end = arr.size();
    size_t mid = start + (end - start) / 2;
    if ((end - start + 1 <= 0) || mid == end) return -1;
    else {
        Comparable t = arr[mid];
        if (t == data) return mid;
        if (t > data) return BinarySearch(arr, data, start, mid);
        else return BinarySearch(arr, data, mid + 1, end);
    }
}

// The array must be sorted
template<typename Comparable>
long long JumpSearch(const std::vector<Comparable> &arr, const Comparable &data) {
    uint64_t step = sqrt(arr.size());
    size_t prev = 0;
    // To prevent seacrhing exceeds the array size
    while (arr[std::min(step, arr.size() - 1)] < data) {
        prev = step;
        step += step;
        // If the previous block exceeds the boundary then the element does not exist
        if (prev >= arr.size()) return -1;
    }
    // Jump back to the previous block and perform linear search
    while (arr[prev] < data) {
        prev++;
        // The boundary of this linear search is step or arr.size()
        if (prev == std::min(step, arr.size())) return -1;
    }
    if (arr[prev] == data) return prev;
    return -1;
}