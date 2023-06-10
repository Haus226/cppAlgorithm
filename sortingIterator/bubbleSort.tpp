#include <vector>
#include "bubbleSort.hpp"
#include <algorithm>


template<typename It, typename Key>
void BubbleSort(It begin, It end, Key&& cmp) {
    for (It it = begin; it < end; ++it) {
        for(It jt = begin; jt < it; ++jt){
            if(cmp(*it, *jt)) std::iter_swap(jt, it);
        }
    }
}

template<typename It, typename Key>
void BubbleSort_(It begin, It end, Key&& cmp) {
    bool swapped = true;
    for (It it = begin; it < end && (swapped); ++it) {
        swapped = false;
        for(It jt = begin; jt - begin < end - it - 1; ++jt){
            if(cmp(*(jt + 1), *jt)) {
                std::iter_swap(jt, jt + 1);
                swapped = true;
            }
        }
    }
}

template<typename It, typename Key>
void CombSort(It begin, It end, Key&& cmp) {
    std::size_t gap = end - begin;
    bool swapped = false;
    while (gap > 1 || swapped == true)
    {
        // Shrink the gap 
        if (gap > 1) gap /= 1.3;
        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false; 
        // Compare all elements with current gap
        for (It it = begin; it < end - gap; it++) {
            if (cmp(*(it + gap), *it))
            {
                std::iter_swap(it, it + gap);
                swapped = true;
            }
        }
    }
}
