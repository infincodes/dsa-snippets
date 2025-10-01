#include <bits/stdc++.h>
using namespace std;

int fibonacciSearch(vector<int>& arr, int target) {
    int n = arr.size();
    int fib2 = 0;  // (m-2)'th Fibonacci number
    int fib1 = 1;  // (m-1)'th Fibonacci number
    int fib = fib1 + fib2; // m'th Fibonacci

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > target) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else return i;
    }

    if (fib1 && arr[offset + 1] == target) return offset + 1;
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;
    cout << "Fibonacci Search: " << fibonacciSearch(arr, target) << endl;
    return 0;
}
