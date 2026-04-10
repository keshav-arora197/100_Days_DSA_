#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int n; // number of vertices
int graph[MAX][MAX]; // adjacency matrix

void dijkstra(int src) {
    int dist[MAX], visited[MAX] = {0};

    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;

        // Find minimum distance vertex
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances
        for(int v = 0; v < n; v++) {
            if(!visited[v] && graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for(int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
}