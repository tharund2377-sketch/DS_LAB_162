/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 7.B
Title      : Depth First Search (DFS)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements Depth First Search graph traversal using an adjacency list
    representation and recursion (system call stack). Explores deeply along
    each branch before backtracking.

Operations:
    1. Graph Initialization
    2. Add Directed/Undirected Edges
    3. Recursive DFS Exploration
    4. Print Graph Adjacency List
    5. Safe Memory Deallocation

Complexity:
    Time Complexity  : O(V + E)
    Space Complexity : O(V) for visited array and recursive call stack

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

/* Adjacency list node */
struct Node {
    int vertex;
    struct Node *next;
};

/* Graph representation */
struct Graph {
    struct Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
};

/* Function Prototypes */
static struct Node *create_node(int v);
static struct Graph *create_graph(int vertices);
static void add_edge(struct Graph *graph, int src, int dest);
static void print_graph(const struct Graph *graph);
static void dfs(struct Graph *graph, int vertex);
static void free_graph(struct Graph *graph);

/* ========================================================================= */

int main(void) {
    int vertices = 4;
    struct Graph *graph = create_graph(vertices);

    printf("========================================\n");
    printf("     DEPTH FIRST SEARCH TRAVERSAL\n");
    printf("========================================\n");

    /* Construct the graph */
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    printf("Adjacency List Representation of Graph:\n");
    print_graph(graph);

    printf("\nDFS Traversal starting from vertex 0:\n");
    dfs(graph, 0);
    printf("\n");

    /* Clean up allocated graph memory */
    free_graph(graph);
    printf("\nGraph resources deallocated successfully.\n");

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static struct Node *create_node(int v) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

static struct Graph *create_graph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for graph.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = vertices;

    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

static void add_edge(struct Graph *graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        fprintf(stderr, "Warning: Vertex out of bounds (%d -> %d)\n", src, dest);
        return;
    }

    /* Add edge src -> dest */
    struct Node *new_node = create_node(dest);
    new_node->next = graph->adjLists[src];
    graph->adjLists[src] = new_node;

    /* For undirected graph, add reverse edge dest -> src */
    new_node = create_node(src);
    new_node->next = graph->adjLists[dest];
    graph->adjLists[dest] = new_node;
}

static void print_graph(const struct Graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node *temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

static void dfs(struct Graph *graph, int vertex) {
    struct Node *adj_list = graph->adjLists[vertex];
    struct Node *temp = adj_list;

    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    while (temp != NULL) {
        int connected_vertex = temp->vertex;

        if (graph->visited[connected_vertex] == 0) {
            dfs(graph, connected_vertex);
        }
        temp = temp->next;
    }
}

static void free_graph(struct Graph *graph) {
    if (graph == NULL)
        return;

    for (int i = 0; i < graph->numVertices; i++) {
        struct Node *temp = graph->adjLists[i];
        while (temp) {
            struct Node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(graph);
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
Adjacency List Representation of Graph:
Vertex 0: 2 -> 1 -> NULL
Vertex 1: 3 -> 2 -> 0 -> NULL
Vertex 2: 3 -> 1 -> 0 -> NULL
Vertex 3: 2 -> 1 -> NULL

DFS Traversal starting from vertex 0:
Visited 0
Visited 2
Visited 3
Visited 1
===============================================================================
*/