#include "bubbleSort.hpp"
#include "insertionSort.hpp"
#include "selectionSort.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"
#include <bits/stdc++.h>

template <typename F, typename It, typename Cmp>
void timeit(F f, It begin, It end, Cmp cmp) {
    std::chrono::steady_clock::time_point begin_ = std::chrono::steady_clock::now();
    f(begin, end, std::forward<Cmp>(cmp));
    std::chrono::steady_clock::time_point end_ = std::chrono::steady_clock::now();
    std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end_ - begin_).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << std::endl;
    std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end_ - begin_).count() << "[ms]" << std::endl;
}

template<typename It, typename T, typename Key=std::less<typename std::iterator_traits<It>::value_type>>
void run(It begin, It end, std::vector<T> &v, Key&& cmp=Key()) {
    std::vector<void (*) (It begin, It end, Key&& cmp)> func = {
        HeapSort,
        HeapSort_,
        MergeSort,
        MergeSort__, 
        QuickSort, 
        QuickSort__,
        ShellSort, 
        CombSort, 
        InsertionSort, 
        SelectionSort, 
        BubbleSort, 
        BubbleSort_
    };
    std::map<void (*) (It begin, It end, Key&& cmp), std::string> func_names_map;
    std::vector<std::string> func_names = {
        "HeapSort", 
        "HeapSort_",
        "MergeSort", 
        "MergeSort_", 
        "QuickSort", 
        "QuickSort_", 
        "ShellSort", 
        "CombSort",
        "InsertionSort", 
        "SelectionSort", 
        "BubbleSort",
        "BubbleSort_"
    };
    for (size_t idx = 0; idx < func.size(); idx++) func_names_map[func[idx]] = func_names[idx];
    std::vector<std::vector<T>> v_(func.size(), v);
    for (size_t idx = 0; idx < func.size(); idx ++) {
        std::cout << "Current : " << func_names_map[func[idx]] << std::endl;
        timeit(func[idx], v_[idx].begin(), v_[idx].end(), cmp);
        std::cout << "\tstd::is_sorted : " << std::is_sorted(v_[idx].begin(), v_[idx].end(), cmp) << std::endl;
        // for (T e : v_[idx]) std::cout << e << " ";
        // std::cout << std::endl;
        std::cout << "DONE " << func_names_map[func[idx]] << std::endl;
        std::cout << std::endl;
    }
}

    

int main() {
    std::random_device rd;
    std::mt19937 gen(21);
    std::uniform_int_distribution<int64_t> randint(-10000000, 100000000);
    size_t size = 10000000;
    using T = int64_t;
    std::vector<T> v(size);
    for (size_t i = 0; i < size; i++) v[i] = randint(gen);

    run(v.begin(), v.end(), v);



    // Before figure out the correct way to wrap with timeit function...

    // int cnt = 0;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // // HeapSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // HeapSort(v_[cnt].begin(), v_[cnt].end());
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;

    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // MergeSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // MergeSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // MergeSort__(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // MergeSort__(v_[cnt].begin(), v_[cnt].end());

    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // QuickSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // QuickSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // QuickSort__(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // QuickSort__(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // ShellSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // ShellSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // CombSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // CombSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // InsertionSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // InsertionSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // SelectionSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // SelectionSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // BubbleSort(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // BubbleSort(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cout << "Current :  " << func_names[cnt] << std::endl;
    // begin = std::chrono::steady_clock::now();
    // // BubbleSort_(v_[cnt].begin(), v_[cnt].end(), [](T& a, T& b) { return a < b; });
    // BubbleSort_(v_[cnt].begin(), v_[cnt].end());
    // end = std::chrono::steady_clock::now();
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "\tTime difference = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
    // std::cout << "\tisSorted : " << isSorted(v_[cnt], 0) << std::endl;
    // std::cout << "\tisSorted : " << std::is_sorted(v_[cnt].begin(), v_[cnt].end()) << std::endl;
    // std::cout << "DONE " << func_names[cnt] << std::endl;
    // cnt++;

    // std::cin.get();
}
