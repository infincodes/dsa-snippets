# Contributing to DSA Snippets 🤝

Thank you for your interest in contributing to DSA Snippets! This document provides guidelines and instructions for contributing to this project.

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Coding Standards](#coding-standards)
- [File Structure Guidelines](#file-structure-guidelines)
- [Testing Guidelines](#testing-guidelines)
- [Documentation Standards](#documentation-standards)
- [Pull Request Process](#pull-request-process)

## 🤝 Code of Conduct

This project adheres to a Code of Conduct. By participating, you are expected to uphold this code. Please read [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) for details.

## 🚀 Getting Started

1. **Fork the repository** on GitHub
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/yourusername/dsa-snippets.git
   cd dsa-snippets
   ```
3. **Create a new branch** for your feature:
   ```bash
   git checkout -b feature/algorithm-name
   ```

## 🛠️ How to Contribute

### 1. Adding New Algorithms

When adding a new algorithm:

1. **Check existing implementations** to avoid duplicates
2. **Add files directly** to the appropriate category folder:
   ```
   Algorithm/sorting/     - for sorting algorithms
   Algorithm/searching/   - for searching algorithms
   ```
3. **Follow the file naming convention**:
   - Use descriptive names like `bubble.cpp`, `Binary_Search.cpp`
   - Currently focused on C++ implementations (.cpp)
   - Future support planned for Python, Java, JavaScript

### 2. Adding Data Structures

When implementing data structures:

1. **Add files to appropriate directories** under `DataStructure/`:
   ```
   DataStructure/LinkedList/  - for linked list implementations
   DataStructure/Tree/        - for tree-related implementations
   ```
2. **Include all basic operations** (insert, delete, search, etc.)
3. **Add comprehensive examples** showing usage
4. **Follow existing naming patterns** like `LinkedListIntro.cpp`, `TreeIntro.cpp`

### 3. Adding Tests

1. **Create test files** alongside implementations or in a separate `tests/` directory
2. **Mirror the source structure**:
   ```
   tests/Algorithm/sorting/
   tests/DataStructure/LinkedList/
   ```
3. **Include edge cases** and performance tests
4. **Use appropriate testing frameworks** for each language

## 📝 Coding Standards

### General Guidelines

- **Write clean, readable code** with meaningful variable names
- **Add comprehensive comments** explaining the logic
- **Include time and space complexity** in comments
- **Handle edge cases** appropriately
- **Follow language-specific conventions**

### Language-Specific Standards

#### C++
```cpp
// File: bubble_sort.cpp
#include <iostream>
#include <vector>

/**
 * Bubble Sort Algorithm
 * Time Complexity: O(n²) average and worst case, O(n) best case
 * Space Complexity: O(1)
 * 
 * @param arr: vector to be sorted
 */
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping occurred, array is sorted
        if (!swapped) break;
    }
}
```

#### Python
```python
# File: bubble_sort.py
def bubble_sort(arr):
    """
    Bubble Sort Algorithm
    Time Complexity: O(n²) average and worst case, O(n) best case
    Space Complexity: O(1)
    
    Args:
        arr (list): List of comparable elements to be sorted
        
    Returns:
        list: Sorted list
    """
    n = len(arr)
    
    for i in range(n - 1):
        swapped = False
        
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        
        # If no swapping occurred, array is sorted
        if not swapped:
            break
    
    return arr
```

## 📁 File Structure Guidelines

### Current Repository Structure
```
dsa-snippets/
├── Algorithm/
│   ├── sorting/
│   │   ├── bubble.cpp
│   │   ├── heap.cpp
│   │   ├── insertion.cpp
│   │   ├── merge.cpp
│   │   ├── quick.cpp
│   │   └── selection.cpp
│   └── searching/
│       ├── Binary_Search.cpp
│       ├── Exponential_Search.cpp
│       ├── Interpolation_Search.cpp
│       ├── Jump_Search.cpp
│       └── Linear_Search.cpp
├── DataStructure/
│   ├── LinkedList/
│   │   ├── DoubleLinkedList.cpp
│   │   └── LinkedListIntro.cpp
│   └── Tree/
│       ├── PostfixInfixPrefix.cpp
│       └── TreeIntro.cpp
├── CONTRIBUTING.md
├── CODE_OF_CONDUCT.md
├── ISSUES.md
└── LICENSE
```

### Recommended File Structure for New Contributions
```
Algorithm/category/
├── algorithm_name.cpp (primary implementation)
├── algorithm_name.py (future multi-language support)
├── README.md (optional documentation)
└── test_algorithm_name.cpp (optional tests)
```

### Required Files

1. **Implementation files** in at least one language
2. **README.md** with:
   - Algorithm description
   - Time/space complexity
   - Usage examples
   - References

3. **Example files** showing input/output

### README Template for Algorithms

```markdown
# Algorithm Name

## Description
Brief description of what the algorithm does.

## Complexity
- **Time Complexity**: O(...)
- **Space Complexity**: O(...)

## Implementation
Available in:
- [C++](algorithm_name.cpp)
- [Python](algorithm_name.py)
- [Java](algorithm_name.java)

## Usage Example
```language
// Example code here
```

## Test Cases
- Input: [example input]
- Output: [expected output]

## References
- [Link to algorithm explanation]
```

## 🧪 Testing Guidelines

### Test File Structure
```python
# test_algorithm_name.py
import unittest
from algorithm_name import algorithm_function

class TestAlgorithmName(unittest.TestCase):
    
    def test_basic_case(self):
        """Test basic functionality"""
        input_data = [3, 1, 4, 1, 5]
        expected = [1, 1, 3, 4, 5]
        result = algorithm_function(input_data)
        self.assertEqual(result, expected)
    
    def test_edge_cases(self):
        """Test edge cases"""
        # Empty array
        self.assertEqual(algorithm_function([]), [])
        
        # Single element
        self.assertEqual(algorithm_function([1]), [1])
        
        # Already sorted
        self.assertEqual(algorithm_function([1, 2, 3]), [1, 2, 3])
    
    def test_performance(self):
        """Test with larger datasets"""
        large_input = list(range(1000, 0, -1))
        result = algorithm_function(large_input)
        self.assertEqual(result, list(range(1, 1001)))

if __name__ == '__main__':
    unittest.main()
```

## 📚 Documentation Standards

### Code Comments
- **Explain the "why"**, not just the "what"
- **Add complexity analysis** at the top of functions
- **Document parameters** and return values
- **Explain tricky parts** of the algorithm

### README Requirements
- **Clear algorithm description**
- **Complexity analysis**
- **Usage examples**
- **Links to educational resources**

## 🔄 Pull Request Process

1. **Update documentation** if needed
2. **Add tests** for new functionality
3. **Ensure all tests pass**
4. **Update README.md** if adding new categories
5. **Create descriptive commit messages**:
   ```
   Add: Implement merge sort in Python
   Fix: Correct binary search edge case
   Docs: Update complexity analysis for quick sort
   ```

6. **Submit pull request** with:
   - Clear title and description
   - Reference to related issues
   - Screenshots if applicable

### PR Template
```markdown
## Description
Brief description of changes made.

## Type of Change
- [ ] New algorithm implementation
- [ ] New data structure implementation
- [ ] Bug fix
- [ ] Documentation update
- [ ] Test addition

## Testing
- [ ] Added unit tests
- [ ] All tests pass
- [ ] Tested edge cases

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-review completed
- [ ] Documentation updated
- [ ] No breaking changes
```

## 🏷️ Issue Labels

When creating issues, use appropriate labels:

- `algorithm` - New algorithm needed
- `data-structure` - New data structure needed
- `bug` - Something isn't working
- `enhancement` - Improvement suggestion
- `documentation` - Docs need work
- `test` - Tests needed
- `good first issue` - Good for newcomers
- `help wanted` - Extra attention needed

## ❓ Questions?

If you have questions:
1. Check existing [Issues](https://github.com/yourusername/dsa-snippets/issues)
2. Create a new issue with the `question` label
3. Join our [Discussions](https://github.com/yourusername/dsa-snippets/discussions)

Thank you for contributing to DSA Snippets! 🎉
