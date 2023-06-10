#include <vector>
#include <algorithm>
#include "mergeSort.hpp"

template<typename It, typename Key>
void Merge(It begin, It mid, It end, Key&& cmp) {
    // It num1 = mid - begin + 1, num2 = end - mid;
    std::vector<typename std::iterator_traits<It>::value_type> l(begin, mid + 1);
    std::vector<typename std::iterator_traits<It>::value_type> r(mid + 1, end + 1);
    It it = l.begin(), jt = r.begin(), kt = begin;
    while (it < l.end() && jt < r.end()) {
        *(kt++) = cmp(*jt, *it) ? *(jt++) : *(it++); 
    }
    while (it < l.end()) *(kt++) = *(it++);
    while (jt < r.end()) *(kt++) = *(jt++);
}

template<typename It, typename Key>
void MergeSort_(It begin, It end, Key&& cmp) {
    if (begin < end) {
        It mid = begin + ((end - begin) / 2);
        MergeSort_(begin, mid, cmp);
        MergeSort_(mid + 1, end, cmp);
        Merge(begin, mid, end, cmp);
    }

}

template<typename It, typename Key>
void MergeSort(It begin, It end, Key&& cmp) {
    MergeSort_(begin, end - 1, cmp);
}


// A little bit faster merge sort
template<typename It, typename Key>
void Merge_(It begin, It mid, It end, Key&& cmp) {
    std::vector<typename std::iterator_traits<It>::value_type> temp(end - begin + 1);
    It it = temp.begin(), p1 = begin, p2 = mid + 1;
    while (p1 <= mid && p2 <= end) *(it++) = cmp(*p1, *p2) ? *(p1++) : *(p2++);
    while (p2 <= end) *(it++) = *(p2++);
    while (p1 <= mid) *(it++) = *(p1++);
    It kt = temp.begin();
    for (It jt = begin; jt <= end; jt++) *jt = *(kt++);
    // std::copy(temp.begin(), temp.end(), begin);
}

template<typename It, typename Key>
void _MergeSort_(It begin, It end, Key&& cmp) {
    if (begin < end){
        It mid = begin + ((end - begin) / 2);
        // long long mid = (lo + hi) / 2;
        _MergeSort_(begin, mid, cmp);
        _MergeSort_(mid + 1, end, cmp);
        Merge_(begin, mid, end, cmp);
    }
}

template<typename It, typename Key>
void MergeSort__(It begin, It end, Key&& cmp) {
    _MergeSort_(begin, end - 1, cmp);
}

