#pragma once

#include <vector>
#include <algorithm>

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void BubbleSort(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void BubbleSort_(It begin, It end, Key&& cmp=Key());

template<typename It, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void CombSort(It begin, It end, Key&& cmp=Key());

#include "bubbleSort.tpp"
