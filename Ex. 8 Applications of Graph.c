/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 8
Title      : Applications of Graph (Dijkstra's Algorithm)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements Dijkstra's Single-Source Shortest Path Algorithm on a weighted
    directed graph represented as a cost adjacency matrix. Determines the
    shortest distance and prints the route from a source vertex to all vertices.

Operations:
    1. Input Cost Adjacency Matrix
    2. Minimum Distance Selection
    3. Edge Relaxation: dist[v] = dist[u] + cost[u][v]
    4. Shortest Path Reconstruction via Parent Tracking
    5. Formatted Output Display

Complexity:
    Time Complexity  : O(V^2) with adjacency matrix
    Space Complexity : O(V^2) for graph matrix, O(V) for distance and parent

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 20
#define INF 999

/* Function Prototypes */
static void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src);
static void print_path(const int parent[], int j);

/* ========================================================================= */

int main(void) {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int n, src;

    printf("========================================\n");
    printf("   DIJKSTRA'S SHORTEST PATH ALGORITHM\n");
    printf("========================================\n");

    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_VERTICES) {
        fprintf(stderr, "Error: Invalid number of vertices.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the cost adjacency matrix (use %d for no direct edge):\n", INF);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &graph[i][j]) != 1) {
                fprintf(stderr, "Error: Invalid matrix entry.\n");
                return EXIT_FAILURE;
            }
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    if (scanf("%d", &src) != 1 || src < 0 || src >= n) {
        fprintf(stderr, "Error: Invalid source vertex.\n");
        return EXIT_FAILURE;
    }

    dijkstra(graph, n, src);

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static void print_path(const int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printf("%d <- ", j);
    print_path(parent, parent[j]);
}

static void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int n, int src) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    /* Initialize distances, visited status, and parent pointers */
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; ++count) {
        /* Find minimum distance vertex from unvisited set */
        int min_dist = INF;
        int u = -1;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] <= min_dist) {
                min_dist = dist[v];
                u = v;
            }
        }

        if (u == -1 || min_dist == INF)
            break;

        visited[u] = 1;

        /* Relax adjacent vertices */
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    /* Display shortest paths and total costs */
    printf("\nShortest Paths from Source Vertex %d:\n", src);
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; ++i) {
        if (i == src)
            continue;

        if (dist[i] >= INF) {
            printf("Path to vertex %d: Cost = INF (No path reachable)\n", i);
        } else {
            printf("Path to vertex %d: Cost = %-3d | Path = ", i, dist[i]);
            print_path(parent, i);
            printf("\n");
        }
    }
    printf("--------------------------------------------------\n");
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
Enter the number of vertices (max 20): 5
Enter the cost adjacency matrix (use 999 for no direct edge):
0 10 5 999 999
999 0 2 1 999
999 3 0 9 2
4 999 999 0 7
999 999 999 6 0
Enter the source vertex (0 to 4): 0

Shortest Paths from Source Vertex 0:
--------------------------------------------------
Path to vertex 1: Cost = 8   | Path = 1 <- 2 <- 0
Path to vertex 2: Cost = 5   | Path = 2 <- 0
Path to vertex 3: Cost = 9   | Path = 3 <- 1 <- 2 <- 0
Path to vertex 4: Cost = 7   | Path = 4 <- 2 <- 0
--------------------------------------------------
===============================================================================
*/