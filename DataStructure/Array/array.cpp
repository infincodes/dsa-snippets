#include <bits/stdc++.h>
using namespace std;

// Function to traverse array
void traverse(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Insert element at given index
void insertAt(int arr[], int &n, int pos, int val) {
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

// Delete element from given index
void deleteAt(int arr[], int &n, int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    traverse(arr, n);

    cout << "Inserting 10 at position 2...\n";
    insertAt(arr, n, 2, 10);
    traverse(arr, n);

    cout << "Deleting element at position 3...\n";
    deleteAt(arr, n, 3);
    traverse(arr, n);

    return 0;
}
