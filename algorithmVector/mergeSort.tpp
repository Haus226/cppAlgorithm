#include <vector>
#include "mergeSort.hpp"

template<class Comparable>
void Merge(std::vector<Comparable> &arr, long long lo, long long mid, long long hi, bool reverse) {
    long long num1 = mid - lo + 1, num2 = hi - mid;
    std::vector<Comparable> l(num1), r(num2);
    for(long long i = 0; i < num1; i++){
        l[i] = arr[lo + i];
    }
    for (long long j = 0; j < num2; j++){
        r[j] = arr[mid + j + 1];
    }
    long long i = 0, j = 0, k = lo;
    if (!reverse){
        while (i < num1 && j < num2){
            arr[k++] = l[i] > r[j] ? r[j++] : l[i++];
            // if (l[i] > r[j]) arr[k++] = r[j++];
            // else arr[k++] = l[i++];
        }
    }
    else{
        while(i < num1 && j < num2){
            arr[k++] = l[i] < r[j] ? r[j++] : l[i++];
            // if (l[i] < r[j]) arr[k++] = r[j++];
            // else arr[k++] = l[i++];
        }
    }

    while (i < num1) arr[k++] = l[i++];
    while (j < num2) arr[k++] = r[j++];

    
}

template<class Comparable>
void MergeSort_(std::vector<Comparable> &arr, long long lo, long long hi, bool reverse) {
    if (lo < hi){
        long long mid = (lo + hi) / 2;
        MergeSort_(arr, lo, mid, reverse);
        MergeSort_(arr, mid + 1, hi, reverse);
        Merge(arr, lo, mid, hi, reverse);
    }
}

template<class Comparable>
std::vector<Comparable> MergeSort(std::vector<Comparable> &arr, bool reverse) {
    MergeSort_(arr, 0, arr.size() - 1, reverse);
    return arr;
}

// A little bit faster merge sort
template<class Comparable>
void Merge_(std::vector<Comparable> &arr, long long lo, long long mid, long long hi, bool reverse) {
    std::vector<Comparable> temp(hi - lo + 1);
    long long idx = 0, p1 = lo, p2 = mid + 1;
    if (!reverse) {
        while (p1 <= mid && p2 <= hi)
            temp[idx++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    else {
         while (p1 <= mid && p2 <= hi)
            temp[idx++] = arr[p1] > arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p2 <= hi) temp[idx++] = arr[p2++];
    while (p1 <= mid) temp[idx++] = arr[p1++];
    for (idx = 0; idx < temp.size(); idx++) arr[lo + idx] = temp[idx];
}

template<class Comparable>
void _MergeSort_(std::vector<Comparable> &arr, long long lo, long long hi, bool reverse) {
    if (lo < hi){
        long long mid = (lo + hi) / 2;
        _MergeSort_(arr, lo, mid, reverse);
        _MergeSort_(arr, mid + 1, hi, reverse);
        Merge_(arr, lo, mid, hi, reverse);
    }
}

template<class Comparable>
std::vector<Comparable> MergeSort__(std::vector<Comparable> &arr, bool reverse) {
    _MergeSort_(arr, 0, arr.size() - 1, reverse);
    return arr;
}