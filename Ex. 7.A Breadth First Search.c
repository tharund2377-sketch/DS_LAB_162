/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 7.A
Title      : Breadth First Search (BFS)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements Breadth First Search graph traversal using an adjacency list
    representation and a FIFO queue. Traverses the graph level by level
    starting from a source vertex.

Operations:
    1. Graph Creation
    2. Add Directed/Undirected Edge
    3. Queue Operations (Enqueue, Dequeue, IsEmpty)
    4. BFS Traversal
    5. Print Adjacency List
    6. Safe Memory Cleanup

Complexity:
    Time Complexity  : O(V + E)
    Space Complexity : O(V) for queue and visited array

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

/* Queue for BFS */
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

/* Function Prototypes */
static struct Node *create_node(int v);
static struct Graph *create_graph(int vertices);
static void add_edge(struct Graph *graph, int src, int dest);
static struct Queue *create_queue(void);
static int is_empty(const struct Queue *q);
static void enqueue(struct Queue *q, int value);
static int dequeue(struct Queue *q);
static void print_graph(const struct Graph *graph);
static void bfs(struct Graph *graph, int start_vertex);
static void free_graph(struct Graph *graph);

/* ========================================================================= */

int main(void) {
    int vertices = 4;
    struct Graph *graph = create_graph(vertices);

    printf("========================================\n");
    printf("    BREADTH FIRST SEARCH TRAVERSAL\n");
    printf("========================================\n");

    /* Construct the graph */
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);

    printf("Adjacency List Representation of Graph:\n");
    print_graph(graph);

    printf("\nBFS Traversal starting from vertex 0:\n");
    bfs(graph, 0);
    printf("\n");

    /* Clean up allocated memory */
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

    /* Add edge from src to dest */
    struct Node *new_node = create_node(dest);
    new_node->next = graph->adjLists[src];
    graph->adjLists[src] = new_node;

    /* For undirected graph, add reverse edge dest -> src */
    new_node = create_node(src);
    new_node->next = graph->adjLists[dest];
    graph->adjLists[dest] = new_node;
}

static struct Queue *create_queue(void) {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (q == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for queue.\n");
        exit(EXIT_FAILURE);
    }
    q->front = -1;
    q->rear = -1;
    return q;
}

static int is_empty(const struct Queue *q) {
    return (q->front == -1);
}

static void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        fprintf(stderr, "Error: Queue is full.\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

static int dequeue(struct Queue *q) {
    if (is_empty(q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return item;
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

static void bfs(struct Graph *graph, int start_vertex) {
    struct Queue *q = create_queue();

    graph->visited[start_vertex] = 1;
    enqueue(q, start_vertex);

    while (!is_empty(q)) {
        int current_vertex = dequeue(q);
        printf("Visited %d\n", current_vertex);

        struct Node *temp = graph->adjLists[current_vertex];
        while (temp) {
            int adj_vertex = temp->vertex;
            if (graph->visited[adj_vertex] == 0) {
                graph->visited[adj_vertex] = 1;
                enqueue(q, adj_vertex);
            }
            temp = temp->next;
        }
    }

    free(q);
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

BFS Traversal starting from vertex 0:
Visited 0
Visited 2
Visited 1
Visited 3
===============================================================================
*/