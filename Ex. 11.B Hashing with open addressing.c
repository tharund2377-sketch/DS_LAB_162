/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 11.B
Title      : Hashing with Open Addressing (Linear Probing)
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements a closed Hash Table using Linear Probing for collision
    resolution: h'(k, i) = (h(k) + i) % TABLE_SIZE. Uses sentinel values
    EMPTY (INT_MIN) and DELETED (INT_MAX) to maintain search probe sequences.

Operations:
    1. Insert Key
    2. Delete Key (Tombstone Marker)
    3. Display Table Slots
    4. Search Key

Complexity:
    Average Time     : O(1 / (1 - alpha)) where alpha is load factor
    Worst Case Time  : O(n) when table is densely clustered
    Space Complexity : O(TABLE_SIZE) static array storage

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TABLE_SIZE 5
#define EMPTY INT_MIN
#define DELETED INT_MAX

/* Function Prototypes */
static void initialize_table(int table[], int size);
static void insert_element(int table[], int size);
static void delete_element(int table[], int size);
static void search_element(const int table[], int size);
static void display_table(const int table[], int size);

/* ========================================================================= */

int main(void) {
    int table[TABLE_SIZE];
    int choice;

    initialize_table(table, TABLE_SIZE);

    while (1) {
        printf("\n========================================\n");
        printf("   HASHING WITH OPEN ADDRESSING\n");
        printf("========================================\n");
        printf("1 -> Insert Key\n");
        printf("2 -> Delete Key\n");
        printf("3 -> Display Hash Table\n");
        printf("4 -> Search Key\n");
        printf("0 -> Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                insert_element(table, TABLE_SIZE);
                break;

            case 2:
                delete_element(table, TABLE_SIZE);
                break;

            case 3:
                display_table(table, TABLE_SIZE);
                break;

            case 4:
                search_element(table, TABLE_SIZE);
                break;

            case 0:
                printf("Exiting program...\n");
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice! Please select 0-4.\n");
        }
    }

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static void initialize_table(int table[], int size) {
    for (int i = 0; i < size; ++i) {
        table[i] = EMPTY;
    }
}

static void insert_element(int table[], int size) {
    int element, pos, count = 0;

    printf("Enter key element to insert: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid element.\n");
        return;
    }

    pos = abs(element) % size;

    while (table[pos] != EMPTY && table[pos] != DELETED) {
        pos = (pos + 1) % size;
        count++;
        if (count == size) {
            printf("Hash table is full. Cannot insert element.\n");
            return;
        }
    }

    table[pos] = element;
    printf("Element %d successfully inserted at index %d.\n", element, pos);
}

static void delete_element(int table[], int size) {
    int element, pos, count = 0;

    printf("Enter element to delete: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid input.\n");
        return;
    }

    pos = abs(element) % size;

    while (count < size) {
        if (table[pos] == EMPTY) {
            printf("Element %d not found in hash table.\n", element);
            return;
        } else if (table[pos] == element) {
            table[pos] = DELETED; /* Mark slot with tombstone */
            printf("Element %d deleted from index %d.\n", element, pos);
            return;
        }
        pos = (pos + 1) % size;
        count++;
    }

    printf("Element %d not found in hash table.\n", element);
}

static void search_element(const int table[], int size) {
    int element, pos, count = 0;

    printf("Enter element to search: ");
    if (scanf("%d", &element) != 1) {
        printf("Invalid input.\n");
        return;
    }

    pos = abs(element) % size;

    while (count < size) {
        if (table[pos] == EMPTY) {
            printf("Element %d not found in hash table.\n", element);
            return;
        } else if (table[pos] == element) {
            printf("Element %d found at index %d.\n", element, pos);
            return;
        }
        pos = (pos + 1) % size;
        count++;
    }

    printf("Element %d not found in hash table.\n", element);
}

static void display_table(const int table[], int size) {
    printf("\nIndex\tValue\n");
    printf("------------------------\n");
    for (int i = 0; i < size; i++) {
        if (table[i] == EMPTY) {
            printf("%d\tEmpty\n", i);
        } else if (table[i] == DELETED) {
            printf("%d\tDeleted (Tombstone)\n", i);
        } else {
            printf("%d\t%d\n", i, table[i]);
        }
    }
    printf("------------------------\n");
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
   HASHING WITH OPEN ADDRESSING
========================================
1 -> Insert Key
2 -> Delete Key
3 -> Display Hash Table
4 -> Search Key
0 -> Exit
----------------------------------------
Enter your choice: 1
Enter key element to insert: 25
Element 25 successfully inserted at index 0.

Enter your choice: 1
Enter key element to insert: 20
Element 20 successfully inserted at index 1.

Enter your choice: 3
Index   Value
------------------------
0       25
1       20
2       Empty
3       Empty
4       Empty
------------------------

Enter your choice: 2
Enter element to delete: 20
Element 20 deleted from index 1.

Enter your choice: 3
Index   Value
------------------------
0       25
1       Deleted (Tombstone)
2       Empty
3       Empty
4       Empty
------------------------

Enter your choice: 0
Exiting program...
===============================================================================
*/