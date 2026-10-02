# Data Structures Laboratory in C

A comprehensive, production-grade collection of **Data Structures Laboratory programs** implemented in **C (C11)**. This repository covers fundamental Abstract Data Types (ADTs), linear structures, trees, graphs, priority queues, searching, sorting, hashing techniques, and practical applications required for undergraduate Computer Science and Engineering laboratory curricula.

The repository focuses on **algorithmic correctness, clean modular design, robust edge-case handling, and readable documentation**, making it an ideal companion for practical examinations, laboratory records, viva preparation, and portfolio showcase.

---

## Index of Experiments

| Experiment | Title | Category / Data Structure | Source File |
|:---|:---|:---|:---|
| **Ex 1.A** | Array Implementation of List ADT | List ADT (Static Array) | [`Ex_1A_Array_Implementation_of_List_ADT.c`](Ex_1A_Array_Implementation_of_List_ADT.c) |
| **Ex 1.B** | Implementation of Singly Linked List | Linked List (Dynamic) | [`Ex_1B_Implementation_of_Singly_Linked_List.c`](Ex_1B_Implementation_of_Singly_Linked_List.c) |
| **Ex 2** | Implementation of Circular Linked List | Circular Linked List | [`Ex_2_Implementation_of_Circular_Linked_List.c`](Ex_2_Implementation_of_Circular_Linked_List.c) |
| **Ex 3.A** | Array Implementation of Stack | Stack (LIFO - Array) | [`Ex_3A_Array_Implementation_of_Stack.c`](Ex_3A_Array_Implementation_of_Stack.c) |
| **Ex 3.B** | Array Implementation of Queue | Circular Queue (FIFO - Array) | [`Ex_3B_Array_Implementation_of_Queue.c`](Ex_3B_Array_Implementation_of_Queue.c) |
| **Ex 4.A** | Linked List Implementation of Stack | Stack (LIFO - Linked List) | [`Ex_4A_Linked_List_Implementation_of_Stack.c`](Ex_4A_Linked_List_Implementation_of_Stack.c) |
| **Ex 4.B** | Linked List Implementation of Queue | Queue (FIFO - Linked List) | [`Ex_4B_Linked_List_Implementation_of_Queue.c`](Ex_4B_Linked_List_Implementation_of_Queue.c) |
| **Ex 5** | Binary Search Tree | Tree (BST Operations & Traversals) | [`Ex_5_Binary_Search_Tree.c`](Ex_5_Binary_Search_Tree.c) |
| **Ex 6** | Implementation of AVL Tree | Self-Balancing BST (Rotations) | [`Ex. 6 Implementation of AVL Tree.c`](Ex.%206%20Implementation%20of%20AVL%20Tree.c) |
| **Ex 7.A** | Breadth First Search (BFS) | Graph Traversal (Queue-based) | [`Ex. 7.A Breadth First Search.c`](Ex.%207.A%20Breadth%20First%20Search.c) |
| **Ex 7.B** | Depth First Search (DFS) | Graph Traversal (Recursive) | [`Ex. 7.B Depth First Search.c`](Ex.%207.B%20Depth%20First%20Search.c) |
| **Ex 8** | Applications of Graph (Dijkstra's Algorithm) | Shortest Path (Greedy Graph) | [`Ex. 8 Applications of Graph.c`](Ex.%208%20Applications%20of%20Graph.c) |
| **Ex 9** | Implementation of Priority Queue | Heap (Binary Min-Heap) | [`Ex. 9 Implementation of Priority Queue.c`](Ex.%209%20Implementation%20of%20Priority%20Queue.c) |
| **Ex 10.A** | Linear Search | Searching Algorithm | [`Ex. 10 A Linear Search.c`](Ex.%2010%20A%20Linear%20Search.c) |
| **Ex 10.B** | Binary Search | Searching Algorithm (Divide & Conquer) | [`Ex. 10 B Binary Search.c`](Ex.%2010%20B%20Binary%20Search.c) |
| **Ex 10.C** | Insertion Sort | Sorting Algorithm (Comparison) | [`Ex. 10. C Insertion Sort.c`](Ex.%2010.%20C%20Insertion%20Sort.c) |
| **Ex 10.D** | Quick Sort | Sorting Algorithm (Divide & Conquer) | [`Ex. 10. D Quick Sort.c`](Ex.%2010.%20D%20Quick%20Sort.c) |
| **Ex 11.A** | Hashing with Separate Chaining | Hash Table (Closed Addressing) | [`Ex. 11. A Hashing with seperate chaining.c`](Ex.%2011.%20A%20Hashing%20with%20seperate%20chaining.c) |
| **Ex 11.B** | Hashing with Open Addressing | Hash Table (Linear Probing) | [`Ex. 11.B Hashing with open addressing.c`](Ex.%2011.B%20Hashing%20with%20open%20addressing.c) |
| **Ex 12** | Student Record System | Structures & Application Data Processing | [`Ex.12 Student Record System.c`](Ex.12%20Student%20Record%20System.c) |

---

## Repository Structure

```text
DS_Lab/
├── README.md
├── Ex_1A_Array_Implementation_of_List_ADT.c
├── Ex_1B_Implementation_of_Singly_Linked_List.c
├── Ex_2_Implementation_of_Circular_Linked_List.c
├── Ex_3A_Array_Implementation_of_Stack.c
├── Ex_3B_Array_Implementation_of_Queue.c
├── Ex_4A_Linked_List_Implementation_of_Stack.c
├── Ex_4B_Linked_List_Implementation_of_Queue.c
├── Ex_5_Binary_Search_Tree.c
├── Ex. 6 Implementation of AVL Tree.c
├── Ex. 7.A Breadth First Search.c
├── Ex. 7.B Depth First Search.c
├── Ex. 8 Applications of Graph.c
├── Ex. 9 Implementation of Priority Queue.c
├── Ex. 10 A Linear Search.c
├── Ex. 10 B Binary Search.c
├── Ex. 10. C Insertion Sort.c
├── Ex. 10. D Quick Sort.c
├── Ex. 11. A Hashing with seperate chaining.c
├── Ex. 11.B Hashing with open addressing.c
└── Ex.12 Student Record System.c
```

---

## Program Explanations

### 1. Linear Data Structures (Lists, Stacks, & Queues)

#### Ex 1.A: Array Implementation of List ADT
- **File:** [`Ex_1A_Array_Implementation_of_List_ADT.c`](Ex_1A_Array_Implementation_of_List_ADT.c)
- **Description:** Implements the List Abstract Data Type using a contiguous fixed-size array. Supports list creation, element insertion at any 1-based index (with element shifting), deletion by position, linear searching, and display.
- **Key Operations:** `create()`, `insert(pos, val)`, `delete(pos)`, `search(key)`, `display()`.
- **Complexity:** Insertion/Deletion: $O(n)$, Search: $O(n)$, Access: $O(1)$.

#### Ex 1.B: Singly Linked List
- **File:** [`Ex_1B_Implementation_of_Singly_Linked_List.c`](Ex_1B_Implementation_of_Singly_Linked_List.c)
- **Description:** Implements a dynamic singly linked list using heap-allocated nodes (`data`, `next`). Provides constant-time head insertion, tail insertion, position-based deletion with pointer rewiring, sequential search, and graceful memory deallocation on exit.
- **Key Operations:** `insert_beginning(val)`, `insert_end(val)`, `delete_position(pos)`, `search(val)`, `traverse()`.
- **Complexity:** Insert at Head: $O(1)$, Insert at Tail: $O(n)$, Deletion: $O(n)$, Search: $O(n)$.

#### Ex 2: Circular Linked List
- **File:** [`Ex_2_Implementation_of_Circular_Linked_List.c`](Ex_2_Implementation_of_Circular_Linked_List.c)
- **Description:** Implements a singly circular linked list where the terminal node connects back to the head node. Features end insertion, value-based deletion (correctly preserving cycle integrity across empty, single-node, head, and internal node states), searching, and cyclic traversal.
- **Key Operations:** `insert_end(val)`, `delete_value(val)`, `search(val)`, `display()`, `free_list()`.
- **Complexity:** Insertion: $O(n)$, Deletion: $O(n)$, Search: $O(n)$.

#### Ex 3.A: Array Implementation of Stack
- **File:** [`Ex_3A_Array_Implementation_of_Stack.c`](Ex_3A_Array_Implementation_of_Stack.c)
- **Description:** Implements a Last-In, First-Out (LIFO) stack using a fixed-size array and a `top` cursor. Fully guards against stack overflow (when `top == MAX - 1`) and stack underflow (when `top == -1`).
- **Key Operations:** `push(x)`, `pop()`, `peek()`, `display()`.
- **Complexity:** Push: $O(1)$, Pop: $O(1)$, Peek: $O(1)$, Space: $O(n)$.

#### Ex 3.B: Array Implementation of Queue (Circular Queue)
- **File:** [`Ex_3B_Array_Implementation_of_Queue.c`](Ex_3B_Array_Implementation_of_Queue.c)
- **Description:** Implements a First-In, First-Out (FIFO) queue utilizing a circular array buffer with `front`, `rear`, and `count`. Circular index arithmetic (`(rear + 1) % MAX`) prevents the false overflow limitation of linear queues.
- **Key Operations:** `enqueue(x)`, `dequeue()`, `peek()`, `display()`.
- **Complexity:** Enqueue: $O(1)$, Dequeue: $O(1)$, Peek: $O(1)$, Space: $O(n)$.

#### Ex 4.A: Linked List Implementation of Stack
- **File:** [`Ex_4A_Linked_List_Implementation_of_Stack.c`](Ex_4A_Linked_List_Implementation_of_Stack.c)
- **Description:** Implements a dynamic LIFO stack where `top` points to the head of a singly linked list. Eliminates capacity constraints while guaranteeing safe memory cleanup upon exit.
- **Key Operations:** `push(val)`, `pop()`, `peek()`, `display()`, `free_stack()`.
- **Complexity:** Push: $O(1)$, Pop: $O(1)$, Peek: $O(1)$, Space: $O(n)$.

#### Ex 4.B: Linked List Implementation of Queue
- **File:** [`Ex_4B_Linked_List_Implementation_of_Queue.c`](Ex_4B_Linked_List_Implementation_of_Queue.c)
- **Description:** Implements a dynamic FIFO queue maintained by two pointers: `front` (for removal) and `rear` (for insertion). Guarantees true constant-time enqueue and dequeue operations without capacity bounds.
- **Key Operations:** `enqueue(val)`, `dequeue()`, `peek()`, `display()`, `free_queue()`.
- **Complexity:** Enqueue: $O(1)$, Dequeue: $O(1)$, Peek: $O(1)$, Space: $O(n)$.

---

### 2. Tree Structures (BST & AVL Tree)

#### Ex 5: Binary Search Tree (BST)
- **File:** [`Ex_5_Binary_Search_Tree.c`](Ex_5_Binary_Search_Tree.c)
- **Description:** Implements a non-linear hierarchical Binary Search Tree. Enforces the ordering invariant where all left-subtree keys are smaller and right-subtree keys are larger than the root. Supports batch node insertion, duplicate rejection, key searching, and recursive tree traversals.
- **Traversals:**
  - **Inorder:** Left $\to$ Root $\to$ Right (produces keys in sorted order)
  - **Preorder:** Root $\to$ Left $\to$ Right
  - **Postorder:** Left $\to$ Right $\to$ Root
- **Complexity:** Average Search/Insert: $O(\log n)$, Worst Case (skewed): $O(n)$, Traversals: $O(n)$.

#### Ex 6: Implementation of AVL Tree
- **File:** [`Ex. 6 Implementation of AVL Tree.c`](Ex.%206%20Implementation%20of%20AVL%20Tree.c)
- **Description:** Implements an Adelson-Velsky and Landis (AVL) self-balancing binary search tree. Each node tracks its height, and balance factors are recalculated after every insertion and deletion:
  $$\text{Balance Factor} = \text{height}(\text{left}) - \text{height}(\text{right})$$
  When a node becomes unbalanced ($\text{BF} \notin \{-1, 0, 1\}$), one of four rotation algorithms is applied to restore height balance in $O(1)$ time.
- **Rotations Supported:**
  - **Left-Left (LL):** Single Right Rotation (`rightRotate`)
  - **Right-Right (RR):** Single Left Rotation (`leftRotate`)
  - **Left-Right (LR):** Left Rotation on child followed by Right Rotation on root
  - **Right-Left (RL):** Right Rotation on child followed by Left Rotation on root
- **Complexity:** Search, Insert, and Delete strictly bounded to $O(\log n)$ even in the worst case.

---

### 3. Graphs and Graph Algorithms

#### Ex 7.A: Breadth First Search (BFS)
- **File:** [`Ex. 7.A Breadth First Search.c`](Ex.%207.A%20Breadth%20First%20Search.c)
- **Description:** Implements Breadth First Search graph traversal using an adjacency list and an explicit FIFO queue. Explores vertices level-by-level starting from a designated source, marking each vertex in a `visited` array to prevent cycles.
- **Key Operations:** `createGraph()`, `addEdge()`, `enqueue()`, `dequeue()`, `bfs(startVertex)`.
- **Complexity:** Time: $O(V + E)$, Space: $O(V)$.

#### Ex 7.B: Depth First Search (DFS)
- **File:** [`Ex. 7.B Depth First Search.c`](Ex.%207.B%20Depth%20First%20Search.c)
- **Description:** Implements Depth First Search graph traversal on an adjacency list using recursion (system call stack). Visits unvisited neighbor vertices deeply along each branch before backtracking.
- **Key Operations:** `createGraph()`, `addEdge()`, `DFS(vertex)`.
- **Complexity:** Time: $O(V + E)$, Space: $O(V)$ auxiliary stack space.

#### Ex 8: Applications of Graph (Dijkstra's Algorithm)
- **File:** [`Ex. 8 Applications of Graph.c`](Ex.%208%20Applications%20of%20Graph.c)
- **Description:** Implements Dijkstra's Single-Source Shortest Path algorithm on a directed/undirected weighted graph represented as a cost adjacency matrix. Uses a greedy strategy to find the shortest distance from a start vertex to all other vertices and reconstructs the full path tree using a `parent[]` array.
- **Key Operations:** Distance relaxation: `if (dist[u] + cost < dist[v]) dist[v] = dist[u] + cost`.
- **Complexity:** Time: $O(V^2)$ with adjacency matrix, Space: $O(V)$.

---

### 4. Priority Queues & Heaps

#### Ex 9: Implementation of Priority Queue (Min-Heap)
- **File:** [`Ex. 9 Implementation of Priority Queue.c`](Ex.%209%20Implementation%20of%20Priority%20Queue.c)
- **Description:** Implements a Priority Queue using an array-backed binary min-heap where the root element is always the minimum key. Supports insertion via upward percolation (percolate up) and minimum extraction via downward percolation (percolate down).
- **Key Operations:**
  - `insert(x)`: Appends to heap and bubbles up to restore heap order ($O(\log n)$).
  - `deletemin()`: Extracts root element, moves the last element to root, and sifts down ($O(\log n)$).
  - `display()`: Prints internal heap array order.
- **Complexity:** Insert: $O(\log n)$, Extract Min: $O(\log n)$, Find Min: $O(1)$.

---

### 5. Searching Algorithms

#### Ex 10.A: Linear Search
- **File:** [`Ex. 10 A Linear Search.c`](Ex.%2010%20A%20Linear%20Search.c)
- **Description:** Implements sequential linear search over an array. Checks every element from index $0$ to $n-1$ until the target key is discovered or the end of the array is reached. Works on both sorted and unsorted collections.
- **Complexity:** Best Case: $O(1)$ (key at index 0), Worst/Average Case: $O(n)$, Auxiliary Space: $O(1)$.

#### Ex 10.B: Binary Search
- **File:** [`Ex. 10 B Binary Search.c`](Ex.%2010%20B%20Binary%20Search.c)
- **Description:** Implements binary search on a sorted array using the divide-and-conquer strategy. Iteratively halves the active search window by comparing the target with `arr[mid]`, setting `low = mid + 1` or `high = mid - 1`.
- **Complexity:** Best Case: $O(1)$, Worst/Average Case: $O(\log n)$, Space: $O(1)$.

---

### 6. Sorting Algorithms

#### Ex 10.C: Insertion Sort
- **File:** [`Ex. 10. C Insertion Sort.c`](Ex.%2010.%20C%20Insertion%20Sort.c)
- **Description:** Implements the in-place comparison-based insertion sort. Divides the array conceptually into sorted and unsorted partitions. In each iteration, takes the next unsorted element and shifts larger elements in the sorted partition one position right to insert the key into its correct relative position.
- **Characteristics:** Stable, adaptive, minimal overhead on nearly-sorted data.
- **Complexity:** Best Case (already sorted): $O(n)$, Worst/Average Case: $O(n^2)$, Auxiliary Space: $O(1)$.

#### Ex 10.D: Quick Sort
- **File:** [`Ex. 10. D Quick Sort.c`](Ex.%2010.%20D%20Quick%20Sort.c)
- **Description:** Implements the divide-and-conquer quick sort algorithm using Lomuto partitioning. Selects the last element as the pivot, partitions the array such that all elements $\le \text{pivot}$ are on the left and elements $> \text{pivot}$ are on the right, then recursively sorts both partitions.
- **Key Operations:** `partition(arr, low, high)`, `quickSort(arr, low, high)`.
- **Complexity:** Best/Average Case: $O(n \log n)$, Worst Case (unbalanced partitions): $O(n^2)$, Auxiliary Space: $O(\log n)$ recursive stack.

---

### 7. Hashing Techniques

#### Ex 11.A: Hashing with Separate Chaining
- **File:** [`Ex. 11. A Hashing with seperate chaining.c`](Ex.%2011.%20A%20Hashing%20with%20seperate%20chaining.c)
- **Description:** Implements a Hash Table using the division modulo hash function $h(k) = k \bmod \text{TABLE\_SIZE}$ with Separate Chaining (closed addressing). Collisions are handled by creating dynamic singly linked lists at each bucket header, allowing multiple records per bucket without table size restrictions.
- **Complexity:** Average Insert/Search: $O(1 + \alpha)$ where $\alpha = \frac{n}{m}$ is the load factor. Worst Case: $O(n)$ if all keys hash to the same bucket.

#### Ex 11.B: Hashing with Open Addressing
- **File:** [`Ex. 11.B Hashing with open addressing.c`](Ex.%2011.B%20Hashing%20with%20open%20addressing.c)
- **Description:** Implements a closed hash table using Linear Probing (open addressing). When a collision occurs at index $h(k)$, it sequentially probes $(h(k) + i) \bmod \text{size}$ until an empty slot is located. Deletion utilizes a tombstone marker (`INT_MAX`) so subsequent probes in a search chain are not broken.
- **Key Operations:** `insert()`, `delete()` (with tombstone), `search()`, `display()`.
- **Complexity:** Average Insert/Search/Delete: $O\left(\frac{1}{1 - \alpha}\right)$, Worst Case: $O(n)$.

---

### 8. Applied Real-World Systems

#### Ex 12: Student Record System
- **File:** [`Ex.12 Student Record System.c`](Ex.12%20Student%20Record%20System.c)
- **Description:** Demonstrates real-world application of user-defined data structures (`struct Student`). Reads student profiles (name, roll number, and 3 subject marks), computes overall totals, determines the highest scorer in each individual subject, and finds the student with the overall maximum score.
- **Key Concepts:** Structures, array of structures, aggregate calculations, multi-criteria scanning.

---

## Time and Space Complexity Summary

| Experiment | Program / Algorithm | Best Time | Average Time | Worst Time | Space Complexity |
|:---|:---|:---:|:---:|:---:|:---:|
| **Ex 1.A** | List ADT (Array) | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Ex 1.B** | Singly Linked List | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Ex 2** | Circular Linked List | $O(1)$ | $O(n)$ | $O(n)$ | $O(n)$ |
| **Ex 3.A** | Stack (Array) | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Ex 3.B** | Circular Queue (Array) | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Ex 4.A** | Stack (Linked List) | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Ex 4.B** | Queue (Linked List) | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ |
| **Ex 5** | Binary Search Tree | $O(\log n)$ | $O(\log n)$ | $O(n)$ | $O(n)$ |
| **Ex 6** | AVL Tree | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| **Ex 7.A** | Breadth First Search | $O(V + E)$ | $O(V + E)$ | $O(V + E)$ | $O(V)$ |
| **Ex 7.B** | Depth First Search | $O(V + E)$ | $O(V + E)$ | $O(V + E)$ | $O(V)$ |
| **Ex 8** | Dijkstra's Algorithm | $O(V^2)$ | $O(V^2)$ | $O(V^2)$ | $O(V^2)$ |
| **Ex 9** | Priority Queue (Min-Heap) | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(n)$ |
| **Ex 10.A** | Linear Search | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ |
| **Ex 10.B** | Binary Search | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ |
| **Ex 10.C** | Insertion Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| **Ex 10.D** | Quick Sort | $O(n \log n)$ | $O(n \log n)$ | $O(n^2)$ | $O(\log n)$ |
| **Ex 11.A** | Hashing (Separate Chaining) | $O(1)$ | $O(1 + \alpha)$ | $O(n)$ | $O(m + n)$ |
| **Ex 11.B** | Hashing (Open Addressing) | $O(1)$ | $O(1)$ | $O(n)$ | $O(m)$ |
| **Ex 12** | Student Record System | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ |

---

## Compilation and Execution

All programs are written in standard C and can be compiled using any modern GCC / Clang toolchain on Windows, Linux, or macOS.

### Using GCC (MinGW / Linux / macOS)

To compile any source file with warnings enabled:

```bash
# General syntax
gcc -std=c11 -Wall -Wextra -O2 "filename.c" -o program

# Run executable
# On Windows (PowerShell/CMD):
.\program.exe

# On Linux / macOS:
./program
```

### Examples

**1. AVL Tree (Ex 6):**
```powershell
gcc -std=c11 -Wall -Wextra -O2 "Ex. 6 Implementation of AVL Tree.c" -o Ex_6_AVL.exe
.\Ex_6_AVL.exe
```

**2. Dijkstra's Algorithm (Ex 8):**
```powershell
gcc -std=c11 -Wall -Wextra -O2 "Ex. 8 Applications of Graph.c" -o Ex_8_Graph.exe
.\Ex_8_Graph.exe
```

**3. Quick Sort (Ex 10.D):**
```powershell
gcc -std=c11 -Wall -Wextra -O2 "Ex. 10. D Quick Sort.c" -o Ex_10D_QuickSort.exe
.\Ex_10D_QuickSort.exe
```

---

## Learning Outcomes

Upon completing and studying these experiments, one will develop practical mastery in:
- Abstract Data Types (ADT) specifications and concrete implementations.
- Pointer mechanics and dynamic memory management with `malloc()` and `free()`.
- Trade-offs between array-based (contiguous) and pointer-based (linked) representations.
- Self-balancing tree rotations and invariant preservation (AVL trees).
- Graph modeling with adjacency matrices and adjacency lists, as well as level-order and depth-first exploration.
- Greedy algorithm formulation for single-source shortest path problems.
- Heap properties and priority queue operations.
- Comparative analysis of searching and sorting algorithms.
- Collision resolution strategies in hash tables (chaining vs. open addressing).

---

## Author & Academic Purpose

- **Author:** Thamizh Selvan
- **Department:** Computer Science & Engineering
- **Purpose:** Data Structures & Algorithms Laboratory coursework, practical exam preparation, and reference.
- **License:** Educational and open academic use.
