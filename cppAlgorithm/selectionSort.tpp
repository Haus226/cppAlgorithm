#include <vector>
#include "func.hpp"
#include "selectionSort.hpp"


template<class Comparable>
std::vector<Comparable> SelectionSort(std::vector<Comparable> &arr, bool reverse) {
    for (long long i = 0; i < arr.size() - 1; ++i) {
        long long min = i;
        for(long long j = i + 1; j < arr.size(); ++j){
            if(arr[j] < arr[min] && (!reverse)) min = j;
            if(arr[j] > arr[min] && (reverse)) min = j;
        }
        std::swap(arr[i], arr[min]);
    }
    return arr;
}

template<class Comparable>
void down(std::vector<Comparable> &arr, long long start, long long end, const bool &reverse) {
    int child = 2 * start + 1;
    if (reverse){
        while (child < end) {
            // Compare with the largest children
            if (child + 1 < end && arr[child + 1] < arr[child]) child++;
            if (arr[child] >= arr[start]) break;
            std::swap(arr[start], arr[child]);
            // Compare iteratively downwards
            start = child;
            child = 2 * start + 1;
        }
    }
    else{
         while (child < end) {
            // Compare with the smallest children
            if (child + 1 < end && arr[child + 1] > arr[child]) child++;
            if (arr[child] <= arr[start]) break;
            std::swap(arr[start], arr[child]);
            // Compare iteratively downwards
            start = child;
            child = 2 * start + 1;
        }
    }
}

template<class Comparable>
std::vector<Comparable> HeapSort(std::vector<Comparable> &arr, bool reverse) {
    if (!reverse) {
        // Build the heap
        for(int i = arr.size() / 2 - 1; i >= 0; i--) down(arr, i, arr.size(), reverse);
        for(int j = arr.size() - 1; j > 0; j--){
            std::swap(arr[0], arr[j]);
            down(arr, 0, j, reverse);
        }
    }
    else{
        for(int i = arr.size() / 2 - 1; i >= 0; i--) down(arr, i, arr.size(), reverse);
        for(int j = arr.size() - 1; j > 0; j--){
            std::swap(arr[0], arr[j]);
            down(arr, 0, j, reverse);
        }
    }
    
    return arr;
}

template<class Comparable>
void down_(std::vector<Comparable> &arr, size_t size, long long idx, const bool &reverse) {
    long long larger = idx;
    long long left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < size && arr[left] > arr[larger]) larger = left;
    if (right < size && arr[right] > arr[larger]) larger = right;
    if (larger != idx) {
        std::swap(arr[idx], arr[larger]);
        down_(arr, size, larger, reverse);
    }
}

template<class Comparable>
std::vector<Comparable> HeapSort_(std::vector<Comparable> &arr, bool reverse) {
    for(int i = arr.size() / 2 - 1; i >= 0; i--) down_(arr, arr.size(), i, reverse);
    for(int j = arr.size() - 1; j > 0; j--){
        std::swap(arr[0], arr[j]);
        down_(arr, j, 0, reverse);
    }
    return arr;
}


