#include <stdio.h>
#define INFINITY 9999
#define MAX_VERTICES 10

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex) {
    int cost[MAX_VERTICES][MAX_VERTICES], distance[MAX_VERTICES], predecessor[MAX_VERTICES];
    int visited[MAX_VERTICES], count, minDistance, nextVertex;
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < numVertices; i++) {
        distance[i] = cost[startVertex][i];
        predecessor[i] = startVertex;
        visited[i] = 0;
    }
    distance[startVertex] = 0;
    visited[startVertex] = 1;
    count = 1;

    while (count < numVertices - 1) {
        minDistance = INFINITY;
        for (int i = 0; i < numVertices; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextVertex = i;
            }
        }

        visited[nextVertex] = 1;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && minDistance + cost[nextVertex][i] < distance[i]) {
                distance[i] = minDistance + cost[nextVertex][i];
                predecessor[i] = nextVertex;
            }
        }

        count++;
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", distance[i]);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        if (i != startVertex) {
            printf("The minimum distance from %d to %d = %d. ", startVertex, i, distance[i]);
            printf("%d", startVertex);
            int path[MAX_VERTICES];
            int count = 0;
            int j = i;
            while (j != startVertex) {
                path[count++] = j;
                j = predecessor[j];
            }
            for (int k = count - 1; k >= 0; k--) {
                printf("->%d", path[k]);
            }
            printf("\n");
        }
    }
}


int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int numVertices, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, numVertices, startVertex);

    return 0;
}
