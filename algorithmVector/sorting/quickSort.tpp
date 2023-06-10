#include <vector>
#include "func.hpp"
#include "quickSort.hpp"


template<class Comparable>
long long Partition(std::vector<Comparable> &arr, long long start, long long end, bool reverse) {
    Comparable pivot = arr[end];
    // Pointer for greater element
    long long i = (start - 1);
    // Traverse each element of the array
    // compare them with the pivot
    if(!reverse) {
        for (long long j = start; j < end; j++) {
            if (arr[j] <= pivot) {
                // If element smaller than pivot is found
                // swap it with the greater element pointed by i
                i++;
                // Swap element at i with element at j
                std::swap(arr[i], arr[j]);
            }    
        }
    }
    else {
        for (long long j = start; j < end; j++) {
            if (arr[j] >= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }    
        }
    }
    // Place the pivot at the correction position
    std::swap(arr[i + 1], arr[end]);
    return (i + 1);
}

template<class Comparable>
void QuickSort_(std::vector<Comparable> &arr, long long start, long long end, bool reverse) {
    if (start < end){
        long long mid = Partition(arr, start, end, reverse);
        QuickSort_(arr, start, mid - 1, reverse);
        QuickSort_(arr, mid + 1, end, reverse);
    }
}

template<class Comparable>
std::vector<Comparable> QuickSort(std::vector<Comparable> &arr, bool reverse){
    QuickSort_(arr, 0, arr.size() - 1, reverse);
    return arr;
}


template<class Comparable>
long long Partition_(std::vector<Comparable> &arr, long long start, long long end, bool reverse) {

    long long i = start, j = end + 1;
    Comparable pivot = arr[start];
    if (!reverse) {
        while (true) {
            // Find the elements that larger than pivot
            while (arr[++i] < pivot) if(i == end) break;
            // Find the elements that smaller than pivot
            while (pivot < arr[--j]) if(j == start) break;
            if (i >= j) break;
            // Swap them so that smaller elements are at the LHS of the pivot
            // while the larger elements are at the RHS of the pivot
            std::swap(arr[i], arr[j]);

        }
        // Swap the pivot to the correct positoin
        std::swap(arr[j], arr[start]);
        return j;
    }
    else {
         while (true) {
            while (arr[++i] > pivot) if(i == end) break;
            while (pivot > arr[--j]) if(j == start) break;
            if (i >= j) break;
            std::swap(arr[i], arr[j]);

        }
        std::swap(arr[j], arr[start]);
        return j;
    }
}

template<class Comparable>
void _QuickSort_(std::vector<Comparable> &arr, long long start, long long end, bool reverse) {
    if (start < end){
        long long mid = Partition_(arr, start, end, reverse);
        _QuickSort_(arr, start, mid - 1, reverse);
        _QuickSort_(arr, mid + 1, end, reverse);
    }
}

template<class Comparable>
std::vector<Comparable> QuickSort__(std::vector<Comparable> &arr, bool reverse) {
    _QuickSort_(arr, 0, arr.size() - 1, reverse);
    return arr;
}
