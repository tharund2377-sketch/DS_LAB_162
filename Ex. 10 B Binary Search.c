/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 10.B
Title      : Implementation of Binary Search
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements the Binary Search algorithm on a sorted array using divide-and-
    conquer. Repeatedly halves the search interval by comparing the target
    value with the middle element.

Operations:
    1. Read Sorted Array Elements
    2. Ascending Order Verification
    3. Binary Search for Key
    4. Report Index / Position

Complexity:
    Best Case Time    : O(1) (element at middle position)
    Average Case Time : O(log n)
    Worst Case Time   : O(log n) (element not present or at leaf level)
    Space Complexity  : O(1) iterative

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Function Prototypes */
static int binary_search(const int arr[], int n, int key);
static void print_array(const int arr[], int n);

/* ========================================================================= */

int main(void) {
    int arr[MAX_SIZE];
    int n, key, index;

    printf("========================================\n");
    printf("         BINARY SEARCH ALGORITHM\n");
    printf("========================================\n");

    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        fprintf(stderr, "Error: Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d numbers in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: Invalid input value.\n");
            return EXIT_FAILURE;
        }
        /* Warn if not sorted */
        if (i > 0 && arr[i] < arr[i - 1]) {
            printf("Warning: Array elements must be in ascending order.\n");
        }
    }

    printf("\nSorted Array: ");
    print_array(arr, n);

    printf("Enter the search element: ");
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Error: Invalid search element.\n");
        return EXIT_FAILURE;
    }

    index = binary_search(arr, n, key);

    if (index != -1) {
        printf("Result: Element %d found at index %d (position %d).\n", key, index, index + 1);
    } else {
        printf("Result: Element %d is not present in the array.\n", key);
    }

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static int binary_search(const int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; /* Safe midpoint calculation */

        if (arr[mid] == key) {
            return mid; /* Key found */
        } else if (arr[mid] < key) {
            low = mid + 1; /* Search in right half */
        } else {
            high = mid - 1; /* Search in left half */
        }
    }

    return -1; /* Key not found */
}

static void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
         BINARY SEARCH ALGORITHM
========================================
Enter the number of elements (1-100): 4
Enter 4 numbers in ascending order:
a[0] = 23
a[1] = 45
a[2] = 67
a[3] = 87

Sorted Array: 23 45 67 87
Enter the search element: 45
Result: Element 45 found at index 1 (position 2).

Enter the search element: 10
Result: Element 10 is not present in the array.
===============================================================================
*/