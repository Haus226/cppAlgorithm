#pragma once

#include <vector>

template<class Comparable>
long long Partition(std::vector<Comparable> &arr, long long start, long long end, bool reverse=false);

template<class Comparable>
void QuickSort_(std::vector<Comparable> &arr, long long start, long long end, bool reverse=false);

template<class Comparable>
std::vector<Comparable> QuickSort(std::vector<Comparable> &arr, bool reverse=false);
template<class Comparable>
long long Partition_(std::vector<Comparable> &arr, long long start, long long end, bool reverse=false);

template<class Comparable>
void _QuickSort_(std::vector<Comparable> &arr, long long start, long long end, bool reverse=false);

template<class Comparable>
std::vector<Comparable> QuickSort__(std::vector<Comparable> &arr, bool reverse=false);

#include "quickSort.tpp"