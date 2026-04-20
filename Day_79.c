#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Create new node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Find vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int n, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 1; count <= n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}