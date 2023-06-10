#pragma once

#include <vector>

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void InsertionSort(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void ShellSort(It begin, It end, Key&& cmp=Key());
                     
#include "insertionSort.tpp"
