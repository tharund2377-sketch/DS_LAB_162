/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 10.A
Title      : Implementation of Linear Search
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements the Linear (Sequential) Search algorithm. Scans each element
    in the array sequentially from the start until a target key is found
    or the end of the array is reached.

Operations:
    1. Read Array Elements
    2. Linear Search for Target Key
    3. Display Index / 1-based Position
    4. Handle Absent Key Scenarios

Complexity:
    Best Case Time    : O(1) (element at first position)
    Average Case Time : O(n)
    Worst Case Time   : O(n) (element at last position or absent)
    Space Complexity  : O(1) auxiliary

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Function Prototypes */
static int linear_search(const int arr[], int n, int key);
static void print_array(const int arr[], int n);

/* ========================================================================= */

int main(void) {
    int arr[MAX_SIZE];
    int n, key, index;

    printf("========================================\n");
    printf("         LINEAR SEARCH ALGORITHM\n");
    printf("========================================\n");

    printf("Enter number of elements in array (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        /* Default to demo array if user enters 0 or invalid input */
        printf("Using default demonstration array.\n");
        const int demo[] = {12, 45, 67, 23, 56, 89, 9, 43};
        n = (int)(sizeof(demo) / sizeof(demo[0]));
        for (int i = 0; i < n; ++i)
            arr[i] = demo[i];
    } else {
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; ++i) {
            if (scanf("%d", &arr[i]) != 1) {
                fprintf(stderr, "Error: Invalid array element.\n");
                return EXIT_FAILURE;
            }
        }
    }

    printf("\nArray elements: ");
    print_array(arr, n);

    printf("\nEnter the element to search: ");
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Error: Invalid search key.\n");
        return EXIT_FAILURE;
    }

    index = linear_search(arr, n, key);

    if (index != -1) {
        printf("Result: Element %d found at index %d (position %d).\n", key, index, index + 1);
    } else {
        printf("Result: Element %d not found in the array.\n", key);
    }

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static int linear_search(const int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i; /* Return index when match is found */
        }
    }
    return -1; /* Return -1 if not found */
}

static void print_array(const int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
         LINEAR SEARCH ALGORITHM
========================================
Enter number of elements in array (1-100): 8
Enter 8 elements: 12 45 67 23 56 89 9 43

Array elements: 12 45 67 23 56 89 9 43

Enter the element to search: 45
Result: Element 45 found at index 1 (position 2).

Enter the element to search: 11
Result: Element 11 not found in the array.
===============================================================================
*/