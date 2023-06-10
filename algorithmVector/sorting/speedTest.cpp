#include "bubbleSort.hpp"
#include "bucketSort.hpp"
#include "countingSort.hpp"
#include "elementSearch.hpp"
#include "insertionSort.hpp"
#include "selectionSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"
#include "radixSort.hpp"
#include "func.hpp"
#include <bits/stdc++.h>

template <typename F, typename ... Ts>
void timeit(F&& f, Ts&&...args) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto v = std::forward<F>(f)(std::forward<Ts>(args)...);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "\tisSorted : " << isSorted(v) << std::endl;
    std::cout << "\tstd::is_sorted : " << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << std::endl;
    std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;

}


template<typename T>
void run(std::vector<T> v) {
    std::vector<std::vector<T> (*) (std::vector<T>&, bool)> func = {
        HeapSort<T>, 
        HeapSort_<T>,
        MergeSort<T>, 
        MergeSort__<T>, 
        QuickSort<T>, 
        QuickSort__<T>,
        ShellSort<T>, 
        CombSort<T>, 
        CountingSort<T>, 
        BucketSort<T>, 
        BucketSort_<T>, 
        RadixSort<T>, 
        RadixSort_<T>, 
        RadixSort_INT<T>, 
        RadixSort_FLOAT<T>, 
        InsertionSort<T>, 
        SelectionSort<T>, 
        BubbleSort<T>, 
        BubbleSort_<T>
    };
    std::map<std::vector<T> (*) (std::vector<T>&, bool), std::string> func_names_map;
    std::vector<std::string> func_names = {
        "HeapSort", 
        "HeapSort_",
        "MergeSort", 
        "MergeSort_", 
        "QuickSort", 
        "QuickSort_", 
        "ShellSort", 
        "CombSort",
        "CountingSort", 
        "BucketSort", 
        "BucketSort_", 
        "RadixSort", 
        "RadixSort_", 
        "RadixSort_INT", 
        "RadixSort_FLOAT",
        "InsertionSort", 
        "SelectionSort", 
        "BubbleSort",
        "BubbleSort_"
    };
    for (size_t idx = 0; idx < func.size(); idx++) func_names_map[func[idx]] = func_names[idx];
    std::vector<std::vector<T>> v_(func.size(), v);
    for (size_t idx = 0; idx < func.size(); idx++) {
        std::cout << "Current : " << func_names_map[func[idx]] << std::endl;
        timeit(func[idx], v_[idx], 0);
        // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        // std::sort(v_[idx + 1].begin(), v_[idx + 1].end());
        // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::cout << "\tTime difference (std::sort) = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
        std::cout << "DONE " << func_names_map[func[idx]] << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(21);
    std::uniform_int_distribution<int64_t> randint(-10000000, 100000000);
    size_t size = 1000000;
    using T = int64_t;
    std::vector<T> v(size);
    for (size_t i = 0; i < size; i++) v[i] = randint(gen);
    run(v);


}

