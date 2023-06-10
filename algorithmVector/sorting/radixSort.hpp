#pragma once
#include <vector>


// Plain radix sort
template <typename Comparable>
std::vector<Comparable> RadixSort(std::vector<Comparable> &arr, bool reverse);

// Counting sort used in Radix sort for integer
template <typename Comparable>
std::vector<Comparable> countingSort_(std::vector<Comparable> &arr, Comparable place);

template <typename Comparable>
std::vector<Comparable> RadixSort_(std::vector<Comparable> &arr, bool reverse);

double ll2d(long long val);

template <typename T>
std::vector<T> RadixSort_FLOAT(std::vector<T>& array, bool reverse);

template <typename T>
std::vector<T> RadixSort_INT(std::vector<T>& array, bool reverse);

#include "radixSort.tpp"