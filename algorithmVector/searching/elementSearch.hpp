#pragma once

#include <vector>

template<typename Comparable>
long long LinearSearch(const std::vector<Comparable> &arr, const Comparable &data);

template<typename Comparable>
long long BinarySearch(const std::vector<Comparable> &arr, const Comparable &data, 
                       size_t start = 0, size_t end = nullptr);


template<typename Comparable>
long long JumpSearch(const std::vector<Comparable> &arr, const Comparable &data);

#include "elementSearch.tpp"
