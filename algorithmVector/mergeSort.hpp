#pragma once

#include <vector>


template<class Comparable>
void Merge(std::vector<Comparable> &arr, long long lo, long long mid, long long hi, bool reverse=false);

template<class Comparable>
void MergeSort_(std::vector<Comparable> &arr, long long lo, long long hi, bool reverse=false);


template<class Comparable>
std::vector<Comparable> MergeSort(std::vector<Comparable> &arr, bool reverse=false);
 
// A bit faster merger sort
template<class Comparable>
void Merge_(std::vector<Comparable> &arr, long long lo, long long mid, long long hi, bool reverse=false);

template<class Comparable>
void _MergeSort_(std::vector<Comparable> &arr, long long lo, long long hi, bool reverse=false);

template<class Comparable>
std::vector<Comparable> MergeSort__(std::vector<Comparable> &arr, bool reverse=false);

#include "mergeSort.tpp"