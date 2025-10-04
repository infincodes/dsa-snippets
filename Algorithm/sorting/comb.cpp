#include <iostream>
#include <vector>
using namespace std;

void combSort(vector<int>& arr) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    const float shrink = 1.3f;  // shrink factor

    while (gap > 1 || swapped) {
        // Update gap
        gap = int(gap / shrink);
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main() {
    vector<int> arr = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    combSort(arr);
    
    for (int x : arr) cout << x << " ";
    return 0;
}
