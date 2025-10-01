#include <iostream>
#include <algorithm>
using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i=1; i<n; i++)
        if(arr[i] > mx) mx = arr[i];
    return mx;
}

void countingSortForRadix(int arr[], int n, int exp) {
    int output[n], count[10] = {0};

    // Count occurrences of digits
    for(int i=0; i<n; i++)
        count[(arr[i]/exp)%10]++;

    // Cumulative count
    for(int i=1; i<10; i++)
        count[i] += count[i-1];

    // Build output array
    for(int i=n-1; i>=0; i--) {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    // Copy back to original array
    for(int i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for(int exp=1; m/exp>0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (non-negative integers): ";
    for(int i=0; i<n; i++) cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
