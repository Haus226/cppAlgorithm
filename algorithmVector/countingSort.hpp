#pragma once

#include <vector>
#include "stdint.h"

template <typename Comparable>
std::vector<Comparable> CountingSort(std::vector<Comparable> &arr, bool reverse=false);

// Counting Sort with usage of map data structure to save memory but time consuming
// due to the insertion and tranvsering of the map.
template <typename Comparable>
std::vector<Comparable> CountingSort_(std::vector<Comparable> &arr, bool reverse=false);

#include "countingSort.tpp"
