#pragma once

#include <vector>

template<typename It, typename Key>
It Partition(It begin, It end, Key&& cmp);

template<typename It, typename Key>
void QuickSort_(It begin, It end, Key&& cmp);

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void QuickSort(It begin, It end, Key&& cmp=Key());

// A little bit slower Quick Sort
template<typename It, typename Key>
It Partition_(It begin, It end, Key&& cmp);

template<typename It, typename Key>
void _QuickSort_(It begin, It end, Key&& cmp);

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void QuickSort__(It begin, It end, Key&& cmp=Key());

#include "quickSort.tpp"