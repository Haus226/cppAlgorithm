#include <vector>
#include "insertionSort.hpp"



template<class Comparable>
std::vector<Comparable> InsertionSort(std::vector<Comparable> &arr, bool reverse) {
    for (long long i = 1; i < arr.size(); ++i) {
        Comparable temp = arr[i];
        long long j = i - 1;
        if (!reverse) {
            // Compare key with each element on the left of it until an element smaller than
            // it is found or it is being move to the first position of the vector
            while(j >= 0 && arr[j] > temp){
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else {
            while(j >= 0 && arr[j] < temp){
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = temp;
    }
    return arr;
}

template<class Comparable>
std::vector<Comparable> ShellSort(std::vector<Comparable> &arr, bool reverse) {
    for (long long interval = arr.size() / 2; interval > 0; interval /= 2){
        for (long long i = interval; i < arr.size(); ++i) {
            Comparable temp = arr[i];
            long long j = i;
            if (!reverse) {
                // Compare key with each element on the left of it until an element smaller than
                // it is found.
                while(j >= interval && arr[j - interval] > temp){
                    arr[j] = arr[j - interval];
                    j -= interval;
                }
            }
            else {
                while(j >= interval && arr[j - interval] < temp){
                    arr[j] = arr[j - interval];
                    j -= interval;
                }
            }
            arr[j] = temp;
        }
    }
    return arr;
}
