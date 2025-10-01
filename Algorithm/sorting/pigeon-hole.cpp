#include <iostream>
#include <vector>
#include <algorithm>

void pigeonholeSort(std::vector<int>& arr) {
    // Find the minimum and maximum values in the array
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());

    int range = max - min + 1;  // Range of values in the array
    std::vector<int> holes(range, 0);

    // Count occurrences of each element
    for (int i = 0; i < arr.size(); ++i) {
        holes[arr[i] - min]++;
    }

    // Reconstruct the sorted array from pigeonholes
    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;
        }
    }
}

int main() {
    std::vector<int> arr = {8, 3, 2, 5, 7, 5, 1};
    pigeonholeSort(arr);
    for (int num : arr)
        std::cout << num << " ";
    return 0;
}
