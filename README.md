# Travelling-Sales-Man-Problem
Travelling Salesman Problem is stated as: A salesman wants to visit N cities such that
starting from a city he visits every city exactly once and returns to the starting city. Problem
is to find the order in which salesman has to visit the cities so that minimum distance is
covered.

The algorithm used is Simulated Annealing.

The initial tour is generated randomly.This tour is given as input to simulated anneal-
ing.Here the initial temperature is set to 100 and it is reduced by a factor of 0.99992 after
100(value of j in pseudocode) iterations. The number of epochs is 100000000.The node here
is a path and it is evaluated by the total distance covered.Distance between cities is given in
the input file. If the distance measure used is non euclidean, then the distance between the
cities are updated with shortest path found using Floyd Warshall algorithm. To generate
random neighbours 2 opt algorithm is used.