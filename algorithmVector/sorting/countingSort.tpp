#include <vector>
#include "stdint.h"
#include <map>
#include "countingSort.hpp"

// Counting sort for integers but memory consuming
template <typename Comparable>
std::vector<Comparable> CountingSort(std::vector<Comparable> &arr, bool reverse) {
    static_assert(!std::is_same<Comparable, float>::value, "You can't use floats here");
    static_assert(!std::is_same<Comparable, double>::value, "You can't use doubles here");
    Comparable upper = arr[0], lower = arr[0];
    for (size_t idx = 1; idx < arr.size(); idx++) {
        if (arr[idx] > upper) upper = arr[idx];
        if (arr[idx] < lower) lower = arr[idx];
    }

    Comparable space = upper - lower + 1;
    std::vector<Comparable> count(space, 0);
    for (Comparable e : arr) count[e - lower]++;    
    // k to indicate the current position in the original array
    size_t k = 0;
    // j from lower to upper for ascending order
    // count[j - lower] indicates how many the same elements we need
    // to put first
    if (!reverse) {
        for (Comparable j = lower; j <= upper; j++) {
            for (Comparable i = 0; i < count[j - lower]; i++) arr[k++] = j;
        }
    }
    else {
        for (Comparable j = upper; j >= lower; j--) {
            for (Comparable i = 0; i < count[j - lower]; i++) arr[k++] = j;
        }
    }
    return arr;
}

// Counting Sort with usage of map data structure to save memory but time consuming
// due to the insertion and tranvsering of the map.
template<typename Comparable>
std::vector<Comparable> CountingSort_(std::vector<Comparable>& array, bool reverse) {
    static_assert(!std::is_same<Comparable, float>::value, "You can't use floats here");
    static_assert(!std::is_same<Comparable, double>::value, "You can't use doubles here");
    std::map<Comparable, uint64_t> counts;
    for (size_t i = 0; i < array.size(); i++) counts[array[i]]++;    
    if (!reverse) {
        size_t k = 0;
        for (typename std::map<Comparable, uint64_t>::iterator it = counts.begin(); it != counts.end(); it++) {
            if (it->second > 0) {
                int count = it->second;
                for (int i = 0; i < count; i++) array[k++] = it->first;
            }
        }
    }
    else {
        size_t k = 0;
        for (typename std::map<Comparable, uint64_t>::reverse_iterator it = counts.rbegin(); it != counts.rend(); it++) {
            if (it->second > 0) {
                int count = it->second;
                for (int i = 0; i < count; i++) array[k++] = it->first;
            }
        }
    }      
    return array;
}