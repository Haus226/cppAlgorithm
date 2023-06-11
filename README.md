B cppAlgorithm

Some algorithms implemented using C++.

## Algorithm (folder: algorithmIterator)
Micmic C++ standard library style which accepts begin and end iterator of a container and customized comparison function (using std::less by default). 
Under this folder contains two different folder `sorting`, `searching`. In `searching`, three algorithms were implemented i.e `LinearSearch`, `JumpSearch`and recursive `BinarySearch`.
While the algorithms implemented in `sorting` were shown below :
- [`HeapSort`](algorithmIterator/sorting/HeapSort.tpp) (Iterative slightly faster in microseconds)
- [`HeapSort_`](algorithmIterator/sorting/HeapSort_.tpp) (Recursive)
- [`MergeSort`](algorithmIterator/sorting/MergeSort.tpp)
- [`MergeSort__`](algorithmIterator/sorting/MergeSort__.tpp) (Slightly faster in millseconds)
- [`QuickSort`](algorithmIterator/sorting/QuickSort.tpp)
- [`QuickSort__`](algorithmIterator/sorting/QuickSort__.tpp)
- [`ShellSort`](algorithmIterator/sorting/ShellSort.tpp)
- [`CombSort`](algorithmIterator/sorting/CombSort.tpp)
- [`InsertionSort`](algorithmIterator/sorting/InsertionSort.tpp)
- [`SelectionSort`](algorithmIterator/sorting/SelectionSort.tpp)
- [`BubbleSort`](algorithmIterator/sorting/BubbleSort.tpp)
- [`BubbleSort_`](algorithmIterator/sorting/BubbleSort_.tpp) (Modified version with a variable that check whether swapping occurs everytime but ver slow compared to plain version)


## Algorithms that receive std::vector (folder : algorithmVector)

Sorting function that accpets Comparable template arguement vector and some can only accept integer.
Under this folder contain a `func.tpp` which contains some useful function such as `printArr`, `isSorted` while the elementSearch.hpp
is the file that implements `LinearSearch`, `JumpSearch`and recursive `BinarySearch`.
1) `HeapSort` (Iterative slightly faster in microseconds)
2) `HeapSort_` (Recursive)
3) `MergeSort`
4) `MergeSort__` (Slightly faster in milliseconds)
5) `QuickSort`
6) `QuickSort__`
7) `ShellSort`
8) `CombSort`
9) `InsertionSort`
10) `SelectionSort`
11) `BubbleSort`
12) `BubbleSort_` (Modified version with a variable that checks whether swapping occurs every time but very slow compared to plain version)
13) `CountingSort` (Integer Only)
14) `RadixSort` (Integer Only)
15) `RadixSort_` with Counting Sort as a subroutine (Integer Only)
16) `RadixSort_FLOAT` for floating (Based on bits, actually applicable to integer also but slower than (17))
17) `RadixSort_INT` for integer (Based on bits, faster than the two (14 and 15) above)
  - There are small differences between the two radix sorts (16 and 17) above, but the implementations are mostly the same
  - Reference Link for 16 and 17: [https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-floats-in-c-sharp](https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-floats-in-c-sharp)
18) `BucketSort` (use Insertion Sort when fewer elements while Merge Sort (3) when more elements)
19) `BucketSort_` (use Insertion Sort when fewer elements while Merge Sort (3) when more elements)


## Optimization Algorithm (for Travelling Salesman Problem)
[TSP Data Source](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp/)
Currently does not support data in format of MATRIX type, please use the cleaned dataset provided (dataset.zip)
- `antColonyOpimization` (ACO)
  - Implement based on Ant Cycle Model
  - Speed up the searching by using multithreading such that one thread handle some of the ants
- `geneticAlgorithm` (GA)
  - Can simulate several different populations at one time by multithreading
- `simulatedAnnealing` (SA)


Usage :
Write the test in run.cpp then run the make command in terminal and finally run the run.exe.
