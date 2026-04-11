#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n = 4, m = 3;
    struct Edge edges[] = {
        {0,1,4},
        {0,2,5},
        {1,2,-3}
    };

    int dist[n];

    // Step 1: Initialize
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[0] = 0; // source

    // Step 2: Relax edges n-1 times
    for(int i = 1; i <= n-1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Output distances
    printf("Shortest distances:\n");
    for(int i = 0; i < n; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}