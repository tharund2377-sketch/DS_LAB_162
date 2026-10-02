/*
===============================================================================
                     DATA STRUCTURES LABORATORY
===============================================================================

Experiment : 6
Title      : Implementation of AVL Tree
Language   : C
Standard   : C11
Status     : Reviewed & Verified

Description:
    Implements an AVL (Adelson-Velsky and Landis) self-balancing binary search
    tree. Maintains height balance factor within {-1, 0, +1} using single
    rotations (LL, RR) and double rotations (LR, RL).

Operations:
    1. Node Creation
    2. AVL Insertion with Rebalancing
    3. AVL Deletion with Rebalancing
    4. Rotations (Left and Right)
    5. Preorder & Inorder Traversals
    6. Safe Memory Cleanup

Complexity:
    Insertion  : O(log n)
    Deletion   : O(log n)
    Search     : O(log n)
    Traversal  : O(n)
    Space      : O(n)

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Function Prototypes */
static int max(int a, int b);
static int height(const struct Node *node);
static struct Node *create_node(int key);
static struct Node *right_rotate(struct Node *y);
static struct Node *left_rotate(struct Node *x);
static int get_balance(const struct Node *node);
static struct Node *insert_node(struct Node *node, int key);
static struct Node *min_value_node(struct Node *node);
static struct Node *delete_node(struct Node *root, int key);
static void print_preorder(const struct Node *root);
static void print_inorder(const struct Node *root);
static void free_tree(struct Node *root);

/* ========================================================================= */

int main(void) {
    struct Node *root = NULL;

    printf("========================================\n");
    printf("         AVL TREE IMPLEMENTATION\n");
    printf("========================================\n");

    /* Insert sample nodes into AVL Tree */
    const int keys[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    const int n = (int)(sizeof(keys) / sizeof(keys[0]));

    printf("Inserting keys: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", keys[i]);
        root = insert_node(root, keys[i]);
    }
    printf("\n\n");

    printf("Preorder traversal of constructed AVL tree:\n");
    print_preorder(root);
    printf("\n\n");

    printf("Inorder traversal (sorted verification):\n");
    print_inorder(root);
    printf("\n\n");

    /* Delete key 10 */
    printf("Deleting key: 10\n");
    root = delete_node(root, 10);

    printf("Preorder traversal after deletion of 10:\n");
    print_preorder(root);
    printf("\n\n");

    printf("Inorder traversal after deletion:\n");
    print_inorder(root);
    printf("\n\n");

    /* Free all allocated tree memory */
    free_tree(root);
    root = NULL;
    printf("AVL tree memory deallocated successfully.\n");

    return EXIT_SUCCESS;
}

/* ========================================================================= */

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int height(const struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

static struct Node *create_node(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; /* New node initialized at height 1 */
    return node;
}

static struct Node *right_rotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    /* Perform rotation */
    x->right = y;
    y->left = T2;

    /* Update heights */
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    /* Return new root */
    return x;
}

static struct Node *left_rotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    /* Perform rotation */
    y->left = x;
    x->right = T2;

    /* Update heights */
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    /* Return new root */
    return y;
}

static int get_balance(const struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

static struct Node *insert_node(struct Node *node, int key) {
    /* 1. Perform normal BST insertion */
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    else
        return node; /* Duplicate keys not permitted */

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get balance factor to check whether node became unbalanced */
    int balance = get_balance(node);

    /* Left-Left Case */
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    /* Right-Right Case */
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    /* Left-Right Case */
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    /* Right-Left Case */
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

static struct Node *min_value_node(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

static struct Node *delete_node(struct Node *root, int key) {
    /* 1. Perform standard BST delete */
    if (root == NULL)
        return root;

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);
    } else {
        /* Node with only one child or no child */
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                /* No child case */
                temp = root;
                root = NULL;
            } else {
                /* One child case */
                *root = *temp;
            }
            free(temp);
        } else {
            /* Node with two children: get inorder successor */
            struct Node *temp = min_value_node(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    /* 2. Update height of current node */
    root->height = 1 + max(height(root->left), height(root->right));

    /* 3. Rebalance the node if necessary */
    int balance = get_balance(root);

    /* Left-Left Case */
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    /* Left-Right Case */
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    /* Right-Right Case */
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    /* Right-Left Case */
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

static void print_preorder(const struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

static void print_inorder(const struct Node *root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("%d ", root->key);
        print_inorder(root->right);
    }
}

static void free_tree(struct Node *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

/*
===============================================================================
                               SAMPLE OUTPUT
===============================================================================
Preorder traversal of constructed AVL tree:
9 1 0 -1 5 2 6 10 11

Inorder traversal (sorted verification):
-1 0 1 2 5 6 9 10 11

Deleting key: 10
Preorder traversal after deletion of 10:
1 0 -1 9 5 2 6 11

Inorder traversal after deletion:
-1 0 1 2 5 6 9 11
===============================================================================
*/