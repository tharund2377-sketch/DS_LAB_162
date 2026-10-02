/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 9
Title      : Implementation of Priority Queue (Binary Min-Heap)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements a Priority Queue using an array-based Binary Min-Heap.
    Maintains the min-heap invariant where the parent node is always smaller
    than or equal to its children. Supports O(log n) insertion and min-deletion.

Operations:
    1. Insert (Percolate Up)
    2. Delete Min (Percolate Down)
    3. Display Heap Array
    4. Safe Memory Cleanup & Exit

Complexity:
    Insert     : O(log n)
    Delete Min : O(log n)
    Find Min   : O(1)
    Display    : O(n)
    Space      : O(n)

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int capacity;
    int size;
    int *elements;
};

typedef struct Heap *PriorityQueue;

/* Function Prototypes */
static PriorityQueue initialize_heap(int max_elements);
static int is_empty(const PriorityQueue pq);
static int is_full(const PriorityQueue pq);
static void insert(PriorityQueue pq, int x);
static int delete_min(PriorityQueue pq);
static void display(const PriorityQueue pq);
static void free_heap(PriorityQueue pq);

/* ========================================================================= */

int main(void) {
    int capacity = 20;
    PriorityQueue pq = initialize_heap(capacity);
    int choice, element;

    while (1) {
        printf("\n========================================\n");
        printf("       PRIORITY QUEUE (MIN-HEAP)\n");
        printf("========================================\n");
        printf("1. Insert Element\n");
        printf("2. Delete Minimum Element\n");
        printf("3. Display Heap Elements\n");
        printf("4. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                if (scanf("%d", &element) == 1) {
                    insert(pq, element);
                } else {
                    printf("Invalid input.\n");
                }
                break;

            case 2:
                if (!is_empty(pq)) {
                    int min_val = delete_min(pq);
                    printf("The deleted minimum element is: %d\n", min_val);
                } else {
                    printf("Priority Queue is empty.\n");
                }
                break;

            case 3:
                display(pq);
                break;

            case 4:
                printf("Exiting program...\n");
                free_heap(pq);
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice. Please enter 1-4.\n");
        }
    }

    free_heap(pq);
    return EXIT_SUCCESS;
}

/* ========================================================================= */

static PriorityQueue initialize_heap(int max_elements) {
    if (max_elements < 1) {
        fprintf(stderr, "Error: Priority queue capacity too small.\n");
        exit(EXIT_FAILURE);
    }

    PriorityQueue pq = (PriorityQueue)malloc(sizeof(struct Heap));
    if (pq == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(EXIT_FAILURE);
    }

    /* 1-based indexing for convenient child calculation (2*i, 2*i+1) */
    pq->elements = (int *)malloc((max_elements + 1) * sizeof(int));
    if (pq->elements == NULL) {
        fprintf(stderr, "Error: Out of memory for heap elements.\n");
        free(pq);
        exit(EXIT_FAILURE);
    }

    pq->capacity = max_elements;
    pq->size = 0;
    pq->elements[0] = -1; /* Sentinel at index 0 */

    return pq;
}

static int is_empty(const PriorityQueue pq) {
    return (pq->size == 0);
}

static int is_full(const PriorityQueue pq) {
    return (pq->size == pq->capacity);
}

static void insert(PriorityQueue pq, int x) {
    if (is_full(pq)) {
        printf("Priority Queue is full. Insertion rejected.\n");
        return;
    }

    /* Percolate up */
    int i = ++pq->size;
    while (i > 1 && pq->elements[i / 2] > x) {
        pq->elements[i] = pq->elements[i / 2];
        i = i / 2;
    }
    pq->elements[i] = x;
    printf("Element %d inserted into Priority Queue.\n", x);
}

static int delete_min(PriorityQueue pq) {
    if (is_empty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }

    int min_element = pq->elements[1];
    int last_element = pq->elements[pq->size--];

    /* Percolate down */
    int i = 1;
    int child;
    for (i = 1; i * 2 <= pq->size; i = child) {
        child = i * 2;
        /* Choose smaller child */
        if (child != pq->size && pq->elements[child + 1] < pq->elements[child])
            child++;

        if (last_element > pq->elements[child])
            pq->elements[i] = pq->elements[child];
        else
            break;
    }
    pq->elements[i] = last_element;

    return min_element;
}

static void display(const PriorityQueue pq) {
    if (is_empty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Elements in the heap array (level-order): ");
    for (int i = 1; i <= pq->size; i++) {
        printf("%d ", pq->elements[i]);
    }
    printf("\n");
}

static void free_heap(PriorityQueue pq) {
    if (pq != NULL) {
        if (pq->elements != NULL) {
            free(pq->elements);
        }
        free(pq);
    }
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
       PRIORITY QUEUE (MIN-HEAP)
========================================
1. Insert Element
2. Delete Minimum Element
3. Display Heap Elements
4. Exit
----------------------------------------
Enter your choice: 1
Enter the element to insert: 87
Element 87 inserted into Priority Queue.

Enter your choice: 1
Enter the element to insert: 3
Element 3 inserted into Priority Queue.

Enter your choice: 1
Enter the element to insert: 65
Element 65 inserted into Priority Queue.

Enter your choice: 3
Elements in the heap array (level-order): 3 87 65

Enter your choice: 2
The deleted minimum element is: 3

Enter your choice: 3
Elements in the heap array (level-order): 65 87

Enter your choice: 4
Exiting program...
===============================================================================
*/