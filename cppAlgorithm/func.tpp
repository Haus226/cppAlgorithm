#include "func.hpp"
#include <vector>
#include <iostream>

template<typename T>
void swap(T* x, T* y) {
    T temp = *x;
    *x = *y;
    *y = temp;
}

template<typename Comparable>
long long isSorted(const std::vector<Comparable> &arr, bool reverse) {
    if (!reverse) {
        for (long long idx = 0; idx < arr.size() - 1; idx++) {
            if (arr[idx] > arr[idx + 1]) return idx;
       }
    }
    else {
        for (long long idx = 0; idx < arr.size() - 1; idx++) {
            if (arr[idx] < arr[idx + 1]) return idx;
       }
    }
    return -1;
}

template<typename T>
void printArr(const std::vector<T> &arr) {
    for (const T &e : arr) std::cout << e << ", ";
    std::cout << std::endl;
}   
