# Usage
1. Read the TSP data using the [`readTSPData`](func.cpp) function in [`func.cpp`](func.cpp), which returns a pair. The first element is the data type needed to initialize the distance matrix, and the second element is the coordinates of the cities.
2. Pass the returned value to the `coords` parameter of the `antColonyOptimization`, `geneticAlgorithm`, and `simulatedAnnealing` functions. The distance matrix will be initialized inside the function.

## Parameters of antColonyOptimization
- `coords` (pair<string, vector<double, double>>): Data type of coordinates and coordinates of cities.
- `ants_num` (int): Number of ants.
- `alpha` (double): Weight of pheromone on transition probability.
- `beta` (double): Weight of heuristic on transition probability.
- `tau` (double): Initial value of pheromone.
- `rho` (double): Evaporation rate of pheromone.
- `q` (double): Constant used in the calculation that updates pheromone after an iteration.
- `iter` (int): Number of iterations.
- `verbose` (bool): Display the current iteration (100 per time), final best distance, and time used.
- `numThreads` (int): Number of threads to use for speeding up the searching. By default, it uses the maximum threads of the device.
- Returns: A tuple containing:
  1. A vector of int (best order of visiting).
  2. A vector of double (the best distance of each iteration).
  3. A double (the best distance found).
  4. A long long (time used in milliseconds).

## Parameters of geneticAlgorithm
- `coords` (pair<string, vector<double, double>>): Data type of coordinates and coordinates of cities.
- `iterations` (int): Number of iterations.
- `mutateRate` (double): The mutation rate. If the value is too high, it may not preserve the better order of visiting found.
- `popSize` (int): The size of the population.
- `eliteSize` (int): The number of top individuals to preserve.
- `verbose` (bool): Display the current iteration, final best distance, and time used.
- `numThreads` (int, for `threadedGeneticAlgorithm`): Number of threads used to run different populations concurrently. By default, it uses the maximum number of threads of the device.
- Returns: A tuple containing:
  1. A vector of int (best order of visiting).
  2. A vector of double (the best distance of each iteration).
  3. A double (the best distance found).
  4. A long long (time used in milliseconds).
- For `threadedGeneticAlgorithm`, it returns a tuple containing:
  1. A nested vector of int (best order of visiting for each population).
  2. A nested vector of double (the best distance of each iteration for each population).
  3. A vector of double (the best distance found for each population).
  4. A vector of long long (time used in milliseconds for each population).

## Parameters of simulatedAnnealing
- `coords` (pair<string, vector<double, double>>): Data type of coordinates and coordinates of cities.
- `temp` (double): Initial temperature.
- `coolingRate` (double): Cooling rate of temperature.
- `endTemp` (double): Threshold for ending.
- Returns: A tuple containing:
  1. A vector of int (best order of visiting).
  2. A vector of double (the best distance of each iteration).
  3. A double (the best distance found).
  4. A long long (time used in milliseconds).
