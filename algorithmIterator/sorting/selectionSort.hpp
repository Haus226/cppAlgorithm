#pragma once

#include <vector>

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void SelectionSort(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key>
void down(It begin, It idx, It end, Key&& cmp);

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void HeapSort(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key>
void down_(It begin, It idx, It end, Key&& cmp);

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void HeapSort_(It begin, It end, Key&& cmp=Key());

#include "selectionSort.tpp"
