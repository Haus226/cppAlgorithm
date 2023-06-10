#pragma once
#include <vector>

// Self-defined swap function
template<typename T>
void swap(T* x, T* y);

// Some useful function during testing
template<typename Comparable>
long long isSorted(const std::vector<Comparable> &arr, bool reverse=false);
template<typename T>
void printArr(const std::vector<T> &arr);

#include "func.tpp"