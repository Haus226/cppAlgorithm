#include <vector>
#include <algorithm>
#include "insertionSort.hpp"

template<typename It, typename Key>
void InsertionSort(It begin, It end, Key&& cmp) {
    for (It it = begin + 1; it != end; ++it) {
        typename std::iterator_traits<It>::value_type temp = *it;
        It jt = it - 1;
        // Compare key with each element on the left of it until an element smaller than
        // it is found or it is being move to the first position of the vector
        while (jt >= begin && cmp(temp, *jt)) {
            *(jt + 1) = *jt;
            jt--;
        }
        *(jt + 1) = temp;
    }
}

template<typename It, typename Key>
void ShellSort(It begin, It end, Key&& cmp) {
    for (long long interval = (end - begin) / 2; interval > 0; interval /= 2) {
        for (It it = begin + interval; it < end; ++it) {
            typename std::iterator_traits<It>::value_type temp = *it;
            It jt = it;
            while (jt >= begin + interval && cmp(temp, *(jt - interval))) {
                *jt = *(jt - interval);
                jt -= interval;
            }
            *jt = temp;
        }
    }
}
