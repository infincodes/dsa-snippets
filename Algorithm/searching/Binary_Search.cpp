#include <bits/stdc++.h>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int l, int r, int target) {
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, r, target);
    else return binarySearchRecursive(arr, l, mid - 1, target);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    cout << "Iterative: " << binarySearchIterative(arr, target) << endl;
    cout << "Recursive: " << binarySearchRecursive(arr, 0, arr.size()-1, target) << endl;
    return 0;
}
