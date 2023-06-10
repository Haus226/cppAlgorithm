# cppAlgorithm
Some algorithm implemented using C++

# Sorting Algorithm (folder : sortingIterator)
Micmic C++ standard library style which accepts begin and end iterator of a container and customized comparison function (using std::less by default). 
- Heap Sort (Iterative slightly faster in microseconds)
- Heap Sort_ (Recursive)
- Merge Sort 
- Merge Sort__ (Slightly faster in millseconds)
- Quick Sort
- Quick Sort__ 
- Shell Sort
- Comb Sort
- Insertion Sort
- Selection Sort
- Bubble Sort
- Bubble Sort_ (Modified version with a variable that check whether swapping occurs everytime but ver slow compared to plain version)

# Algorithms that receive std::vector (folder : sortingVector)
Sorting function that accpets Comparable template arguement vector and some can only accept integer.
Under this folder contain a func.hpp which contains some usefule function such as printArr, isSorted while the elementSearch.hpp
is the file that implements Linear Search, Jump Search and recursive Binary Search.
1) Heap Sort (Iterative slightly faster in microseconds)
2) Heap Sort_ (Recursive)
3) Merge Sort 
4) Merge Sort__ (Slightly faster in millseconds)
5) Quick Sort
6) Quick Sort__ 
7) Shell Sort
8) Comb Sort
9) Insertion Sort
10) Selection Sort
11) Bubble Sort
12) Bubble Sort_ (Modified version with a variable that check whether swapping occurs everytime but ver slow compared to plain version)
13) Counting Sort (Integer Only)
14) Plain Radix Sort (Integer Only)
15) Radix Sort with Counting Sort as subroutine (Integer Only)
16) Radix Sort for floating (Based on bits, actually applicable to integer also but slower than (16))
17) Radix Sort for integer (Based on bits, faster than the two (14 and 15) above)
  - There is small differences between the two radix sort (16 and 17) above but the implementations are mostly the same
  - Reference Link for 16 and 17 : [https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-floats-in-c-sharp](https://stackoverflow.com/questions/2685035/is-there-a-good-radixsort-implementation-for-floats-in-c-sharp)
18) Hybrid Bucket Sort (use Insertion Sort when less elements while Merge Sort when more elements)

# Optimization Algorithm (for Travelling Salesman Problem)
[TSP Data Source](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp/)
Currently does not support data in format of MATRIX type, please use the cleaned dataset provided (dataset.zip)
- Ant Colony Optimization (ACO)
  - Implement based on Ant Cycle Model
  - Speed up the searching by using multithreading such that one thread handle some of the ants
- Genetic Algorithm (GA)
  - Can simulate several different populations at one time by multithreading
- Simulated Annealing (SA)
