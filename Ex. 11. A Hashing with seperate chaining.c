/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 11.A
Title      : Hashing with Separate Chaining
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements a Hash Table using the division modulo hash function:
    h(k) = k % TABLE_SIZE. Handles collisions via Separate Chaining (closed
    addressing) by chaining colliding keys in dynamically allocated singly
    linked lists at each bucket.

Operations:
    1. Insert Key into Hash Table
    2. Display Hash Table Buckets
    3. Search for Key
    4. Safe Memory Cleanup & Exit

Complexity:
    Average Insert Time : O(1)
    Average Search Time : O(1 + alpha) where alpha = n / TABLE_SIZE
    Worst Case Time     : O(n) (all keys hash to the same bucket)
    Space Complexity    : O(m + n) where m is table size and n is key count

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

/* Node structure for chaining */
struct Node {
    int data;
    struct Node *next;
};

/* Hash Table array of bucket heads */
static struct Node *head[TABLE_SIZE] = {NULL};

/* Function Prototypes */
static int hash_function(int key);
static void insert(int val);
static int search(int val);
static void display(void);
static void free_table(void);

/* ========================================================================= */

int main(void) {
    int choice, val;

    while (1) {
        printf("\n========================================\n");
        printf("    HASHING WITH SEPARATE CHAINING\n");
        printf("========================================\n");
        printf("1. Insert Key\n");
        printf("2. Display Hash Table\n");
        printf("3. Search Key\n");
        printf("4. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert into hash table: ");
                if (scanf("%d", &val) == 1) {
                    insert(val);
                } else {
                    printf("Invalid value.\n");
                }
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter value to search: ");
                if (scanf("%d", &val) == 1) {
                    int bucket = search(val);
                    if (bucket != -1) {
                        printf("Key %d found in bucket index %d.\n", val, bucket);
                    } else {
                        printf("Key %d not found in hash table.\n", val);
                    }
                }
                break;

            case 4:
                printf("Deallocating hash table and exiting...\n");
                free_table();
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice. Please enter 1-4.\n");
        }
    }

    free_table();
    return EXIT_SUCCESS;
}

/* ========================================================================= */

static int hash_function(int key) {
    int idx = key % TABLE_SIZE;
    if (idx < 0)
        idx += TABLE_SIZE;
    return idx;
}

static void insert(int val) {
    int i = hash_function(val);

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = val;
    new_node->next = NULL;

    if (head[i] == NULL) {
        head[i] = new_node;
    } else {
        /* Append at the end of the chain */
        struct Node *c = head[i];
        while (c->next != NULL) {
            c = c->next;
        }
        c->next = new_node;
    }
    printf("Inserted %d at bucket index %d.\n", val, i);
}

static int search(int val) {
    int i = hash_function(val);
    struct Node *c = head[i];

    while (c != NULL) {
        if (c->data == val)
            return i;
        c = c->next;
    }
    return -1;
}

static void display(void) {
    printf("\nHash Table Contents:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket [%d]: ", i);
        struct Node *temp = head[i];
        if (temp == NULL) {
            printf("Empty\n");
        } else {
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
    printf("----------------------------------------\n");
}

static void free_table(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node *temp = head[i];
        while (temp != NULL) {
            struct Node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
        head[i] = NULL;
    }
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
========================================
    HASHING WITH SEPARATE CHAINING
========================================
1. Insert Key
2. Display Hash Table
3. Search Key
4. Exit
----------------------------------------
Enter your choice: 1
Enter value to insert into hash table: 12
Inserted 12 at bucket index 5.

Enter your choice: 1
Enter value to insert into hash table: 7
Inserted 7 at bucket index 0.

Enter your choice: 1
Enter value to insert into hash table: 3
Inserted 3 at bucket index 3.

Enter your choice: 2
Hash Table Contents:
----------------------------------------
Bucket [0]: 7 -> NULL
Bucket [1]: Empty
Bucket [2]: Empty
Bucket [3]: 3 -> NULL
Bucket [4]: Empty
Bucket [5]: 12 -> NULL
Bucket [6]: Empty
----------------------------------------

Enter your choice: 4
Deallocating hash table and exiting...
===============================================================================
*/