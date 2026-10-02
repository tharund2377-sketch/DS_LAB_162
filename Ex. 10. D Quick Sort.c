/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 10.D
Title      : Implementation of Quick Sort
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements the divide-and-conquer Quick Sort algorithm using Lomuto
    partitioning. Selects the last element as the pivot, partitions the array
    such that elements smaller than pivot precede it, and recursively sorts
    the left and right sub-arrays.

Operations:
    1. Read Array Elements
    2. Lomuto Partitioning
    3. Recursive Quick Sort
    4. Display Original & Sorted Arrays

Complexity:
    Best Case Time    : O(n log n)
    Average Case Time : O(n log n)
    Worst Case Time   : O(n^2) (already sorted array with naive pivot)
    Space Complexity  : O(log n) auxiliary stack space

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Function Prototypes */
static void swap(int *a, int *b);
static int partition(int arr[], int low, int high);
static void quick_sort(int arr[], int low, int high);
static void print_array(const int arr[], int size);

/* ========================================================================= */

int main(void) {
    int arr[MAX_SIZE];
    int n;

    printf("========================================\n");
    printf("          QUICK SORT ALGORITHM\n");
    printf("========================================\n");

    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        printf("Using default demonstration array.\n");
        const int demo[] = {12, 7, 11, 13, 5, 6};
        n = (int)(sizeof(demo) / sizeof(demo[0]));
        for (int i = 0; i < n; i++)
            arr[i] = demo[i];
    } else {
        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                fprintf(stderr, "Error: Invalid array element.\n");
                return EXIT_FAILURE;
            }
        }
    }

    printf("\nOriginal array:\n");
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    print_array(arr, n);

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high]; /* Lomuto: last element as pivot */
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        /* Recursively sort sub-arrays */
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

static void print_array(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i == size - 1) ? "" : " ");
    }
    printf("\n");
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
          QUICK SORT ALGORITHM
========================================
Enter number of elements (1-100): 6
Enter 6 elements:
12 7 11 13 5 6

Original array:
12 7 11 13 5 6
Sorted array:
5 6 7 11 12 13
===============================================================================
*/