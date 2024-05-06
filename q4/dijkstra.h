// taken from Geeks4Geeks:
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

#include <stdbool.h>

// #define TEST

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int V);

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int V);

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int **graph, int src, int V);