#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int exponentialSearch(vector<int>& arr, int target) {
    if (arr[0] == target) return 0;
    int n = arr.size();
    int i = 1;
    while (i < n && arr[i] <= target) i *= 2;
    return binarySearch(arr, i/2, min(i, n-1), target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 11;
    cout << "Exponential Search: " << exponentialSearch(arr, target) << endl;
    return 0;
}
