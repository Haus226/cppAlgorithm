#include <vector>
#include <cstring>
#include "radixSort.hpp"
#include <cstdint>


// Plain Radix Sort for integer
template <typename Comparable>
std::vector<Comparable> RadixSort(std::vector<Comparable> &arr, bool reverse) {
    static_assert(!std::is_same<Comparable, float>::value, "You can't use floats here");
    static_assert(!std::is_same<Comparable, double>::value, "You can't use doubles here");
    std::vector<Comparable> t(arr);
    Comparable min = 0;
    Comparable max = 0;
    for (size_t idx = 0; idx < arr.size(); idx++) {
        if (t[idx] < min) min = t[idx];
        if (t[idx] > max) max = t[idx];
    }
    max -= min;
    if (min < 0) for (size_t idx = 0; idx < arr.size(); idx++) t[idx] = arr[idx] - min;
    for (int64_t exp = 1; max / exp > 0; exp *= 10) {
        std::vector<std::vector<Comparable>> buckets(10);
        for (Comparable e : t) buckets[(e / exp) % 10].push_back(e);
        size_t index = 0;
        for (std::vector<Comparable> v : buckets) {
            for (Comparable e : v) t[index++] = e;
        }
    }
    if (!reverse) {
        for (size_t idx = 0; idx < arr.size(); idx++) {
            arr[idx] = t[idx] + min;
        }
    }
    else {
        for (size_t idx = 0; idx < arr.size(); idx++) {
            arr[arr.size() - idx - 1] = t[idx];
        }
    }
    return arr;
}

// Counting sort used in Radix sort for integer
template <typename Comparable>
std::vector<Comparable> countingSort_(std::vector<Comparable> &arr, Comparable place) {
    std::vector<Comparable> output(arr.size(), 0);
    std::vector<Comparable> count(10, 0);
    for (Comparable e : arr) count[(e / place) % 10]++;    
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    // Be careful, don't use size_t here since when i = 0 after i--, 
    // i will become positive again due to data type is uint64_t 
    for (long long i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / place) % 10] - 1] = arr[i];
            count[(arr[i] / place) % 10]--;
    }    
    for (size_t i = 0; i < arr.size(); i++) arr[i] = output[i];
    return arr;
}

// Radix Sort for integer with Counting Sort as subroutine
template <typename Comparable>
std::vector<Comparable> RadixSort_(std::vector<Comparable> &arr, bool reverse) {
    std::vector<Comparable> t(arr);
    Comparable min = 0, max = 0;
    for (size_t idx = 0; idx < arr.size(); idx++) {
        if (t[idx] < min) min = t[idx];
        if (t[idx] > max) max = t[idx];
    }
    max -= min;
    if (min < 0) for (size_t idx = 0; idx < arr.size(); idx++) t[idx] = arr[idx] - min;
    for (Comparable exp = 1; max / exp > 0; exp *= 10) countingSort_(t, exp);
    if (!reverse) {
        for (size_t idx = 0; idx < arr.size(); idx++) arr[idx] = t[idx] + min;
        return arr;
    }
    else {
        for (size_t idx = 0; idx < arr.size(); idx++) arr[arr.size() - idx - 1] = t[idx] + min;
        return arr;

    }
}

double ll2d(long long val) {
    double convertedValue = 0.0;
    std::memcpy(&convertedValue, &val, sizeof(convertedValue));
    return convertedValue;
}

template <typename T>
std::vector<T> RadixSort_FLOAT(std::vector<T>& array, bool reverse) {
    // static_assert(!std::is_same<T, int>::value, "You can't use integer here");
    // static_assert(!std::is_same<T, int8_t>::value, "You can't use integer here");
    // static_assert(!std::is_same<T, int16_t>::value, "You can't use integer here");
    // static_assert(!std::is_same<T, int32_t>::value, "You can't use integer here");
    // static_assert(!std::is_same<T, int64_t>::value, "You can't use integer here");

    // temporary array and the array of converted doubles to ints
    std::vector<long long> t(array.size());
    std::vector<long long> a(array.size());
    for (size_t i = 0; i < array.size(); i++)
        a[i] = *reinterpret_cast<const long long*>(&array[i]);

    // set the group length to 1, 2, 4, 8 or 16
    // and see which one is quicker
    int groupLength = 4;
    int bitLength = sizeof(double) * 8;
//    cout << bitLength << endl;

    // counting and prefix arrays
    // (dimension is 2^r, the number of possible values of a r-bit number)
    std::vector<int> count(1 << groupLength);
    std::vector<int> pref(1 << groupLength);
    int groups = bitLength / groupLength;
    int mask = (1 << groupLength) - 1;
    int negatives = 0, positives = 0;

    for (int c = 0, shift = 0; c < groups; c++, shift += groupLength)
    {
        // reset count array
        std::fill(count.begin(), count.end(), 0);

        // counting elements of the c-th group
        for (size_t i = 0; i < a.size(); i++)
        {
            // To iterate "groupLength" bits from LSB to MSB
            count[(a[i] >> shift) & mask]++;

            // additionally count all negative
            // values in first round

            if (c == 0 && a[i] < 0)
                negatives++;
        }
        if (c == 0) positives = a.size() - negatives;

        // calculating prefixes (cumulative sum)
        pref[0] = 0;
        for (size_t i = 1; i < count.size(); i++)
            pref[i] = pref[i - 1] + count[i - 1];

        // counting sort
        for (size_t i = 0; i < a.size(); i++){
            // Get the right index to sort the number in
            int index = pref[(a[i] >> shift) & mask]++;

            if (c == groups - 1)
            {
                // We're in the last (most significant) group, if the
                // number is negative, order them inversely in front
                // of the array, pushing positive ones back.
                if (a[i] < 0)
                    index = positives - (index - negatives) - 1;
                else
                    index += negatives;
            }
            t[index] = a[i];
        }
        // a[]=t[] and start again until the last group
        std::copy(t.begin(), t.end(), a.begin());
    }

    // Convert back the ints to the double array
    if(!reverse) {
        std::vector<T> ret(a.size());
        for (size_t i = 0; i < a.size(); i++) ret[i] = ll2d(a[i]);
        return ret;
    }
    else {
        std::vector<T> ret(a.size());
        for (size_t i = 0; i < a.size(); i++) ret[a.size() - i - 1] = ll2d(a[i]);
        return ret;
    }
}

template <typename T>
std::vector<T> RadixSort_INT(std::vector<T>& array, bool reverse)
{
    static_assert(!std::is_same<T, float>::value, "You can't use floats here");
    static_assert(!std::is_same<T, double>::value, "You can't use doubles here");
    // temporary array and the array of converted doubles to ints
    std::vector<T> t(array.size());
    std::vector<T> a(array);

    // set the group length to 1, 2, 4, 8 or 16
    // and see which one is quicker
    int groupLength = 4;
    int bitLength = sizeof(T) * 8;

    // counting and prefix arrays
    // (dimension is 2^r, the number of possible values of a r-bit number)
    std::vector<int> count(1 << groupLength);
    std::vector<int> pref(1 << groupLength);
    int groups = bitLength / groupLength;
    int mask = (1 << groupLength) - 1;
    int negatives = 0, positives = 0;

    for (int c = 0, shift = 0; c < groups; c++, shift += groupLength) {
//        cout << "Current Group : " << c << endl;
        // Reset count array
        std::fill(count.begin(), count.end(), 0);

        // Counting elements of the c-th group
        for (size_t i = 0; i < a.size(); i++) {
            // To iterate "groupLength" bits from LSB to MSB
            count[(a[i] >> shift) & mask]++;
            // Count all negative
            // values in first round
            if (c == 0 && a[i] < 0) negatives++;
        }
        if (c == 0) positives = a.size() - negatives;

        // calculating prefixes (cumulative sum)
        pref[0] = 0;
        for (size_t i = 1; i < count.size(); i++)
            pref[i] = pref[i - 1] + count[i - 1];

        // counting sort
        for (size_t i = 0; i < a.size(); i++) {
            // Get the right index to sort the number in
            int index = pref[(a[i] >> shift) & mask]++;

            if (c == groups - 1) {
                // We're in the last (most significant) group, if the
                // number is negative, order them inversely in front
                // of the array, pushing positive ones back.
                if (a[i] < 0) index = positives - (index - negatives) - 1;
                else index += negatives;
            }
            t[index] = a[i];
        }
        // a[]=t[] and start again until the last group
        std::copy(t.begin(), t.end(), a.begin());
    }

    // The negatives are sorted reversely while positives are sorted correctly
    for (long long idx = negatives - 1, cnt = 0; idx >= 0; idx--, cnt++) a[cnt] = t[idx];
    for (long long idx = negatives; idx < t.size(); idx++) a[idx] = t[idx];
    // Convert back the ints to the double array
    if(!reverse) return a;
    else {
        std::vector<T> ret(a.size());
        for (size_t i = 0; i < a.size(); i++) ret[a.size() - i - 1] = a[i];
        return ret;
    }
}