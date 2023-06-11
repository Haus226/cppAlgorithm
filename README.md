B cppAlgorithm

Some algorithms implemented using C++.

## Algorithm (folder: algorithmIterator)
Micmic C++ standard library style which accepts begin and end iterator of a container and customized comparison function (using std::less by default). 
Under this folder contains two different folder `sorting`, `searching`. In `searching`, three algorithms were implemented i.e [`LinearSearch`](algorithmIterator/searching/elementSearch.tpp), [`JumpSearch`](algorithmIterator/searching/elementSearch.tpp) and recursive [`BinarySearch`](algorithmIterator/searching/elementSearch.tpp).
While the algorithms implemented in `sorting` were shown below :
- [`HeapSort`](algorithmIterator/sorting/selectionSort.tpp) (Iterative slightly faster in microseconds)
- [`HeapSort_`](algorithmIterator/sorting/selectionSort_.tpp) (Recursive)
- [`MergeSort`](algorithmIterator/sorting/mergeSort.tpp)
- [`MergeSort__`](algorithmIterator/sorting/mergeSort.tpp) (Slightly faster in millseconds)
- [`QuickSort`](algorithmIterator/sorting/quickSort.tpp)
- [`QuickSort__`](algorithmIterator/sorting/quickSort.tpp)
- [`ShellSort`](algorithmIterator/sorting/insertionSort.tpp)
- [`CombSort`](algorithmIterator/sorting/bubbleSort.tpp)
- [`InsertionSort`](algorithmIterator/sorting/insertionSort.tpp)
- [`SelectionSort`](algorithmIterator/sorting/selectionSort.tpp)
- [`BubbleSort`](algorithmIterator/sorting/bubbleSort.tpp)
- [`BubbleSort_`](algorithmIterator/sorting/bubbleSort.tpp) (Modified version with a variable that check whether swapping occurs everytime but ver slow compared to plain version)


## Algorithms that receive std::vector (folder : algorithmVector)

Sorting function that accpets Comparable template arguement vector and some can only accept integer.
Under this folder contain a [`func.tpp`](algorithmVector/func.tpp) which contains some useful function such as [`printArr`](algorithmVector/func.tpp), [`isSorted`](algorithmVector/func.tpp) while the elementSearch.hpp
is the file that implements [`LinearSearch`](algorithmVector/searching/elementSearch.tpp), [`JumpSearch`](algorithmVector/searching/elementSearch.tpp) and recursive [`BinarySearch`](algorithmVector/searching/elementSearch.tpp).
1. [`HeapSort`](algorithmVector/sorting/selectionSort.tpp) (Iterative slightly faster in microseconds)
2. [`HeapSort_`](algorithmVector/sorting/selectionSort.tpp) (Recursive)
3. [`MergeSort`](algorithmVector/sorting/mergeSort.tpp)
4. [`MergeSort__`](algorithmVector/sorting/mergeSort.tpp) (Slightly faster in milliseconds)
5. [`QuickSort`](algorithmVector/sorting/quickSort.tpp)
6. [`QuickSort__`](algorithmVector/sorting/quickSort.tpp)
7. [`ShellSort`](algorithmVector/sorting/insertionSort.tpp)
8. [`CombSort`](algorithmVector/sorting/bubbleSort.tpp)
9. [`InsertionSort`](algorithmVector/sorting/insertionSort.tpp)
10. [`SelectionSort`](algorithmVector/sorting/selectionSort.tpp)
11. [`BubbleSort`](algorithmVector/sorting/bubbleSort.tpp)
12. [`BubbleSort_`](algorithmVector/sorting/bubbleSort.tpp) (Modified version with a variable that checks whether swapping occurs every time but very slow compared to plain version)
13. [`CountingSort`](algorithmVector/sorting/countingSort.tpp) (Integer Only)
14. [`RadixSort`](algorithmVector/sorting/radixSort.tpp) (Plain Radix Sort for Integer Only)
15. [`RadixSort_`](algorithmVector/sorting/radixSort.tpp) with Counting Sort as a subroutine (Integer Only)
16. [`RadixSort_FLOAT`](algorithmVector/sorting/radixSort.tpp) for floating (Based on bits, actually applicable to integer also but slower than (17))
17. [`RadixSort_INT`](algorithmVector/sorting/radixSort.tpp) for integer (Based on bits, faster than the two (14 and 15) above)
  - There are small differences between the two radix sorts (16 and 17) above, but the implementations are mostly the same
  - Reference Link for 16 and 17: [https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-
    floats-in-c-sharp](https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-floats-in-c-sharp)
19. Hybrid [`BucketSort`](algorithmVector/sorting/bucketSort.tpp) (use Insertion Sort when fewer elements while Merge Sort (3) when more elements)
20. Hybrid [`BucketSort_`](algorithmVector/sorting/bucketSort.tpp) (use Insertion Sort when fewer elements while Merge Sort (4) when more elements)

## Optimization Algorithm (for Travelling Salesman Problem)
[TSP Data Source](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp/)
Currently does not support data in format of MATRIX type, please use the cleaned dataset provided ([dataset.zip](tspAlgorithm/dataset.zip))
- [`antColonyOpimization`](tspAlgorithm/antColonyOptimization.cpp) (ACO)
  - Implement based on Ant Cycle Model
  - Speed up the searching by using multithreading, with each thread handling a subset of the ants
- [`geneticAlgorithm`](tspAlgorithm/geneticAlgorithm.cpp) (GA)
  - Can simulate several different populations concurrently using multithreading
- [`simulatedAnnealing`](tspAlgorithm/simulatedAnnealing.cpp) (SA)


Usage :
Write the test in run.cpp then run the [`make`](tspAlgorithm/Makefile) command in terminal and finally run the run.exe.
