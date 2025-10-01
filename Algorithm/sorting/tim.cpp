#include <iostream>
#include <algorithm>
using namespace std;

const int RUN = 32; // Typical size for insertion sort in TimSort

// Insertion sort used in TimSort
void insertionSort(int arr[], int left, int right) {
    for(int i = left+1; i <= right; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= left && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Merge function used in TimSort
void merge(int arr[], int l, int m, int r) {
    int len1 = m-l+1, len2 = r-m;
    int left[len1], right[len2];

    for(int i=0; i<len1; i++) left[i] = arr[l+i];
    for(int i=0; i<len2; i++) right[i] = arr[m+1+i];

    int i=0, j=0, k=l;
    while(i < len1 && j < len2) {
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while(i < len1) arr[k++] = left[i++];
    while(j < len2) arr[k++] = right[j++];
}

// TimSort function
void timSort(int arr[], int n) {
    // Step 1: Sort small runs using insertion sort
    for(int i=0; i<n; i+=RUN) {
        insertionSort(arr, i, min(i+RUN-1, n-1));
    }

    // Step 2: Merge runs
    for(int size=RUN; size < n; size *= 2) {
        for(int left=0; left<n; left += 2*size) {
            int mid = min(left+size-1, n-1);
            int right = min(left + 2*size -1, n-1);
            if(mid < right) merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    timSort(arr, n);

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
