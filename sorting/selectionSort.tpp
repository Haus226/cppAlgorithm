#include <vector>
#include <algorithm>
#include "selectionSort.hpp"
#include <iostream>

template<typename It, typename Key>
void SelectionSort(It begin, It end, Key&& cmp) {
    for (It it = begin; it < end - 1; ++it) {
        It min = it;
        for (It jt = it + 1; jt < end; ++jt) if (cmp(*jt, *min)) min = jt;
        std::iter_swap(it, min);
    }
}

template<typename It, typename Key>
void down(It begin, It idx, It end, Key&& cmp) {
    It child = begin + (2 * (idx - begin) + 1);
    while (child < end) {
        // Compare with the largest children
        if (child + 1 < end && (!cmp(*(child + 1), *child))) child++;
        if (cmp(*child, *idx)) break;
        std::iter_swap(idx, child);
        // Compare iteratively downwards
        idx = child;
        child = begin + (2 * (idx - begin)) + 1;
    }
    
}

template<typename It, typename Key>
void HeapSort(It begin, It end, Key&& cmp) {
    // Build the heap
    for (It it = begin + ((end - begin) / 2) - 1; it >= begin; it--) down(begin, it, end, cmp);
    for (It it = end - 1; it > begin; it--) {
        std::iter_swap(begin, it);
        down(begin, begin, it, cmp);
    }
}

template<typename It, typename Key>
void down_(It begin, It idx, It end, Key&& cmp) {
    It jdx = idx;
    It leftChild = begin + (2 * (idx - begin) + 1);
    It rightChild = begin + (2 * (idx - begin) + 2);
    if (leftChild < end && (cmp(*jdx, *leftChild))) jdx = leftChild;
    if (rightChild < end && (cmp(*jdx, *rightChild))) jdx = rightChild;
    if (jdx != idx) {
        std::iter_swap(idx, jdx);
        down_(begin, jdx, end, cmp);
    }
}

template<typename It, typename Key>
void HeapSort_(It begin, It end, Key&& cmp) {
    for (It it = begin + ((end - begin) / 2) - 1; it >= begin; it--) down_(begin, it, end, cmp);
    for (It it = end - 1; it > begin; it--) {
        std::iter_swap(begin, it);
        down_(begin, begin, it, cmp);
    }
}
