// Following the assignment's guideline: the main func was written by me, everything else, taken from Geeks4Geeks:
// https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

// Number of vertices in the graph
// #define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int V)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int **graph, int src, int V)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet, V);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}

#ifndef TEST
int main()
{
	/* Let us create the example graph discussed above */
	int V = 0;		// Number of verties in the graph
	char c;
	int num;

	printf("How many vertices do you want?\n");
	scanf("%d", &V);

	int** graph = (int **) malloc (V * sizeof(int*));

	if ((c = getchar()) != '\n'){
		fprintf(stderr, "ERROR: Invalid input! a line-break was expected, received %c.\n", c);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < V; i++){
		graph[i] = (int *)malloc(V * sizeof(int));
		for (int j = 0; j < V; j++){
			// skip 1 space or print error if less or more than 1 space was given (only done after the first input in the line)
			if (j != 0 && (c = getchar()) != ' ') {
				fprintf(stderr, "ERROR: Invalid input! a space was expected, received '%c'\n", c);
				exit(EXIT_FAILURE);
			}

			if (scanf("%d", &num) == 1) {
				if (num >= 0){
					graph[i][j] = num;
				}
				else {
					fprintf(stderr, "ERROR: Negative weights are not allowed!\n");
					exit(EXIT_FAILURE);
				}
			}
			else {
				fprintf(stderr, "ERROR: Invalid input! Please enter integers only!\n");
				exit(EXIT_FAILURE);
			}
		}
		if ((c = getchar()) != '\n'){
			fprintf(stderr, "ERROR: Invalid input! a line-break was expected, received '%c'\nDon't add a space at the end of the row.", c);
			exit(EXIT_FAILURE);
		}
	}

	// Function call
	dijkstra(graph, 0, V);

	return 0;
}
#endif