# GitHub Issues for DSA Snippets Repository

This document contains 24 curated issues for contributors to work on. Copy these to your GitHub repository as individual issues.

## Sorting Algorithms (6 issues)

### Issue #1: Add Insertion Sort in Java
**Labels:** `algorithm`, `sorting`, `java`, `good first issue`
**Priority:** High
**Difficulty:** Beginner

Implement insertion sort algorithm in Java with the following requirements:
- Time complexity: O(n²) average and worst case, O(n) best case
- Space complexity: O(1)
- Include comprehensive comments explaining the algorithm
- Add example usage in main method
- Handle edge cases (empty array, single element)
- Create README.md with algorithm explanation

**Acceptance Criteria:**
- [ ] Core insertion sort implementation
- [ ] Proper Java coding standards
- [ ] Example usage with test cases
- [ ] Documentation with complexity analysis

---

### Issue #2: Add Merge Sort in C++
**Labels:** `algorithm`, `sorting`, `cpp`, `intermediate`
**Priority:** High
**Difficulty:** Intermediate

Implement merge sort algorithm in C++ with the following features:
- Divide and conquer approach
- Time complexity: O(n log n) in all cases
- Space complexity: O(n)
- Both recursive and iterative versions
- Template implementation for generic types

**Requirements:**
- [ ] Recursive merge sort implementation
- [ ] Iterative merge sort implementation
- [ ] Template-based generic implementation
- [ ] Performance comparison between versions
- [ ] Comprehensive test cases

---

### Issue #3: Add Heap Sort in Python
**Labels:** `algorithm`, `sorting`, `python`, `intermediate`
**Priority:** Medium
**Difficulty:** Intermediate

Implement heap sort algorithm in Python:
- Build max heap from input array
- Extract maximum elements to sort
- Time complexity: O(n log n)
- Space complexity: O(1)
- Include heap visualization functions

**Deliverables:**
- [ ] Heap sort implementation
- [ ] Heapify functions (max heap)
- [ ] Visualization helper functions
- [ ] Unit tests with pytest
- [ ] Performance benchmarking

---

### Issue #4: Add Radix Sort in Go
**Labels:** `algorithm`, `sorting`, `go`, `advanced`
**Priority:** Medium
**Difficulty:** Advanced

Implement radix sort algorithm in Go:
- Non-comparative sorting algorithm
- Time complexity: O(d × (n + k)) where d is digits, k is range
- Space complexity: O(n + k)
- Support for both integers and strings
- LSD (Least Significant Digit) approach

**Requirements:**
- [ ] Integer radix sort
- [ ] String radix sort
- [ ] Counting sort as subroutine
- [ ] Benchmarks against other sorting algorithms
- [ ] Comprehensive documentation

---

### Issue #5: Add Shell Sort in JavaScript
**Labels:** `algorithm`, `sorting`, `javascript`, `intermediate`
**Priority:** Low
**Difficulty:** Intermediate

Implement Shell sort algorithm in JavaScript:
- Generalization of insertion sort
- Multiple gap sequences (Shell, Knuth, Sedgewick)
- Time complexity varies by gap sequence
- In-place sorting algorithm

**Features:**
- [ ] Multiple gap sequence implementations
- [ ] Performance comparison of gap sequences
- [ ] ES6+ modern JavaScript syntax
- [ ] Jest unit tests
- [ ] Browser and Node.js compatibility

---

### Issue #6: Add Counting Sort in Rust
**Labels:** `algorithm`, `sorting`, `rust`, `intermediate`
**Priority:** Low
**Difficulty:** Intermediate

Implement counting sort algorithm in Rust:
- Non-comparative sorting algorithm
- Time complexity: O(n + k) where k is range
- Space complexity: O(k)
- Memory-safe Rust implementation
- Generic implementation for different integer types

**Requirements:**
- [ ] Basic counting sort
- [ ] Generic implementation
- [ ] Error handling for invalid ranges
- [ ] Comprehensive tests
- [ ] Documentation with examples

---

## Searching Algorithms (4 issues)

### Issue #7: Add Linear Search in Multiple Languages
**Labels:** `algorithm`, `searching`, `multi-language`, `good first issue`
**Priority:** High
**Difficulty:** Beginner

Implement linear search in C++, Python, Java, and JavaScript:
- Sequential search through array elements
- Time complexity: O(n)
- Space complexity: O(1)
- Find first occurrence and all occurrences versions

**Deliverables:**
- [ ] C++ implementation
- [ ] Python implementation
- [ ] Java implementation
- [ ] JavaScript implementation
- [ ] Consistent API across languages
- [ ] Performance comparison

---

### Issue #8: Add Ternary Search in Python
**Labels:** `algorithm`, `searching`, `python`, `intermediate`
**Priority:** Medium
**Difficulty:** Intermediate

Implement ternary search algorithm in Python:
- Divide and conquer search algorithm
- Time complexity: O(log₃ n)
- Works on unimodal functions
- Both recursive and iterative versions

**Features:**
- [ ] Recursive implementation
- [ ] Iterative implementation
- [ ] Find maximum in unimodal array
- [ ] Visualization of search process
- [ ] Comparison with binary search

---

### Issue #9: Add Exponential Search in Java
**Labels:** `algorithm`, `searching`, `java`, `intermediate`
**Priority:** Medium
**Difficulty:** Intermediate

Implement exponential search algorithm in Java:
- Combination of binary search and exponential growth
- Time complexity: O(log n)
- Effective for unbounded or infinite arrays
- Also known as doubling search or galloping search

**Requirements:**
- [ ] Core exponential search implementation
- [ ] Handle bounded and unbounded arrays
- [ ] Integration with binary search
- [ ] JUnit test cases
- [ ] Performance analysis

---

### Issue #10: Add Interpolation Search in C++
**Labels:** `algorithm`, `searching`, `cpp`, `advanced`
**Priority:** Low
**Difficulty:** Advanced

Implement interpolation search algorithm in C++:
- Improvement over binary search for uniformly distributed data
- Time complexity: O(log log n) average, O(n) worst case
- Uses interpolation formula to estimate position
- Template implementation for different data types

**Deliverables:**
- [ ] Template-based implementation
- [ ] Performance comparison with binary search
- [ ] Handle non-uniform distributions
- [ ] Comprehensive test suite
- [ ] Documentation with mathematical analysis

---

## Graph Algorithms (4 issues)

### Issue #11: Add Breadth-First Search (BFS) in Python
**Labels:** `algorithm`, `graph`, `python`, `intermediate`
**Priority:** High
**Difficulty:** Intermediate

Implement BFS algorithm in Python:
- Graph traversal algorithm
- Time complexity: O(V + E)
- Space complexity: O(V)
- Support for both adjacency list and matrix representations
- Find shortest path in unweighted graphs

**Features:**
- [ ] BFS traversal implementation
- [ ] Shortest path finding
- [ ] Support for both graph representations
- [ ] Visualization of traversal
- [ ] Level-order traversal variant

---

### Issue #12: Add Depth-First Search (DFS) in C++
**Labels:** `algorithm`, `graph`, `cpp`, `intermediate`
**Priority:** High
**Difficulty:** Intermediate

Implement DFS algorithm in C++:
- Graph traversal algorithm
- Time complexity: O(V + E)
- Space complexity: O(V)
- Both recursive and iterative implementations
- Detect cycles in directed and undirected graphs

**Requirements:**
- [ ] Recursive DFS implementation
- [ ] Iterative DFS implementation
- [ ] Cycle detection algorithms
- [ ] Topological sorting
- [ ] Connected components finding

---

### Issue #13: Add Dijkstra's Algorithm in Java
**Labels:** `algorithm`, `graph`, `java`, `advanced`
**Priority:** High
**Difficulty:** Advanced

Implement Dijkstra's shortest path algorithm in Java:
- Single-source shortest path algorithm
- Time complexity: O((V + E) log V) with priority queue
- Works with non-negative edge weights
- Priority queue optimization

**Deliverables:**
- [ ] Basic Dijkstra implementation
- [ ] Priority queue optimization
- [ ] Path reconstruction
- [ ] Support for different graph representations
- [ ] Comprehensive test cases with various graph types

---

### Issue #14: Add Kruskal's MST Algorithm in Go
**Labels:** `algorithm`, `graph`, `go`, `advanced`
**Priority:** Medium
**Difficulty:** Advanced

Implement Kruskal's Minimum Spanning Tree algorithm in Go:
- Greedy algorithm for finding MST
- Time complexity: O(E log E)
- Uses Union-Find data structure
- Works on weighted undirected graphs

**Features:**
- [ ] Kruskal's algorithm implementation
- [ ] Union-Find data structure
- [ ] Edge sorting and processing
- [ ] MST weight calculation
- [ ] Visualization of MST construction

---

## Dynamic Programming (4 issues)

### Issue #15: Add Fibonacci Sequence in Multiple Languages
**Labels:** `algorithm`, `dynamic-programming`, `multi-language`, `good first issue`
**Priority:** High
**Difficulty:** Beginner

Implement Fibonacci sequence in Python, Java, and C++:
- Multiple approaches: recursive, memoization, tabulation, matrix
- Time complexity analysis for each approach
- Space optimization techniques
- Handle large Fibonacci numbers

**Implementations:**
- [ ] Naive recursive approach
- [ ] Memoization (top-down DP)
- [ ] Tabulation (bottom-up DP)
- [ ] Space-optimized version
- [ ] Matrix exponentiation method

---

### Issue #16: Add Longest Common Subsequence (LCS) in Python
**Labels:** `algorithm`, `dynamic-programming`, `python`, `intermediate`
**Priority:** High
**Difficulty:** Intermediate

Implement LCS algorithm in Python:
- Classic dynamic programming problem
- Time complexity: O(m × n)
- Space complexity: O(m × n), optimizable to O(min(m, n))
- Reconstruct the actual LCS string

**Requirements:**
- [ ] Basic LCS length calculation
- [ ] LCS string reconstruction
- [ ] Space-optimized version
- [ ] Multiple string LCS variant
- [ ] Visualization of DP table

---

### Issue #17: Add 0/1 Knapsack Problem in Java
**Labels:** `algorithm`, `dynamic-programming`, `java`, `intermediate`
**Priority:** Medium
**Difficulty:** Intermediate

Implement 0/1 Knapsack problem in Java:
- Classic optimization problem
- Time complexity: O(n × W)
- Space complexity: O(n × W), optimizable to O(W)
- Track selected items

**Features:**
- [ ] Basic knapsack implementation
- [ ] Item selection tracking
- [ ] Space-optimized version
- [ ] Multiple knapsack variants
- [ ] Performance benchmarking

---

### Issue #18: Add Edit Distance (Levenshtein) in C++
**Labels:** `algorithm`, `dynamic-programming`, `cpp`, `advanced`
**Priority:** Medium
**Difficulty:** Advanced

Implement edit distance algorithm in C++:
- Minimum operations to transform one string to another
- Operations: insert, delete, replace
- Time complexity: O(m × n)
- Space complexity: O(m × n), optimizable to O(min(m, n))

**Deliverables:**
- [ ] Basic edit distance calculation
- [ ] Operation tracking (which operations were used)
- [ ] Space-optimized version
- [ ] Different operation costs
- [ ] Template implementation for different string types

---

## Data Structures (4 issues)

### Issue #19: Add Linked List Implementation in C++
**Labels:** `data-structure`, `linked-list`, `cpp`, `intermediate`
**Priority:** High
**Difficulty:** Intermediate

Implement comprehensive linked list in C++:
- Singly linked list with all basic operations
- Template-based generic implementation
- Iterator support for STL compatibility
- Memory management and exception safety

**Operations:**
- [ ] Insert (front, back, at position)
- [ ] Delete (front, back, by value, at position)
- [ ] Search and access operations
- [ ] Size and empty checks
- [ ] Iterator implementation
- [ ] Copy constructor and assignment operator

---

### Issue #20: Add Stack Implementation in Python
**Labels:** `data-structure`, `stack`, `python`, `good first issue`
**Priority:** High
**Difficulty:** Beginner

Implement stack data structure in Python:
- LIFO (Last In, First Out) principle
- Array-based and linked list-based implementations
- All standard stack operations
- Exception handling for edge cases

**Features:**
- [ ] Array-based stack implementation
- [ ] Linked list-based stack implementation
- [ ] Standard operations (push, pop, peek, isEmpty)
- [ ] Size tracking and capacity management
- [ ] Custom exceptions for stack operations
- [ ] Performance comparison between implementations

---

### Issue #21: Add Binary Search Tree in Java
**Labels:** `data-structure`, `tree`, `java`, `advanced`
**Priority:** High
**Difficulty:** Advanced

Implement Binary Search Tree in Java:
- Self-balancing not required (basic BST)
- All standard BST operations
- Tree traversal methods
- Generic implementation with Comparable interface

**Operations:**
- [ ] Insert and delete operations
- [ ] Search operations
- [ ] Tree traversals (inorder, preorder, postorder, level-order)
- [ ] Find minimum and maximum
- [ ] Tree height and size calculations
- [ ] Validation methods

---

### Issue #22: Add Hash Table Implementation in Go
**Labels:** `data-structure`, `hash-table`, `go`, `advanced`
**Priority:** Medium
**Difficulty:** Advanced

Implement hash table data structure in Go:
- Separate chaining for collision resolution
- Dynamic resizing for load factor management
- Generic implementation using Go generics
- Custom hash functions

**Features:**
- [ ] Basic hash table operations (get, put, delete)
- [ ] Collision resolution with chaining
- [ ] Dynamic resizing based on load factor
- [ ] Custom hash function support
- [ ] Iterator for key-value pairs
- [ ] Performance analysis and benchmarking

---

## String Algorithms (2 issues)

### Issue #23: Add KMP String Matching in Python
**Labels:** `algorithm`, `string`, `python`, `advanced`
**Priority:** Medium
**Difficulty:** Advanced

Implement Knuth-Morris-Pratt string matching algorithm:
- Efficient pattern matching algorithm
- Time complexity: O(n + m)
- Build failure function (LPS array)
- Find all occurrences of pattern in text

**Requirements:**
- [ ] KMP algorithm implementation
- [ ] LPS (Longest Proper Prefix Suffix) array construction
- [ ] Find first occurrence
- [ ] Find all occurrences
- [ ] Detailed explanation of algorithm steps
- [ ] Comparison with naive string matching

---

### Issue #24: Add Rabin-Karp Algorithm in JavaScript
**Labels:** `algorithm`, `string`, `javascript`, `advanced`
**Priority:** Low
**Difficulty:** Advanced

Implement Rabin-Karp string matching algorithm:
- Rolling hash-based pattern matching
- Average time complexity: O(n + m)
- Worst case time complexity: O(nm)
- Handle hash collisions properly

**Deliverables:**
- [ ] Rabin-Karp algorithm implementation
- [ ] Rolling hash function
- [ ] Collision handling
- [ ] Multiple pattern matching variant
- [ ] Performance comparison with other string matching algorithms
- [ ] Modern JavaScript (ES6+) features

---

## Instructions for Creating Issues

1. **Copy each issue** to your GitHub repository
2. **Assign appropriate labels** as mentioned
3. **Set milestones** if you want to group related issues
4. **Add project boards** for better organization
5. **Encourage discussions** on implementation approaches
6. **Review and merge** pull requests promptly

## Issue Management Tips

- **Label issues clearly** for easy filtering
- **Use project boards** to track progress
- **Create issue templates** for consistency
- **Encourage newcomers** with "good first issue" labels
- **Provide mentorship** for complex algorithms
- **Celebrate contributions** to build community
