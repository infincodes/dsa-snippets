#include <iostream>
#include <cmath>
using namespace std;

// ---------------- Heap Sort ----------------
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int low, int high) {
    for(int i = low+1; i <= high; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= low && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// ---------------- Quick Sort Partition ----------------
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// ---------------- Intro Sort Recursive ----------------
void introSortUtil(int arr[], int low, int high, int depthLimit) {
    int size = high - low + 1;

    if(size < 16) {
        insertionSort(arr, low, high);
        return;
    }

    if(depthLimit == 0) {
        heapSort(arr + low, size); // fallback to heap sort
        return;
    }

    int pivot = partition(arr, low, high);
    introSortUtil(arr, low, pivot-1, depthLimit-1);
    introSortUtil(arr, pivot+1, high, depthLimit-1);
}

void introSort(int arr[], int n) {
    int depthLimit = 2 * log(n);
    introSortUtil(arr, 0, n-1, depthLimit);
}

// ---------------- Main Function ----------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    introSort(arr, n);

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
