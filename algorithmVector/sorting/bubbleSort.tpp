#include <vector>
#include "func.hpp"
#include "bubbleSort.hpp"


template<class Comparable>
std::vector<Comparable> BubbleSort(std::vector<Comparable> &arr, bool reverse) {
    for (long long i = 0; i < arr.size(); ++i) {
        // Faster bubble sort
        for (long long j = 0; j < i; ++j) {
            if (arr[i] < arr[j] && (!reverse)) std::swap(arr[i], arr[j]);
            if(arr[i] > arr[j] && (reverse)) std::swap(arr[j], arr[i]); 

        }
        // Slower bubble sort
        // for(long long j = 0; j < arr.size() - i - 1; ++j){
        //     if(arr[j + 1] < arr[j] && (!reverse)) swap(&arr[j + 1], &arr[j]);
        //     if(arr[j + 1] > arr[j] && (reverse)) swap(&arr[j], &arr[j + 1]); 
        // }
    }
    return arr;
}

template<class Comparable>
std::vector<Comparable> BubbleSort_(std::vector<Comparable> &arr, bool reverse) {
    bool swapped = true;
    for (long long i = 0; i < arr.size() - 1 && (swapped); ++i) {
        swapped = false;
        for(long long j = 0; j < arr.size() - i - 1; ++j){
            if(arr[j + 1] < arr[j] && (!reverse)) {
                std::swap(arr[j + 1], arr[j]);
                swapped = true;
            }
            if(arr[j + 1] > arr[j] && (reverse)) {
                std::swap(arr[j], arr[j + 1]); 
                swapped = true;
            }
        }
    }
    return arr;
}

template<class Comparable>
std::vector<Comparable> CombSort(std::vector<Comparable> &arr, bool reverse) {
    long long gap = arr.size();
    bool swapped = false;
    while (gap > 1 || swapped == true)
    {
        // Shrink the gap 
        if (gap > 1) gap /= 1.3;
        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false; 
        if (!reverse) {  
        // Compare all elements with current gap
            for (long long idx = 0; idx < arr.size() - gap; ++idx)
            {
                if (arr[idx] > arr[idx + gap])
                {
                    std::swap(arr[idx], arr[idx + gap]);
                    swapped = true;
                }
            }
        }
        else {
             for (long long idx = 0; idx < arr.size() - gap; ++idx)
            {
                if (arr[idx] < arr[idx + gap])
                {
                    std::swap(arr[idx], arr[idx + gap]);
                    swapped = true;
                }
            }
        }
    }
    return arr;
}