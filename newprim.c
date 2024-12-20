#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX_VERTICES 20

typedef struct {
    int from, to, weight;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES], numVertices;
Edge mst[MAX_VERTICES - 1];

int primAlgorithm();

int main() {
    int i, totalCost;

    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    totalCost = primAlgorithm();

    printf("\nMinimum Spanning Tree Edges:\n");
    for (i = 0; i < numVertices - 1; i++) {
        printf("%d -- %d == %d\n", mst[i].from, mst[i].to, mst[i].weight);
    }

    printf("\nTotal cost of the spanning tree = %d\n", totalCost);
    return 0;
}

int primAlgorithm() {
    int costMatrix[MAX_VERTICES][MAX_VERTICES];
    int minVertex, nextVertex, minDistance;
    int distance[MAX_VERTICES], parent[MAX_VERTICES];
    int visited[MAX_VERTICES], edgesLeft, i, j, minCost;

    // Create cost matrix
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (graph[i][j] == 0)
                costMatrix[i][j] = INFINITY;
            else
                costMatrix[i][j] = graph[i][j];
        }
    }

    // Initialize distance, visited, and parent arrays
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < numVertices; i++) {
        distance[i] = costMatrix[0][i];
        parent[i] = 0;
        visited[i] = 0;
    }

    minCost = 0;
    edgesLeft = numVertices - 1; // Number of edges to be added
    int edgeIndex = 0; // To track edges in the MST

    while (edgesLeft > 0) {
        // Find the vertex at minimum distance from the current spanning tree
        minDistance = INFINITY;
        for (i = 1; i < numVertices; i++) {
            if (visited[i] == 0 && distance[i] < minDistance) {
                nextVertex = i;
                minDistance = distance[i];
            }
        }

        minVertex = parent[nextVertex];

        // Add the edge to the MST
        mst[edgeIndex].from = minVertex;
        mst[edgeIndex].to = nextVertex;
        mst[edgeIndex].weight = distance[nextVertex];
        edgeIndex++;

        edgesLeft--;
        visited[nextVertex] = 1;

        // Update the distance array
        for (i = 1; i < numVertices; i++) {
            if (visited[i] == 0 && costMatrix[i][nextVertex] < distance[i]) {
                distance[i] = costMatrix[i][nextVertex];
                parent[i] = nextVertex;
            }
        }

        minCost += costMatrix[minVertex][nextVertex];
    }

    return minCost;
}
