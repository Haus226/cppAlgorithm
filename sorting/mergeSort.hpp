#pragma once

#include <vector>

template<typename It, typename Key>
void Merge(It begin, It mid, It end, Key&& cmp);

template<typename It, typename Key>
void MergeSort_(It begin, It end, Key&& cmp);

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void MergeSort(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key>
void Merge_(It begin, It mid, It end, Key&& cmp);

template<typename It, typename Key>
void _MergeSort_(It begin, It end, Key&& cmp);

// A litte bit faster merge sort
template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void MergeSort__(It begin, It end, Key&& cmp=Key());

#include "mergeSort.tpp"
