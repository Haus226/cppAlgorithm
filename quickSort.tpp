#include <vector>
#include <algorithm>
#include "quickSort.hpp"

template<typename It, typename Key>
It Partition(It begin, It end, Key&& cmp) {
    It pivot = end;
    // Pointer for greater element
    It it = begin - 1;
    // Traverse each element of the array
    // compare them with the pivot
    for (It jt = begin; jt < end; jt++) {
        if (cmp(*jt, *pivot)) {
            // cout << "Here" << endl;
            // If element smaller than pivot is found
            // swap it with the greater element pointed by it
            it++;
            // Swap element at i with element at j
            std::iter_swap(it, jt);
        }
    }
    // Place the pivot at the correction position
    std::iter_swap(it + 1, end);
    return it + 1;
}

template<typename It, typename Key>
void QuickSort_(It begin, It end, Key&& cmp) {
    if (begin < end){
        It mid = Partition(begin, end, cmp);
        // cout << "Mid : " << (*mid).first << endl;
        QuickSort_(begin, mid - 1, cmp);
        QuickSort_(mid + 1, end, cmp);
    }
}

template<typename It, typename Key>
void QuickSort(It begin, It end, Key&& cmp) { 
    QuickSort_(begin, end - 1, cmp); 
}

template<typename It, typename Key>
It Partition_(It begin, It end, Key&& cmp) {
    It it = begin, jt = end + 1;
    It pivot = begin;
    // long long i = start, j = end + 1;
    // Comparable pivot = arr[start];
   
    while (true) {
        // Find the elements that larger than pivot
        while (cmp(*(++it), *pivot)) if (it == end) break;
        // Find the elements that smaller than pivot
        while (cmp(*pivot, *(--jt))) if (jt == begin) break;
        if (it >= jt) break;
        // Swap them so that smaller elements are at the LHS of the pivot
        // while the larger elements are at the RHS of the pivot
        std::iter_swap(jt, it);
    }
    // Swap the pivot to the correct position
    std::iter_swap(jt, begin);
    return jt;
}

template<typename It, typename Key>
void _QuickSort_(It begin, It end, Key&& cmp) {
    if (begin < end){
        It mid = Partition_(begin, end, cmp);
        _QuickSort_(begin, mid - 1, cmp);
        _QuickSort_(mid + 1, end, cmp);
    }
}

template<typename It, typename Key>
void QuickSort__(It begin, It end, Key&& cmp) {
    _QuickSort_(begin, end - 1, cmp);
}
