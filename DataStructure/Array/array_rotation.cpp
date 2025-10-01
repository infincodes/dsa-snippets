#include <bits/stdc++.h>
using namespace std;

// Function to reverse array elements from start to end
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Left rotate array by d positions using reversal algorithm
// Time Complexity: O(n), Space Complexity: O(1)
void leftRotate(int arr[], int n, int d) {
    d = d % n; // Handle cases where d > n
    
    // Reverse first d elements
    reverseArray(arr, 0, d - 1);
    
    // Reverse remaining elements
    reverseArray(arr, d, n - 1);
    
    // Reverse entire array
    reverseArray(arr, 0, n - 1);
}

// Right rotate array by d positions
// Time Complexity: O(n), Space Complexity: O(1)
void rightRotate(int arr[], int n, int d) {
    d = d % n; // Handle cases where d > n
    
    // Reverse entire array
    reverseArray(arr, 0, n - 1);
    
    // Reverse first d elements
    reverseArray(arr, 0, d - 1);
    
    // Reverse remaining elements
    reverseArray(arr, d, n - 1);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int d = 2;
    
    cout << "Original array: ";
    printArray(arr1, n);
    
    // Left rotation
    int leftArr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(leftArr, n, d);
    cout << "After left rotation by " << d << " positions: ";
    printArray(leftArr, n);
    
    // Right rotation
    int rightArr[] = {1, 2, 3, 4, 5, 6, 7};
    rightRotate(rightArr, n, d);
    cout << "After right rotation by " << d << " positions: ";
    printArray(rightArr, n);
    
    return 0;
}
