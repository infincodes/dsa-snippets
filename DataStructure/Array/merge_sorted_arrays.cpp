#include <bits/stdc++.h>
using namespace std;

// Method 1: Merge into a new array
// Time Complexity: O(m + n), Space Complexity: O(m + n)
vector<int> mergeTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size();
    vector<int> merged(m + n);
    
    int i = 0, j = 0, k = 0;
    
    // Merge elements while both arrays have elements
    while (i < m && j < n) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    // Copy remaining elements from arr1
    while (i < m) {
        merged[k++] = arr1[i++];
    }
    
    // Copy remaining elements from arr2
    while (j < n) {
        merged[k++] = arr2[j++];
    }
    
    return merged;
}

// Method 2: Merge in-place (arr1 has extra space)
// Time Complexity: O(m + n), Space Complexity: O(1)
void mergeInPlace(vector<int>& arr1, int m, vector<int>& arr2, int n) {
    // Start from the end of both arrays
    int i = m - 1;      // Last element in arr1
    int j = n - 1;      // Last element in arr2
    int k = m + n - 1;  // Last position in arr1
    
    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }
    
    // Copy remaining elements from arr2
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }
    
    // No need to copy remaining from arr1 as they're already in place
}

// Method 3: Using STL merge function
// Time Complexity: O(m + n), Space Complexity: O(m + n)
vector<int> mergeUsingSTL(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged(arr1.size() + arr2.size());
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), merged.begin());
    return merged;
}

// Method 4: Merge with duplicates handling
// Time Complexity: O(m + n), Space Complexity: O(m + n)
vector<int> mergeWithoutDuplicates(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    int m = arr1.size(), n = arr2.size();
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            merged.push_back(arr2[j]);
            j++;
        } else {
            // Equal elements - add only once
            merged.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    // Add remaining elements
    while (i < m) {
        merged.push_back(arr1[i++]);
    }
    
    while (j < n) {
        merged.push_back(arr2[j++]);
    }
    
    return merged;
}

// Method 5: Merge K sorted arrays
// Time Complexity: O(N log k), where N is total elements and k is number of arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    // Min heap to store {value, array_index, element_index}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
    
    // Initialize heap with first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }
    
    vector<int> result;
    
    while (!minHeap.empty()) {
        auto [val, arrIdx, elemIdx] = minHeap.top();
        minHeap.pop();
        
        result.push_back(val);
        
        // Add next element from the same array
        if (elemIdx + 1 < arrays[arrIdx].size()) {
            minHeap.push({arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1});
        }
    }
    
    return result;
}

// Method 6: Intersection of two sorted arrays
// Time Complexity: O(m + n), Space Complexity: O(min(m, n))
vector<int> intersectionSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> intersection;
    int i = 0, j = 0;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    return intersection;
}

void printVector(const vector<int>& arr, const string& label = "Array") {
    cout << label << ": [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    cout << "Merge Sorted Arrays Implementations\n" << string(45, '=') << endl;
    
    // Test Case 1: Basic merge
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    
    cout << "\nTest Case 1: Basic Merge" << endl;
    printVector(arr1, "Array 1");
    printVector(arr2, "Array 2");
    
    vector<int> merged1 = mergeTwoSortedArrays(arr1, arr2);
    printVector(merged1, "Merged");
    
    vector<int> mergedSTL = mergeUsingSTL(arr1, arr2);
    printVector(mergedSTL, "Merged (STL)");
    
    // Test Case 2: In-place merge
    cout << "\nTest Case 2: In-place Merge" << endl;
    vector<int> arr3 = {1, 3, 5, 0, 0, 0}; // Extra space for arr4 elements
    vector<int> arr4 = {2, 4, 6};
    
    cout << "Array 1 (with extra space): [1, 3, 5, 0, 0, 0]" << endl;
    printVector(arr4, "Array 2");
    
    mergeInPlace(arr3, 3, arr4, 3);
    printVector(arr3, "After in-place merge");
    
    // Test Case 3: Arrays with different sizes
    cout << "\nTest Case 3: Different Sizes" << endl;
    vector<int> arr5 = {1, 5, 9, 10, 15, 20};
    vector<int> arr6 = {2, 3, 8, 13};
    
    printVector(arr5, "Array 1");
    printVector(arr6, "Array 2");
    
    vector<int> merged3 = mergeTwoSortedArrays(arr5, arr6);
    printVector(merged3, "Merged");
    
    // Test Case 4: Merge without duplicates
    cout << "\nTest Case 4: Merge Without Duplicates" << endl;
    vector<int> arr7 = {1, 3, 5, 7, 9};
    vector<int> arr8 = {3, 5, 7, 11, 13};
    
    printVector(arr7, "Array 1");
    printVector(arr8, "Array 2");
    
    vector<int> mergedNoDup = mergeWithoutDuplicates(arr7, arr8);
    printVector(mergedNoDup, "Merged (no duplicates)");
    
    // Test Case 5: Intersection
    cout << "\nTest Case 5: Intersection" << endl;
    vector<int> intersection = intersectionSortedArrays(arr7, arr8);
    printVector(intersection, "Intersection");
    
    // Test Case 6: Merge K sorted arrays
    cout << "\nTest Case 6: Merge K Sorted Arrays" << endl;
    vector<vector<int>> kArrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    
    cout << "Arrays to merge:" << endl;
    for (int i = 0; i < kArrays.size(); i++) {
        printVector(kArrays[i], "Array " + to_string(i + 1));
    }
    
    vector<int> mergedK = mergeKSortedArrays(kArrays);
    printVector(mergedK, "Merged K arrays");
    
    // Test Case 7: Edge cases
    cout << "\nTest Case 7: Edge Cases" << endl;
    vector<int> empty1 = {};
    vector<int> single = {42};
    
    vector<int> mergedEdge = mergeTwoSortedArrays(empty1, single);
    cout << "Empty + Single element: ";
    printVector(mergedEdge);
    
    return 0;
}
