
#include <vector>
#include <algorithm>
#include "elementSearch.hpp"
#include <cstdint>

// No constraint for the iterator
template<typename It, typename T, typename Key=std::less<T>>
It LinearSearch(It begin, It end, T&& key, Key&& cmp=Key())  {
    It it = begin;
    for (; it != end; ++it) {
        if (cmp(*it, key)) return it;
    }
    return it;
}

// The iterator must be sorted and be careful of EqualKey, CompareKey
template<typename It, typename T, typename EqualKey=std::equal_to<T>, typename CompareKey=std::less<T>>
It BinarySearch(It begin, It end, T&& key, EqualKey&& equal=EqualKey(), CompareKey&& cmp=CompareKey()) {
    It low = begin, high = end - 1;
    while (low <= high) {
        It mid = low + (high - low) / 2;
        if (equal(key, *mid)) return mid;
        else if (!cmp(key, *mid)) low = mid + 1;
        else high = mid - 1;
    }
    return end;
}

// The iterator must be sorted and be careful of EqualKey, CompareKey
template<typename It, typename T, typename EqualKey=std::equal_to<T>, typename CompareKey=std::less<T>>
It JumpSearch(It begin, It end, T&& key, EqualKey&& equal=EqualKey(), CompareKey&& cmp=CompareKey()) {
    uint64_t step = sqrt(end - begin);
    It prev = begin, current = begin + step;
    // Prevent searching exceed the boundary
    while (current < end && (!cmp(key, *current))) {
        prev = current;
        current += step;
    }
    // Linear search in the range we found
    while (prev < std::min(current, end)) {
        if (equal(key, *prev)) return prev;
        prev++;
    }
    return end;
}