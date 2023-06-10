#pragma once

#include <vector>

template<class Comparable>
std::vector<Comparable> InsertionSort(std::vector<Comparable> &arr, bool reverse=false);

template<class Comparable>
std::vector<Comparable> ShellSort(std::vector<Comparable> &arr, bool reverse=false);
                     
#include "insertionSort.tpp"