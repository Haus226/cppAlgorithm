# Define variables
CC := g++
CFLAGS := -std=c++14 -Wall -O3
SRCS := test.cpp antColonyOptimization.cpp geneticAlgorithm.cpp simulatedAnnealing.cpp func.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.hpp)

# Compile object files

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
test: $(OBJS)
	$(CC) -o $@ $^

# Phony target to clean generated files
.PHONY: clean
clean:
	del -f $(OBJS) test
