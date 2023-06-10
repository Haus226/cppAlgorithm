#pragma once

#include <vector>
#include <cstdint>
#include "mergeSort.hpp"
#include "insertionSort.hpp"

template<typename Comparable>
std::vector<Comparable> BucketSort(std::vector<Comparable> &arr, bool reverse=false);

// Hybrid between insertion sort and fatser merge sort
template<typename Comparable>
std::vector<Comparable> BucketSort_(std::vector<Comparable> &arr, bool reverse=false);

#include "bucketSort.tpp"
