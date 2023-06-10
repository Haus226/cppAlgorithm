#pragma once

#include <vector>

template<class Comparable>
std::vector<Comparable> BubbleSort(std::vector<Comparable> &arr, bool reverse=false);

template<class Comparable>
std::vector<Comparable> BubbleSort_(std::vector<Comparable> &arr, bool reverse=false);


template<class Comparable>
std::vector<Comparable> CombSort(std::vector<Comparable> &arr, bool reverse=false);

#include "bubbleSort.tpp"
