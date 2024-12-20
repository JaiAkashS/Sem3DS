#include<stdio.h>
#include<stdlib.h>
#define INFINITY 9999
#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES], spanningTree[MAX_VERTICES][MAX_VERTICES], numVertices;

int primAlgorithm();

int main() {
    int i, j, totalCost;
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++)
        for (j = 0; j < numVertices; j++)
            scanf("%d", &graph[i][j]);

    totalCost = primAlgorithm();

    printf("\nSpanning Tree Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        printf("\n");
        for (j = 0; j < numVertices; j++)
            printf("%d\t", spanningTree[i][j]);
    }

    printf("\n\nTotal cost of the spanning tree = %d", totalCost);
    return 0;
}

int primAlgorithm() {
    int costMatrix[MAX_VERTICES][MAX_VERTICES];
    int minVertex, nextVertex, minDistance;
    int distance[MAX_VERTICES], parent[MAX_VERTICES];
    int visited[MAX_VERTICES], edgesLeft, i, minCost, j;

    // Create cost matrix and initialize spanning tree matrix
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            if (graph[i][j] == 0)
                costMatrix[i][j] = INFINITY;
            else
                costMatrix[i][j] = graph[i][j];
            
            spanningTree[i][j] = 0;
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

        // Add the edge to the spanning tree
        spanningTree[minVertex][nextVertex] = distance[nextVertex];
        spanningTree[nextVertex][minVertex] = distance[nextVertex];
        
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
