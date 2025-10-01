#include <bits/stdc++.h>
using namespace std;

// Method 1: Using two pointers (in-place)
// Time Complexity: O(n), Space Complexity: O(1)
void reverseArrayTwoPointers(int arr[], int n) {
    int start = 0, end = n - 1;
    
    while (start < end) {
        // Swap elements at start and end positions
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Method 2: Using recursion
// Time Complexity: O(n), Space Complexity: O(n) due to recursion stack
void reverseArrayRecursive(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    
    // Swap current elements
    swap(arr[start], arr[end]);
    
    // Recursive call for remaining elements
    reverseArrayRecursive(arr, start + 1, end - 1);
}

// Method 3: Using STL reverse function
// Time Complexity: O(n), Space Complexity: O(1)
void reverseArraySTL(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}

// Method 4: Creating new reversed array
// Time Complexity: O(n), Space Complexity: O(n)
vector<int> reverseArrayNewArray(vector<int>& arr) {
    vector<int> reversed(arr.size());
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        reversed[i] = arr[n - 1 - i];
    }
    
    return reversed;
}

// Method 5: Using stack
// Time Complexity: O(n), Space Complexity: O(n)
void reverseArrayStack(int arr[], int n) {
    stack<int> st;
    
    // Push all elements to stack
    for (int i = 0; i < n; i++) {
        st.push(arr[i]);
    }
    
    // Pop elements and put back in array
    for (int i = 0; i < n; i++) {
        arr[i] = st.top();
        st.pop();
    }
}

// Method 6: Reverse a specific range in array
// Time Complexity: O(end - start + 1), Space Complexity: O(1)
void reverseArrayRange(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Utility function to print vector
void printVector(vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "Array Reversal Implementations\n" << string(40, '=') << endl;
    
    // Test Method 1: Two Pointers
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "\nMethod 1: Two Pointers" << endl;
    cout << "Original: ";
    printArray(arr1, n1);
    reverseArrayTwoPointers(arr1, n1);
    cout << "Reversed: ";
    printArray(arr1, n1);
    
    // Test Method 2: Recursion
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "\nMethod 2: Recursion" << endl;
    cout << "Original: ";
    printArray(arr2, n2);
    reverseArrayRecursive(arr2, 0, n2 - 1);
    cout << "Reversed: ";
    printArray(arr2, n2);
    
    // Test Method 3: STL reverse
    vector<int> arr3 = {1, 2, 3, 4, 5, 6};
    cout << "\nMethod 3: STL reverse" << endl;
    cout << "Original: ";
    printVector(arr3);
    reverseArraySTL(arr3);
    cout << "Reversed: ";
    printVector(arr3);
    
    // Test Method 4: New Array
    vector<int> arr4 = {1, 2, 3, 4, 5, 6};
    cout << "\nMethod 4: New Array" << endl;
    cout << "Original: ";
    printVector(arr4);
    vector<int> reversed4 = reverseArrayNewArray(arr4);
    cout << "Reversed: ";
    printVector(reversed4);
    
    // Test Method 5: Stack
    int arr5[] = {1, 2, 3, 4, 5, 6};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    cout << "\nMethod 5: Stack" << endl;
    cout << "Original: ";
    printArray(arr5, n5);
    reverseArrayStack(arr5, n5);
    cout << "Reversed: ";
    printArray(arr5, n5);
    
    // Test Method 6: Range Reversal
    int arr6[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    cout << "\nMethod 6: Range Reversal (indices 2 to 5)" << endl;
    cout << "Original: ";
    printArray(arr6, n6);
    reverseArrayRange(arr6, 2, 5);
    cout << "After range reversal: ";
    printArray(arr6, n6);
    
    return 0;
}
