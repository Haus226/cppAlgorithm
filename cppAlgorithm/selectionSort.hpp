#pragma once

#include <vector>

template<class Comparable>
std::vector<Comparable> SelectionSort(std::vector<Comparable> &arr, bool reverse=false);

template<class Comparable>
void down(std::vector<Comparable> &arr, long long start, long long end, const bool &reverse);


template<class Comparable>
std::vector<Comparable> HeapSort(std::vector<Comparable> &arr, bool reverse=false);

#include "selectionSort.tpp"