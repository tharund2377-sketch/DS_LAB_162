/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 10.C
Title      : Implementation of Insertion Sort
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements the Insertion Sort algorithm. Builds the sorted array in-place
    one item at a time by repeatedly taking the next unsorted element and
    shifting larger elements in the sorted partition rightward to insert it.

Operations:
    1. Read Array
    2. In-Place Insertion Sort
    3. Display Sorted Array
    4. Menu-Driven Interface

Complexity:
    Best Case Time    : O(n) (already sorted array)
    Average Case Time : O(n^2)
    Worst Case Time   : O(n^2) (reverse sorted array)
    Space Complexity  : O(1) in-place auxiliary space

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Function Prototypes */
static void insertion_sort(int arr[], int n);
static void print_array(const int arr[], int n);

/* ========================================================================= */

int main(void) {
    int arr[MAX_SIZE];
    int n, choice;

    printf("========================================\n");
    printf("         INSERTION SORT ALGORITHM\n");
    printf("========================================\n");

    printf("Enter the number of elements (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_SIZE) {
        fprintf(stderr, "Error: Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: Invalid array element.\n");
            return EXIT_FAILURE;
        }
    }

    do {
        printf("\n----------------------------------------\n");
        printf("Menu:\n");
        printf("1. Sort using Insertion Sort\n");
        printf("2. Print the array\n");
        printf("3. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                insertion_sort(arr, n);
                printf("Array sorted successfully using Insertion Sort.\n");
                break;

            case 2:
                printf("Array elements: ");
                print_array(arr, n);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    } while (choice != 3);

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key to one position ahead */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
         INSERTION SORT ALGORITHM
========================================
Enter the number of elements (1-100): 4
Enter 4 elements:
1
56
23
78

Menu:
1. Sort using Insertion Sort
2. Print the array
3. Exit
Enter your choice: 1
Array sorted successfully using Insertion Sort.

Menu:
1. Sort using Insertion Sort
2. Print the array
3. Exit
Enter your choice: 2
Array elements: 1 23 56 78

Menu:
1. Sort using Insertion Sort
2. Print the array
3. Exit
Enter your choice: 3
Exiting the program.
===============================================================================
*/