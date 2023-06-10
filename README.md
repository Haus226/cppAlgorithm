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

# Sorting Algorithms which have some constraints (folder : sortingVector)
Sorting function that accpets Comparable template arguement vector and some can only accept integer
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
- Counting Sort (Integer Only)
- Plain Radix Sort (Integer Only)
- Radix Sort with Counting Sort as subroutine
- Radix Sort for floating (Based on bits)
- Radix Sort for integer (Based on bits)
- Hybrid Bucket Sort (use Insertion Sort when less elements while Merge Sort when more elements)

# Optimization Algorithm (for Travelling Salesman Problem)
[TSP Data Source](http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp/)
Currently does not support data in format of MATRIX type, please use the cleaned dataset provided (dataset.zip)
- Ant Colony Optimization (ACO)
  - Speed up the searching by using multithreading such that one thread handle some of the ants
- Genetic Algorithm (GA)
  - Can simulate several different populations at one time by multithreading
- Simulated Annealing (SA)
